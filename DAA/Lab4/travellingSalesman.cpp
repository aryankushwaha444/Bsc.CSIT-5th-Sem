// CPP program to implement traveling salesman
// problem using naive approach.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define V 4

// Implementation of traveling Salesman Problem
int travllingSalesmanProblem(vector<vector<int> >& graph, int s) {
    // Store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++) {
        if (i != s) {
            vertex.push_back(i);
        }
    }

    // Store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
        // Store current path weight (cost)
        int current_pathweight = 0;

        // Compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // Update minimum
        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// Driver program to test above function
int main() {
    vector<vector<int> > graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int s = 0;  // You can change the source vertex if needed
    cout << "The minimum path weight is: " << travllingSalesmanProblem(graph, s) << endl;

    return 0;
}
