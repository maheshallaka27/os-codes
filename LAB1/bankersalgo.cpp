#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    int allocation[10][10], max[10][10], need[10][10];
    int available[10];

    // Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    // Max Matrix
    cout << "\nEnter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    // Available Resources
    cout << "\nEnter Available Resources:\n";
    for (int j = 0; j < m; j++) {
        cin >> available[j];
    }

    // Need Matrix = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int finish[10] = {0};
    int safeSeq[10];
    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {

                bool possible = true;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {

                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            break;
        }
    }

    // Check Safe State
    if (count == n) {
        cout << "\nSystem is in SAFE STATE\n";
        cout << "Safe Sequence: ";

        for (int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i];

            if (i != n - 1)
                cout << " -> ";
        }
    }
    else {
        cout << "\nSystem is NOT in safe state (Deadlock may occur)\n";
    }

    return 0;
}