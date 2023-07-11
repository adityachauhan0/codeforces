// Priority Queue implementation in C

#include <stdio.h>
#include <math.h>

int size = 0;

typedef struct {
  int paintings;
  int boredom;
} ArtGallery;

void swap(ArtGallery* a, ArtGallery* b) {
  ArtGallery temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(ArtGallery array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l].paintings > array[largest].paintings)
      largest = l;
    if (r < size && array[r].paintings > array[largest].paintings)
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

// Function to insert an element into the tree
void insert(ArtGallery array[], ArtGallery newGallery) {
  if (size == 0) {
    array[0] = newGallery;
    size += 1;
  } else {
    array[size] = newGallery;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}

// Function to delete an element from the tree
void deleteRoot(ArtGallery array[], ArtGallery gallery) {
  int i;
  for (i = 0; i < size; i++) {
    if (gallery.paintings == array[i].paintings)
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}

// Print the array
void printArray(ArtGallery array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i].paintings);
  printf("\n");
}

// Function to solve the problem for each test case
void solveTestCase() {
  int n, k;
  scanf("%d %d", &n, &k);

  ArtGallery array[n];
  size = 0;

  for (int i = 0; i < n; i++) {
    int paintings;
    scanf("%d", &paintings);
    insert(array, (ArtGallery) { paintings, 0 });
  }

  for (int i = 0; i < n; i++) {
    int boredom;
    scanf("%d", &boredom);
    ArtGallery ag = array[0];
    deleteRoot(array, ag);

    int paintingsToSee = ceil(ag.paintings / 2.0);

    if (paintingsToSee > 0 && k > 0) {
      insert(array, (ArtGallery) { ag.paintings - paintingsToSee, boredom });
      k--;
    } else {
      insert(array, ag);
      break;
    }
  }

  int remainingPaintings = 0;
  int totalBoredom = 0;

  for (int i = 0; i < size; i++) {
    remainingPaintings += array[i].paintings;
    totalBoredom += array[i].boredom * array[i].paintings;
  }

  printf("%d %d\n", remainingPaintings, totalBoredom);
}

// Driver code
int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    solveTestCase();
  }

  return 0;
}
