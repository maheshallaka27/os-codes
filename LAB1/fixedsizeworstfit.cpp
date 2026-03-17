#include <iostream>
using namespace std;

int main()
{   
    int partitions[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int n = sizeof(processes) / sizeof(processes[0]);
    int m = sizeof(partitions) / sizeof(partitions[0]);
    bool allocated[m];
    for (int i = 0; i < m; i++)
    {
        allocated[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        int worstIndex = -1;

        for (int j = 0; j < m; j++)
        {
            if (!allocated[j] && partitions[j] >= processes[i])
            {
                if (worstIndex == -1 || partitions[j] > partitions[worstIndex])
                {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1)
        {
            allocated[worstIndex] = true;

            cout << "Process " << i+1
                 << " (Size " << processes[i] << ") allocated to Partition "
                 << worstIndex+1 << " (Size " << partitions[worstIndex] << ")"
                 << endl;
        }
        else{
            cout << "Process " << i+1
                 << " (Size " << processes[i] << ") Not Allocated"
                 << endl;
        }
    }
    return 0;
}