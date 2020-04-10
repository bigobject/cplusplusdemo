#include <iostream>
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
#include <unistd.h>

std::mutex mtx; // 全局互斥锁.
std::condition_variable cv; // 全局条件变量.
bool ready = false; // 全局标志位.

void do_print_id(int id)
{
    std::unique_lock <std::mutex> lck(mtx);
    std::cout << "thread " << id << " wait for read."<< '\n';
    while (!ready){ // 如果标志位不为 true, 则等待...
        std::cout << "thread begin wait" << id << std::endl;
        usleep(1000);
        cv.wait(lck); // 当前线程被阻塞, 当全局标志位变为 true 之后线程被唤醒, 继续往下执行打印线程编号id.
        //wait等待期间，其他的线程可以获得mtx的锁。wait被唤醒后，具有mtx
        //sleep(1);
    }
    std::cout << "thread " << id << '\n';
}

void go()
{
    std::unique_lock <std::mutex> lck(mtx);
    std::cout << "locked!!!" << std::endl;
    std::cout << "listen!!!" << std::endl;
    ready = true; // 设置全局标志位为 true.
    std::cout << "ready!!!" << std::endl;
    cv.notify_all(); // 唤醒所有线程.
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


