 #include <stdio.h>
#include <conio.h>

#define MAX 100     // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix for the graph
int visited[MAX];   // Visited array
int stack[MAX];     // Stack to store the topological sort
int top = -1;       // Stack pointer
int n;              // Number of vertices

// Function to push an element onto the stack
void push(int v) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = v;
    }
}

// Function to pop an element from the stack (for demonstration)
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to perform DFS and push vertices to the stack in topological order
void dfs(int v) {
    visited[v] = 1; 
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i]==0) {
            dfs(i);
        }
    }
    push(v);
}

// Function to perform topological sort
void topologicalSort() {
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Call the DFS for each unvisited vertex
    for (int i = 0; i < n; i++) {
        if (visited[i]==0) {
            dfs(i);
        }
    }

    // Print the vertices in topological order by popping from the stack
    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

// Function to take input from the user and form the adjacency matrix
void inputGraph() {
    int edges, src, dest;
    
    printf("Enter the number of node: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
 
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1; // Directed edge from src to dest
    }
}

void main() {
    int i,j;
    inputGraph();
    printf("adjecent matrix:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    topologicalSort();
    getch();
}
