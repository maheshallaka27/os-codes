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
        int worstIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (holes[j] >= processes[i])
            {
                if (worstIndex == -1 || holes[j] > holes[worstIndex])
                {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1)
        {
            cout << "Process " << i+1
                 << " (Size " << processes[i]
                 << ") allocated to Hole "
                 << worstIndex+1 << endl;

            holes[worstIndex] -= processes[i]; 
        }
        else
        {
            cout << "Process " << i+1
                 << " (Size " << processes[i]
                 << ") Not Allocated" << endl;
        }
    }
    cout << "\nRemaining Hole Sizes:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Hole " << i+1 << ": " << holes[i] << endl;
    }

    return 0;
}