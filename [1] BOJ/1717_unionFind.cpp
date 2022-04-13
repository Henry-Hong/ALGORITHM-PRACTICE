#include <stdio.h>

int parent[1000001];

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void unionSet(int a, int b) {

    a = find(a);
    b = find(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int findSet(int a, int b) {

    a = find(a);
    b = find(b);

    if (a == b) return 1;
    else return 0;
}

int main() {

    //1. parent 배열
    

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int op, a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &op, &a, &b);
        if (op == 1) {
            if (findSet(a, b) == 1) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        else {
            unionSet(a, b);
        }
    }

    return 0;
}