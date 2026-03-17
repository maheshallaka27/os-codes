#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, rem_bt;
    int ct, tat, wt;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    cout << "Enter Arrival Time and Burst Time:\n";
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].rem_bt = p[i].bt;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    int time = 0, completed = 0;
    vector<bool> inQ(n, false);

    vector<pair<int,int>> gantt; 

    for(int i = 0; i < n; i++) {
        if(p[i].at == 0) {
            q.push(i);
            inQ[i] = true;
        }
    }

    cout << "\nCompressed Gantt:\n";
    cout << time << " ";   

    int last = -1;

    while(completed < n) {

        if(q.empty()) {
            time++;
            for(int i = 0; i < n; i++) {
                if(p[i].at <= time && !inQ[i] && p[i].rem_bt > 0) {
                    q.push(i);
                    inQ[i] = true;
                }
            }
            continue;
        }

        int i = q.front();
        q.pop();

        if(i != last) {
            cout << "P" << p[i].pid << " " << time << " ";
            last = i;
        }

        int exec = min(tq, p[i].rem_bt);
        time += exec;
        p[i].rem_bt -= exec;

        for(int j = 0; j < n; j++) {
            if(p[j].at <= time && !inQ[j] && p[j].rem_bt > 0) {
                q.push(j);
                inQ[j] = true;
            }
        }

        if(p[i].rem_bt > 0) {
            q.push(i);
        } else {
            p[i].ct = time;
            completed++;
        }
    }

    cout << time << "\n"; 

    double sumTAT = 0, sumWT = 0;

    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sumTAT += p[i].tat;
        sumWT += p[i].wt;
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(auto &x : p) {
        cout << x.pid << "\t"
             << x.at << "\t"
             << x.bt << "\t"
             << x.ct << "\t"
             << x.tat << "\t"
             << x.wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage TAT = " << sumTAT / n << endl;
    cout << "Average WT  = " << sumWT / n << endl;

    return 0;
}
