#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DISK_SIZE 50

int disk[DISK_SIZE];

struct File {
    string name;
    int indexBlock;          
    vector<int> blocks;      
};

File files[10];
int fileCount = 0;

void allocateFile(string name, int length) {
    vector<int> allocatedBlocks;
    int indexBlock = -1;
    for (int i = 0; i < DISK_SIZE; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            indexBlock = i;
            break;
        }
    }

    if (indexBlock == -1) {
        cout << "No free block available for index block of file '" << name << "'" << endl;
        return;
    }

    for (int i = 0; i < DISK_SIZE && allocatedBlocks.size() < length; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            allocatedBlocks.push_back(i);
        }
    }

    if (allocatedBlocks.size() == length) {
        files[fileCount].name = name;
        files[fileCount].indexBlock = indexBlock;
        files[fileCount].blocks = allocatedBlocks;
        fileCount++;
        cout << "File '" << name << "' allocated with index block " << indexBlock << endl;
    } else {
        cout << "Not enough free blocks for file '" << name << "'" << endl;
        // Free allocated blocks
        disk[indexBlock] = 0;
        for (int b : allocatedBlocks) {
            disk[b] = 0;
        }
    }
}

void displayDisk() {
    cout << "\nDisk Status (0=free, 1=occupied):\n";
    for (int i = 0; i < DISK_SIZE; i++) {
        cout << disk[i] << " ";
    }
    cout << endl;
}

void displayFiles() {
    cout << "\nFile Allocation Table:\n";
    for (int i = 0; i < fileCount; i++) {
        cout << "File: " << files[i].name
             << " | Index Block: " << files[i].indexBlock
             << " | Data Blocks: ";
        for (int b : files[i].blocks) {
            cout << b << " ";
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < DISK_SIZE; i++) {
        disk[i] = 0;
    }

    allocateFile("A", 6);
    allocateFile("B", 10);
    allocateFile("C", 15);

    displayDisk();
    displayFiles();

    return 0;
}