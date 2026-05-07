#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    char *shm = (char *)shmat(shmid, NULL, 0);

    strcpy(shm, str.c_str());

    pid_t pid = fork();

    if (pid > 0) {
        wait(NULL);

        int vowels = 0;
        for (int i = 0; shm[i] != '\0'; i++) {
            char c = tolower(shm[i]);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowels++;
        }

        cout << "Parent (Vowel Count): " << vowels << endl;

        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    else if (pid == 0) {
        int words = 1;
        for (int i = 0; shm[i] != '\0'; i++) {
            if (shm[i] == ' ') words++;
        }

        cout << "Child (Word Count): " << words << endl;
        exit(0);
    }

    return 0;
}