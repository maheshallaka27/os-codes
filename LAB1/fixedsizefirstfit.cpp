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
        bool isAllocated = false;
        for(int j= 1;j<m;j++){
            if(!allocated[j]&&partitions[j]>processes[i]){
                allocated[j] = true;
                cout << "Process " << i + 1
                     << " (Size " << processes[i] << ") allocated to Partition "
                     << j + 1 << " (Size " << partitions[j] << ")" << endl;

                isAllocated = true;
                break;
            }
        }
        if(!isAllocated){
            cout << "Process " << i + 1
                 << " (Size " << processes[i] << ") Not Allocated" << endl;
        }
    }
    return 0;
}