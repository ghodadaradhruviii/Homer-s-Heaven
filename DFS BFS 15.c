#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacency_list;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacency_list = (struct Node*)malloc(vertices * sizeof(struct Node));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* adj_list = graph->adjacency_list[vertex];
    while (adj_list) {
        int adj_vertex = adj_list->data;
        if (!visited[adj_vertex]) {
            DFS(graph, adj_vertex, visited);
        }
        adj_list = adj_list->next;
    }
}

void BFS(struct Graph* graph, int start) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    int front = -1, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front < rear) {
        int current_vertex = queue[++front];
        printf("%d ", current_vertex);

        struct Node* adj_list = graph->adjacency_list[current_vertex];
        while (adj_list) {
            int adj_vertex = adj_list->data;
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = true;
                queue[++rear] = adj_vertex;
            }
            adj_list = adj_list->next;
        }
    }

    free(visited);
    free(queue);
}

int main() {
    int vertices = 4;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("DFS Traversal: ");
    bool* visited = (bool*)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; ++i) {
        visited[i] = false;
    }
    DFS(graph, 2, visited);

    printf("\nBFS Traversal: ");
    BFS(graph, 2);

    free(visited);
    return 0;
}
