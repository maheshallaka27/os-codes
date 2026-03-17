#include <iostream>
using namespace std;

int main()
{
    int holes[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};

    int m = sizeof(holes) / sizeof(holes[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    for (int i = 0; i < n; i++)
    {
        bool allocated = false;

        for (int j = 0; j < m; j++)
        {
            if (holes[j] >= processes[i])
            {
                cout << "Process " << i+1
                     << " (Size " << processes[i] << ") allocated to Hole "
                     << j+1 << endl;

                holes[j] -= processes[i];  // Reduce hole size

                allocated = true;
                break;
            }
        }

        if (!allocated)
        {
            cout << "Process " << i+1
                 << " (Size " << processes[i] << ") Not Allocated"
                 << endl;
        }
    }

    // Print remaining holes
    cout << "\nRemaining Hole Sizes:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Hole " << i+1 << ": " << holes[i] << endl;
    }

    return 0;
}
