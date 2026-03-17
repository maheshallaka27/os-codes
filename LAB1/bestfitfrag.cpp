#include <iostream>
using namespace std;

int main()
{
    int blocks[50], process[50];
    int m,n;

    cout<<"Enter number of blocks: ";
    cin>>m;

    cout<<"Enter block sizes:\n";
    for(int i=0;i<m;i++)
        cin>>blocks[i];

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"Enter process sizes:\n";
    for(int i=0;i<n;i++)
        cin>>process[i];

    int allocation[50];
    for(int i=0;i<n;i++)
        allocation[i] = -1;

    int internal = 0;

    for(int i=0;i<n;i++)
    {
        int best = -1;

        for(int j=0;j<m;j++)
        {
            if(blocks[j] >= process[i])
            {
                if(best == -1 || blocks[j] < blocks[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            internal += blocks[best] - process[i];
            blocks[best] = 0;
        }
    }

    int external = 0;
    for(int i=0;i<m;i++)
        external += blocks[i];

    cout<<"\nProcess\tSize\tBlock\n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<process[i]<<"\t";
        if(allocation[i] != -1)
            cout<<allocation[i]+1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

    cout<<"\nInternal Fragmentation = "<<internal;
    cout<<"\nExternal Fragmentation = "<<external;

    return 0;
}