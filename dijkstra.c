 #include<stdio.h>
#include<conio.h>
#define INF 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int visible[MAX], count, miniDist, nextnode, i, j;

    // Step 1: Create the cost matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(G[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = G[i][j];
        }
    }

    // Step 2: Initialize distance, predecessor, and visible arrays
    for(i = 0; i < n; i++) {
        dist[i] = cost[startnode][i];
        pred[i] = startnode;
        visible[i] = 0;
    }
    
    dist[startnode] = 0;
    visible[startnode] = 1;
    count = 1;

    // Step 3: Main loop to find the shortest path for all nodes
    while(count < n - 1) {
        miniDist = INF;

        // Find the next node with the smallest distance
        for(i = 0; i < n; i++) {
            if(dist[i] < miniDist && !visible[i]) {
                miniDist = dist[i];
                nextnode = i;
            }
        }

        // Mark the next node as visited
        visible[nextnode] = 1;

        // Update the distances of adjacent nodes
        for(i = 0; i < n; i++) {
            if(!visible[i]) {
                if(miniDist + cost[nextnode][i] < dist[i]) {
                    dist[i] = miniDist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    // Step 4: Print the result
    for(i = 0; i < n; i++) {
        if(i != startnode) {
            printf("\nDistance from node %d to node %d: %d", startnode, i, dist[i]);
            printf("\nPath: %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while(j != startnode);
            printf("\n");
        }
    }
}

void main() {
    int G[MAX][MAX], i, j, n, u;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("\nEnter the starting node: ");
    scanf("%d", &u);

    dijkstra(G, n, u);
    getch();
}
