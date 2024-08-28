/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 49

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    Node **adjList;
    int *visited;
    int numVertices;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node **)malloc(numVertices * sizeof(Node *));
    graph->visited = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int start, int end) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = graph->adjList[start];
    graph->adjList[start] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = start;
    newNode->next = graph->adjList[end];
    graph->adjList[end] = newNode;
}

int DFS(Graph *graph, int vertex) {
    graph->visited[vertex] = 1;
    int count = 0;
    Node *adjList = graph->adjList[vertex];
    Node *temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            count += 1 + DFS(graph, connectedVertex);
        }

        temp = temp->next;
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int startVertex, numVertices, numEdges;
        scanf("%d", &startVertex);
        scanf("%d %d", &numVertices, &numEdges);

        Graph *graph = createGraph(numVertices);

        for (int i = 0; i < numEdges; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            addEdge(graph, start, end);
        }

        int totalSteps = 2 * DFS(graph, startVertex);
        printf("%d\n", totalSteps);

        // Free the memory
        for (int i = 0; i < numVertices; i++) {
            Node *temp = graph->adjList[i];
            while (temp) {
                Node *toFree = temp;
                temp = temp->next;
                free(toFree);
            }
        }
        free(graph->adjList);
        free(graph->visited);
        free(graph);
    }

    return 0;
}
