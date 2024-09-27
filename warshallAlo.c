 #include <stdio.h>
 #include<conio.h>
#define MAX 100  // Maximum number of vertices

int adj[MAX][MAX];
int ans[MAX][MAX] ; // Adjacency matrix for the graph
int n;              // Number of vertices
 
void inputGraph() {
    int edges, src, dest;

    printf("Enter the number of nodes: ");
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
        adj[src][dest] = 1;  
    }
}

// Function to print the adjacency matrix
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}
void swaped()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ans[i][j]=adj[i][j];
        }
    }
}

 
void warshall() {
    int i, j, k;
    // node
    for (k = 0; k < n; k++) {
        swaped();
        // i
        for (i = 0; i < n; i++) {
            // j
             if(i==k)
                {
                    i++;
                }
            for (j = 0; j < n; j++) {
                
                if(j==k)
                {
                    j++;
                }
              
                if (ans[i][k]==1 && ans[k][j]==1 ||ans[i][j]==1) {
                    adj[i][j] = 1;
                }
               else 
                {
                    adj[i][j]=0;
                }
            }
        }
    }
}

int main() {
    inputGraph();
    
    printf("Adjacency Matrix:\n");
    print();

   
    warshall();

    printf("\n Shortest Path Matrix:\n");
    print();
    getch();
}
