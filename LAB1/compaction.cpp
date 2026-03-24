#include <bits/stdc++.h>
using namespace std;

struct Block {
    string name;
    int size;
    int start;
};

int main() {

    vector<Block> memory = {
        {"os",400,0},
        {"p1",200,400},
        {"p2",100,600},
        {"Hole",400,700},
        {"p3",200,1100},
        {"Hole",300,1300},
        {"p4",400,1600},
        {"Hole",200,2000}
    };

    vector<Block> holes;
    vector<Block> processes;

    for (auto &b : memory) {
        if (b.name == "Hole") holes.push_back(b);
        else processes.push_back(b);
    }

    int totalMovement = 0;

    //  Find last hole
    Block lastHole = holes.back();

    for (auto &p : processes) {

        if (p.name == "p3") {
            // Move p3 to last hole
            p.start = lastHole.start;

            // Movement = size of process
            totalMovement += p.size;
        }
    }

    cout << "After Compaction:\n";
    for (auto &p : processes) {
        cout << p.name << " -> Start: " << p.start
             << ", Size: " << p.size << endl;
    }

    cout << "\nTotal Movement (Data shifted): "
         << totalMovement << endl;

    return 0;
}