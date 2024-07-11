#include <iostream>
#include <limits.h>

// Function prototypes
int minDistance(int dist[], bool sptSet[], int V);
void dijkstra(int** graph, int src, int V);
void printSolution(int dist[], int V);

int main() {
    int V;

    // Take input for the number of vertices
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    // Allocate memory for the graph
    int** graph = new int*[V];
    for (int i = 0; i < V; ++i) {
        graph[i] = new int[V];
    }

    // Take input for the graph
    std::cout << "Enter the adjacency matrix for the graph (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cin >> graph[i][j];
        }
    }

    // Choose the source vertex
    int src;
    std::cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    std::cin >> src;

    // Run Dijkstra's algorithm
    dijkstra(graph, src, V);

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int V) {
    std::cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << "\t\t" << dist[i] << "\n";
    }
}

void dijkstra(int** graph, int src, int V) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}
