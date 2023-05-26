#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Function to create a node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from destination to source
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function for Breadth-First Search (BFS)
void bfs(struct Graph* graph, int startVertex) {
    struct Node* queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = graph->adjLists[startVertex];

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        struct Node* currentVertex = queue[front++];
        printf("%d ", currentVertex->data);

        struct Node* temp = currentVertex;
        while (temp) {
            int adjVertex = temp->data;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = graph->adjLists[adjVertex];
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

// Function for Depth-First Search (DFS) recursive helper function
void dfsRecursive(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (graph->visited[adjVertex] == 0) {
            dfsRecursive(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Function for Depth-First Search (DFS)
void dfs(struct Graph* graph, int startVertex) {
    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfsRecursive(graph, startVertex);
    printf("\n");
}

// Driver program to test BFS and DFS functions
int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    bfs(graph, 0);
    dfs(graph, 0);

    return 0;
}
