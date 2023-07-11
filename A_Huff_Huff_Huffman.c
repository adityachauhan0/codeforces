#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

struct MinHNode {
    char item;
    unsigned freq;
    struct MinHNode* left, * right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHNode** array;
};

struct MinHNode* newNode(char item, unsigned freq) {
    struct MinHNode* temp = (struct MinHNode*)malloc(sizeof(struct MinHNode));
    temp->left = temp->right = NULL;
    temp->item = item;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinH(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHNode**)malloc(minHeap->capacity * sizeof(struct MinHNode*));
    return minHeap;
}

void swapMinHNode(struct MinHNode** a, struct MinHNode** b) {
    struct MinHNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int checkSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHNode* extractMin(struct MinHeap* minHeap) {
    struct MinHNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct MinHNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char item[], int freq[], int size) {
    struct MinHeap* minHeap = createMinH(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(item[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHNode* buildHuffmanTree(char item[], int freq[], int size) {
    struct MinHNode* left, * right, * top;
    struct MinHeap* minHeap = createAndBuildMinHeap(item, freq, size);

    while (!checkSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void decodeHuffmanCode(struct MinHNode* root, char* code) {
    struct MinHNode* curr = root;

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '0') {
            curr = curr->left;
        }
        else if (code[i] == '1') {
            curr = curr->right;
        }

        if (isLeaf(curr)) {
            printf("%c", curr->item);
            curr = root;
        }
    }
}

int main() {
    char s[21];
    int q;
    scanf("%s", s);
    scanf("%d", &q);

    char item[q];
    int freq[q];
    char code[q][MAX_TREE_HT];

    for (int i = 0; i < q; i++) {
        scanf("%s", code[i]);
    }

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int found = 0;

        for (int j = 0; j < q; j++) {
            if (s[i] == code[j][0]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            item[q] = s[i];
            freq[q] = 0;
            q++;
        }
    }

    struct MinHNode* root = buildHuffmanTree(item, freq, q);

    for (int i = 0; i < q; i++) {
        decodeHuffmanCode(root, code[i]);
        printf("\n");
    }

    return 0;
}
