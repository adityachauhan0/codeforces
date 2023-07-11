#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->data = malloc(sizeof(int));
    v->size = 0;
    v->capacity = 1;
}

void vector_push_back(Vector *v, int x) {
    if (v->size == v->capacity) {
        v->capacity <<= 1;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = x;
}

int V, E;
Vector adj[MAXN];
bool vis[MAXN];
int scc_cnt = 0, scc_id[MAXN];
int in_deg[MAXN];

void dfs(int u) {
    vis[u] = true;
    scc_id[u] = scc_cnt;
    for (int i = 0; i < adj[u].size; ++i) {
        int v = adj[u].data[i];
        if (!vis[v]) dfs(v);
    }
}

int main() {
    scanf("%d%d", &V, &E);
    for (int i = 1; i <= V; ++i) vector_init(&adj[i]);
    for (int i = 1; i <= E; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        vector_push_back(&adj[u], v);
        vector_push_back(&adj[v], u);
    }
    for (int i = 1; i <= V; ++i) {
        if (!vis[i]) {
            ++scc_cnt;
            dfs(i);
        }
    }
    for (int u = 1; u <= V; ++u) {
        for (int i = 0; i < adj[u].size; ++i) {
            int v = adj[u].data[i];
            if (scc_id[u] != scc_id[v]) ++in_deg[scc_id[v]];
        }
    }
    int cnt_zero_in_deg = 0;
    for (int i = 1; i <= scc_cnt; ++i) {
        if (!in_deg[i]) ++cnt_zero_in_deg;
    }
    puts(cnt_zero_in_deg == 1 ? "YES" : "NO");
}
