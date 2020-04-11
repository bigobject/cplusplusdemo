#include <iostream>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;


int main() {
    float pi = 3.14;

    std::cout << "father pid:" << getpid() << std::endl;

    do {
        pid_t pid = fork();

        if (pid < 0) {
            std::cout << "error pid" << pid << std::endl;
            return 0;
        }

        if (pid == 0) {
            std::cout << "son ,pi:" << pi << " with addr:" << &pi << std::endl;
            std::cout << "son ,pid:" << pid << " with addr:" << &pid << std::endl;
            return 0;
        }else {
            int status;
            waitpid(-1, &status, 0);
            std::cout << "father ,pi:" << pi << " with addr:" << &pi << std::endl;
            std::cout << "father ,pid:" << pid << " with addr:" << &pid << std::endl;
        }
    }while (true);
}
