#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct Process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
bool compare(Process a,Process b){
    return a.at < b.at;
}
int main(){
    int n;
    cout<<"Enter the number of processes:"<<endl;
    cin>>n;
    Process p[n];
    for(int i=0;i<n;i++){
        cout<<"Process:"<<i+1<<endl;
        cout<<"arrival time:";
        cin>>p[i].at;
        cout<<"burst time:";
        cin>>p[i].bt;
    }
    sort(p,p+n,compare);
    int currentTime = 0,totalWt = 0,totalTat = 0;
    for(int i=0;i<n;i++){
        if(currentTime < p[i].at)
            currentTime = p[i].at;
        p[i].ct = currentTime+p[i].bt;
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i].tat-p[i].bt;
        currentTime = p[i].ct;
        totalTat+=p[i].tat;
        totalWt+=p[i].wt;
    }
    cout<<" P_ID\t AT\tBT\tCT\tWT\tTAT\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].wt<<"\t"<<p[i].tat<<"\n";
    }
    cout<<"average tat:"<<totalTat/n<<endl;
    cout<<"average wt:"<<totalWt/n<<endl;
    return 0;
}