#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

void testCreateChild() {
    cout << "Current PID: " << getpid() << endl;
    cout << "About to Fork" << endl; // Parent process
    int fork_result = fork();
    cout << "Current returned pid: " << fork_result << endl;
    cout << "I've forked" << endl;
}

int main() {
    testCreateChild();
    return 0;
}