#include <iostream>
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
#include <unistd.h>

std::mutex mtx; // ȫ�ֻ�����.
std::condition_variable cv; // ȫ����������.
bool ready = false; // ȫ�ֱ�־λ.

void do_print_id(int id)
{
    std::unique_lock <std::mutex> lck(mtx);
    std::cout << "thread " << id << " wait for read."<< '\n';
    while (!ready){ // �����־λ��Ϊ true, ��ȴ�...
        std::cout << "thread begin wait" << id << std::endl;
        usleep(1000);
        cv.wait(lck); // ��ǰ�̱߳�����, ��ȫ�ֱ�־λ��Ϊ true ֮���̱߳�����, ��������ִ�д�ӡ�̱߳��id.
        //wait�ȴ��ڼ䣬�������߳̿��Ի��mtx������wait�����Ѻ󣬾���mtx
        //sleep(1);
    }
    std::cout << "thread " << id << '\n';
}

void go()
{
    std::unique_lock <std::mutex> lck(mtx);
    std::cout << "locked!!!" << std::endl;
    std::cout << "listen!!!" << std::endl;
    ready = true; // ����ȫ�ֱ�־λΪ true.
    std::cout << "ready!!!" << std::endl;
    cv.notify_all(); // ���������߳�.
    std::cout << "go!!!" << std::endl;
}

int main()
{
    std::thread threads[10];// spawn 10 threads:

    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(do_print_id, i);
    std::cout << "10 threads ready to race...\n";

    go(); // go!
    
    for (auto & th:threads)
        th.join();
    std::cout << "finish task" << std::endl;
    return 0;
}


