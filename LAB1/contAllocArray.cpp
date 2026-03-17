#include <iostream>
using namespace std;

int main() {
    int n, blockSize;
    cout << "Enter total number of memory blocks: ";
    cin >> n;

    cout << "Enter size of EACH block (KB): ";
    cin >> blockSize;

    int memory[n];   

    // Initialize memory as free
    for(int i = 0; i < n; i++)
        memory[i] = 0;

    int choice;
    do {
        cout << "\n-------- CONTIGUOUS ALLOCATION MENU --------\n";
        cout << "1. Allocate File (Contiguous)\n";
        cout << "2. Display Memory Status\n";
        cout << "3. Show External Fragmentation\n";
        cout << "4. Show Internal Fragmentation\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // --------- OPTION 1: CONTIGUOUS ALLOCATION ----------
        if(choice == 1) {
            int start, fileSize;
            cout << "Enter starting block: ";
            cin >> start;

            cout << "Enter file size (in KB): ";
            cin >> fileSize;

            // Blocks required by file
            int blocksNeeded = fileSize / blockSize;
            if(fileSize % blockSize != 0)
                blocksNeeded++;

            bool possible = true;

            // Check if contiguous space available
            for(int i = start; i < start + blocksNeeded; i++) {
                if(i >= n || memory[i] == 1) {
                    possible = false;
                    break;
                }
            }

            if(!possible) {
                cout << "\n Contiguous allocation NOT possible!\n";
            } else {
                for(int i = start; i < start + blocksNeeded; i++)
                    memory[i] = 1;

                cout << "\n File allocated in blocks: ";
                for(int i = start; i < start + blocksNeeded; i++)
                    cout << i << " ";
                cout << endl;
            }
        }

        // OPTION 2: DISPLAY MEMORY 
        else if(choice == 2) {
            cout << "\nMemory Status (0 = free, 1 = allocated):\n";
            for(int i = 0; i < n; i++)
                cout << i << " ";
            cout << "\n";
            for(int i = 0; i < n; i++)
                cout << memory[i] << " ";
            cout << endl;
        }

        //  OPTION 3: EXTERNAL FRAGMENTATION 
        else if(choice == 3) {
            int freeBlocks = 0, largestGap = 0, currentGap = 0;

            for(int i = 0; i < n; i++) {
                if(memory[i] == 0) {
                    freeBlocks++;
                    currentGap++;
                } else {
                    largestGap = max(largestGap, currentGap);
                    currentGap = 0;
                }
            }
            largestGap = max(largestGap, currentGap);

            cout << "\n----- External Fragmentation Analysis -----\n";
            cout << "Total free blocks: " << freeBlocks << endl;
            cout << "Largest contiguous free space: " << largestGap << endl;

            if(freeBlocks > 0 && largestGap < freeBlocks)
                cout << "External Fragmentation EXISTS in memory.\n";
            else
                cout << " No external fragmentation.\n";
        }

        //  INTERNAL FRAGMENTATION 
        else if(choice == 4) {
            int fileSize;
            cout << "Enter file size (KB): ";
            cin >> fileSize;

            int blocksNeeded = fileSize / blockSize;
            if(fileSize % blockSize != 0)
                blocksNeeded++;

            int allocatedSpace = blocksNeeded * blockSize;
            int internalFrag = allocatedSpace - fileSize;

            cout << "\n----- Internal Fragmentation Demo -----\n";
            cout << "Blocks needed: " << blocksNeeded << endl;
            cout << "Allocated space: " << allocatedSpace << " KB\n";
            cout << "Actual file size: " << fileSize << " KB\n";
            cout << "Internal Fragmentation = " << internalFrag << " KB\n";
        }

    } while(choice != 5);

    cout << "\nProgram terminated.\n";
    return 0;
}
