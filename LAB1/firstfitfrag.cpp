#include <iostream>
using namespace std;

int main()
{
    int blocks[50], process[50];
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;

    cout << "Enter block sizes:\n";
    for(int i=0;i<m;i++)
        cin >> blocks[i];

    cout << "Enter number of processes/files: ";
    cin >> n;

    cout << "Enter process sizes:\n";
    for(int i=0;i<n;i++)
        cin >> process[i];

    int internal = 0;
    int external = 0;
    int allocation[50];

    for(int i=0;i<n;i++)
        allocation[i] = -1;

    // FIRST FIT Allocation
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(blocks[j] >= process[i])
            {
                allocation[i] = j;

                internal += blocks[j] - process[i];

                blocks[j] = 0;
                break;
            }
        }
    }

    // External fragmentation
    for(int i=0;i<m;i++)
    {
        if(blocks[i] != 0)
            external += blocks[i];
    }

    cout << "\nProcess No\tProcess Size\tBlock No\n";

    for(int i=0;i<n;i++)
    {
        cout << i+1 << "\t\t" << process[i] << "\t\t";

        if(allocation[i] != -1)
            cout << allocation[i]+1;
        else
            cout << "Not Allocated";

        cout << endl;
    }

    cout << "\nInternal Fragmentation: " << internal << endl;
    cout << "External Fragmentation: " << external << endl;

    return 0;
}