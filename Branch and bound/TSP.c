#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int minCost = INT_MAX;
int visitedAll = (1 << N) - 1;

int tsp(int graph[N][N], int mask, int pos, int cost) {
    if (mask == visitedAll) {
        return graph[pos][0];
    }

    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = cost + graph[pos][city];
            if (newCost < minCost) {
                int newMask = mask | (1 << city);
                minCost = tsp(graph, newMask, city, newCost);
            }
        }
    }

    return minCost;
}

int main() {
    int graph[N][N];

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int cost = tsp(graph, 1, 0, 0);

    printf("Minimum cost: %d\n", cost);

    return 0;
}

