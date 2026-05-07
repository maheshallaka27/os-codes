#include <iostream>
#include <vector>
#include <map>
using namespace std;

class ResourceAllocationGraph {
    int processes, resources;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;
    map<string, int> vertexIndex;

public:
    ResourceAllocationGraph(int p, int r) {
        processes = p;
        resources = r;

        int totalVertices = p + r;

        adjMatrix.resize(totalVertices, vector<int>(totalVertices, 0));
        adjList.resize(totalVertices);

        // Assign index to processes
        for (int i = 0; i < p; i++) {
            vertexIndex["P" + to_string(i)] = i;
        }

        // Assign index to resources
        for (int i = 0; i < r; i++) {
            vertexIndex["R" + to_string(i)] = p + i;
        }
    }

    // Add edge in graph
    void addEdge(string from, string to) {
        int u = vertexIndex[from];
        int v = vertexIndex[to];

        adjMatrix[u][v] = 1;
        adjList[u].push_back(v);
    }

    // Display adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < adjMatrix[i].size(); j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Display adjacency list
    void displayList() {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < adjList.size(); i++) {

            // Print process/resource name
            if (i < processes)
                cout << "P" << i << " -> ";
            else
                cout << "R" << i - processes << " -> ";

            for (int v : adjList[i]) {

                if (v < processes)
                    cout << "P" << v << " ";
                else
                    cout << "R" << v - processes << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    int p, r;

    cout << "Enter number of processes: ";
    cin >> p;

    cout << "Enter number of resources: ";
    cin >> r;

    ResourceAllocationGraph rag(p, r);

    int allocEdges, requestEdges;

    // Allocation edges (Resource -> Process)
    cout << "\nEnter number of allocation edges: ";
    cin >> allocEdges;

    cout << "Enter allocation edges (Resource Process):\n";

    for (int i = 0; i < allocEdges; i++) {
        string resource, process;
        cin >> resource >> process;

        rag.addEdge(resource, process);
    }

    // Request edges (Process -> Resource)
    cout << "\nEnter number of request edges: ";
    cin >> requestEdges;

    cout << "Enter request edges (Process Resource):\n";

    for (int i = 0; i < requestEdges; i++) {
        string process, resource;
        cin >> process >> resource;

        rag.addEdge(process, resource);
    }

    rag.displayMatrix();
    rag.displayList();

    return 0;
}