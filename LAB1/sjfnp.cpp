    #include <bits/stdc++.h>
    using namespace std;
    struct Process {
        int p_id;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
    };
    bool compare(Process a, Process b) {
        if (a.at == b.at)
            return a.bt < b.bt;
        return a.at < b.at;
    }
    int main() {
        int n;
        cout << "Enter number of processes: ";
        cin >> n;

        Process p[n];

        for (int i = 0; i < n; i++) {
            p[i].p_id = i + 1;
            cout << "Enter Arrival Time & Burst Time for P" << i + 1 << ": ";
            cin >> p[i].at >> p[i].bt;
        }

        sort(p, p + n, compare);

        int time = 0;
        float avgWT = 0, avgTAT = 0;
        vector<bool> completed(n, false);
        int completedCount = 0;

        while (completedCount < n) {
            int idx = -1;
            int minBT = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (p[i].at <= time && !completed[i] && p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
            }

            if (idx != -1) {
                time += p[idx].bt;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                avgWT += p[idx].wt;
                avgTAT += p[idx].tat;
                completed[idx] = true;
                completedCount++;
            } else {
                time++;
            }
        }

        cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
        for (int i = 0; i < n; i++) {
            cout << p[i].p_id << "\t"
                << p[i].at << "\t"
                << p[i].bt << "\t"
                << p[i].ct << "\t"
                << p[i].tat << "\t"
                << p[i].wt << "\n";
        }

        cout << "\nAverage Waiting Time: " << avgWT / n;
        cout << "\nAverage Turnaround Time: " << avgTAT / n;

        return 0;
    }