#include <iostream>
using namespace std;

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int **graph, int V)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int **graph, int V)
{
    int *parent = new int[V];   // Array to store constructed MST
    int *key = new int[V];      // Key values used to pick minimum weight edge in cut
    bool *mstSet = new bool[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph, V);

    // Free allocated memory
    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

// Driver code
int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Dynamically allocate memory for the adjacency matrix
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
    }

    cout << "Enter the adjacency matrix (enter 0 if there is no edge):\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Print the solution
    primMST(graph, V);

    // Free allocated memory for graph
    for (int i = 0; i < V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
