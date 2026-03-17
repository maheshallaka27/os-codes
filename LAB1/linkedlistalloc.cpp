#include <iostream>
#include <string>
using namespace std;

#define DISK_SIZE 50

struct Block {
    int index;
    Block* next;
};

struct File {
    string name;
    Block* start;
};

File files[10];
int fileCount = 0;
int disk[DISK_SIZE];

void allocateFile(string name, int length) {
    int allocated = 0;
    Block* head = nullptr;
    Block* tail = nullptr;

    for (int i = 0; i < DISK_SIZE && allocated < length; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            Block* newBlock = new Block();
            newBlock->index = i;
            newBlock->next = nullptr;

            if (head == nullptr) {
                head = newBlock;
                tail = newBlock;
            } else {
                tail->next = newBlock;
                tail = newBlock;
            }
            allocated++;
        }
    }

    if (allocated == length) {
        files[fileCount].name = name;
        files[fileCount].start = head;
        fileCount++;
        cout << "File '" << name << "' allocated with " << length << " blocks." << endl;
    } else {
        cout << "Not enough free blocks for file '" << name << "'" << endl;
        Block* temp = head;
        while (temp != nullptr) {
            disk[temp->index] = 0;
            Block* del = temp;
            temp = temp->next;
            delete del;
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
        cout << "File: " << files[i].name << " | Blocks: ";
        Block* temp = files[i].start;
        while (temp != nullptr) {
            cout << temp->index << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < DISK_SIZE; i++) {
        disk[i] = 0;
    }

    allocateFile("A", 8);
    allocateFile("B", 12);
    allocateFile("C", 20);

    displayDisk();
    displayFiles();

    return 0;
}