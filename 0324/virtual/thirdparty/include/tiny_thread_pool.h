#ifndef _TinyThreadPool_H
#define _TinyThreadPool_H
#include <mutex>
#include <functional>
#include <condition_variable>
#include <queue>
#include <thread>

class TinyThreadPool
{
 private:
  struct data {
    std::mutex mtx_;
    std::condition_variable cond_;
    std::condition_variable cond_thread_done_;
    int  active_task = 0;
    bool is_shutdown_ = false;
    std::queue<std::function<void(int)>> tasks_;
  };

  int m_thread_count;
  std::shared_ptr<data> m_data;

public:
    explicit TinyThreadPool(size_t thread_count)
     :m_thread_count(thread_count),
     m_data(std::make_shared<data>()) 
    {
        for (size_t i = 0; i < thread_count; ++i) {
            std::thread([data = m_data, tid = i] {                     // lambda expression
                std::unique_lock<std::mutex> lk(data->mtx_);
                for (;;) {
                    if (!data->tasks_.empty()) {
                        auto current = std::move(data->tasks_.front());
                        data->tasks_.pop();
                        lk.unlock();
                        current(tid);
                        lk.lock();                                      // enter critical section again
                        data->active_task--;
                        if (data->active_task == 0)
                            data->cond_thread_done_.notify_one();
                    } else if (data->is_shutdown_) {
                        break;
                    } else {
                        data->cond_.wait(lk);                          // no task execute. wait for notity
                    }
                }
            }).detach();

        }
    }

  TinyThreadPool() = default;
  TinyThreadPool(TinyThreadPool&&) = default;

  void waitAll() {
    std::unique_lock<std::mutex> lk(m_data->mtx_);
    while (m_data->active_task != 0)
        m_data->cond_thread_done_.wait(lk);
  }
 
  int getThreadCount() { return m_thread_count; }

  template <class F>
  void execute(F&& task) {
    {
        std::lock_guard<std::mutex> lk(m_data->mtx_);
        m_data->tasks_.emplace(std::forward<F>(task));
        m_data->active_task++;
    }
    m_data->cond_.notify_one();
  }

  ~TinyThreadPool() {
    if ((bool) m_data) {
      {
        std::lock_guard<std::mutex> lk(m_data->mtx_);
        m_data->is_shutdown_ = true;
      }
      m_data->cond_.notify_all();
    }
  }
};

#endif
