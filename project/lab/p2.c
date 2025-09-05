#include <stdio.h>
#include <time.h>

int k = 0;

void dfs(int n, int a[10][10], int u, int t[10][10], int visited[10]) {
    int v;
    visited[u] = 1;

    for (v = 0; v < n; v++) {
        if (a[u][v] == 1 && visited[v] == 0) {
            t[k][0] = u;
            t[k][1] = v; 
            k++;
            dfs(n, a, v, t, visited);
        }
    }
}

int main() {
    int n, i, j, u;
    int a[10][10], visited[10], t[10][10];
    double clk;
    clock_t starttime, endtime;

    printf("\n\t\t\t DEPTH FIRST SEARCH \n");
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0/1 values):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &u);

    starttime = clock();

    dfs(n, a, u, t, visited);

    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nDFS traversal: Edges visited\n");
    for (i = 0; i < k; i++)
        printf("%d %d\n", t[i][0], t[i][1]);

    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}