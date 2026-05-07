#include <iostream>
using namespace std;

int main() {
    int p, r;

    cout << "Enter number of processes: ";
    cin >> p;

    cout << "Enter number of resources: ";
    cin >> r;

    int total = p + r;

    // Adjacency Matrix
    int graph[20][20] = {0};

    int alloc, req;

    // Allocation edges
    cout << "\nEnter number of allocated resources: ";
    cin >> alloc;

    cout << "Enter Resource -> Process edges\n";
    cout << "Example: R0 P1\n";

    for (int i = 0; i < alloc; i++) {
        string res, pro;
        cin >> res >> pro;

        int rIndex = (res[1] - '0') + p;
        int pIndex = pro[1] - '0';

        graph[rIndex][pIndex] = 1;
    }

    // Request edges
    cout << "\nEnter number of request edges: ";
    cin >> req;

    cout << "Enter Process -> Resource edges\n";
    cout << "Example: P1 R0\n";

    for (int i = 0; i < req; i++) {
        string pro, res;
        cin >> pro >> res;

        int pIndex = pro[1] - '0';
        int rIndex = (res[1] - '0') + p;

        graph[pIndex][rIndex] = 1;
    }

    // Display Matrix
    cout << "\nResource Allocation Graph (Adjacency Matrix)\n";

    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}