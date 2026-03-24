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

    int totalMovement = 0;

    for (int i = 0; i < memory.size(); i++) {

        if (memory[i].name == "Hole") {

            for (int j = i + 1; j < memory.size(); j++) {

                if (memory[j].name != "Hole" && memory[j].name != "os") {

                    if (memory[j].size <= memory[i].size) {

                        // 🔥 store old position
                        int oldStart = memory[j].start;

                        // movement = size
                        totalMovement += memory[j].size;

                        // move process to hole
                        memory[j].start = memory[i].start;

                        // update hole
                        memory[i].start += memory[j].size;
                        memory[i].size -= memory[j].size;

                        // 🔥 add new hole at old position
                        memory.push_back({"Hole", memory[j].size, oldStart});

                        break;
                    }
                }
            }
        }
    }

    // sort memory by address
    sort(memory.begin(), memory.end(), [](auto &a, auto &b) {
        return a.start < b.start;
    });

    cout << "After Partial Compaction:\n";
    for (auto &b : memory) {
        cout << b.name << " -> Start: " << b.start
             << ", Size: " << b.size << endl;
    }

    cout << "\nTotal Movement: " << totalMovement << endl;

    return 0;
}