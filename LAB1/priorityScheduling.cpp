#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int priority;
    int remaining_bt;
    int ct, tat, wt;
};

int main() {

    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        cout<<"Enter AT BT Priority for P"<<i+1<<": ";
        cin>>p[i].at>>p[i].bt>>p[i].priority;
        p[i].remaining_bt=p[i].bt;
    }

    int time=0;
    int completed=0;
    float avgWT=0,avgTAT=0;

    while(completed<n){

        int idx=-1;
        int highestPriority=INT_MAX;

        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].remaining_bt>0){

                if(p[i].priority<highestPriority){
                    highestPriority=p[i].priority;
                    idx=i;
                }

                else if(p[i].priority==highestPriority){
                    if(p[i].remaining_bt < p[idx].remaining_bt){
                        idx=i;
                    }
                }
            }
        }

        if(idx!=-1){

            p[idx].remaining_bt--;
            time++;

            if(p[idx].remaining_bt==0){

                p[idx].ct=time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;

                avgWT+=p[idx].wt;
                avgTAT+=p[idx].tat;

                completed++;
            }

        } else {
            time++;
        }
    }

    cout<<"\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++){
        cout<<p[i].pid<<"\t"
            <<p[i].at<<"\t"
            <<p[i].bt<<"\t"
            <<p[i].priority<<"\t"
            <<p[i].ct<<"\t"
            <<p[i].tat<<"\t"
            <<p[i].wt<<"\n";
    }

    cout<<"\nAverage Waiting Time: "<<avgWT/n;
    cout<<"\nAverage Turnaround Time: "<<avgTAT/n;

    return 0;
}