#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

void testCreateChild() {
    int currentPID = getpid();
    cout << "About to Fork" << endl; // Parent process
    int fork_result = fork();
    cout << "--------" << endl;
    cout << "Parent PID: " << currentPID << endl;
    cout << "Current returned pid: " << fork_result << endl;
    if (fork_result == 0) {
        cout << "I am child process" << endl;
        cout << "child process PID: " << getpid() << endl;
    }
    cout << "I've forked" << endl;
}

// Example to print only each pid
void testPidCheck() {
    int my_pid = -1;
    cout << "About to fork" << endl;
    int rtf = fork();
    if (rtf == 0) { // Child process
        my_pid = getpid();
        cout << "Child pid is " << my_pid << endl;
    } else {
        my_pid = getpid();
        cout << "parent pid is " << my_pid << endl;
    }
}

// Test sleep
void testSleep() {
    int my_pid = -1;
    cout << "About to Fork" << endl;
    int rtf = fork();
    if (rtf == 0) {
        my_pid = getpid();
        cout << "Child pid is " << my_pid << endl;
        sleep(3);
        cout << "Child is done sleeping" << endl;
    } else {
        int status;
        cout << "status: " << status << endl;
        my_pid = getpid();
        wait(&status);
        cout << "parent pid is " << my_pid << endl;
    }
}

// Test exec
void testExec() {
    int myPid = -1;
    cout << "About to fork " << endl;
    int rtf = fork();
    if (rtf == 0) { // Child
        myPid = getpid();
        cout << "Child pid is " << myPid << endl;
        sleep(3);
        cout << "child is done sleeping" << endl;
        int rc = execlp("/bin/ls", "ls", "-l", (char *) 0);
        if (rc == -1) {
            cout << "EXEC FAILED" << endl;
        }
    } else {
        int status;
        myPid = getpid();
        wait(&status);
        cout << "parent pid is" << myPid << endl;
    }
}

int main() {
    // testCreateChild();
    // testPidCheck();
    // testSleep();
    testExec();
    return 0;
}