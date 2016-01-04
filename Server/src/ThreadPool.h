#ifndef ThreadPool_H
#define ThreadPool_H

#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <atomic>
#include <mutex>


class ThreadPool
{
public:
    ThreadPool(int nthreads);
    ~ThreadPool();

public:
    void stop();

    /*
private:
    ThreadPool(ThreadPool &&) = delete;
    ThreadPool& operator = (ThreadPool &&) = delete;
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool& operator = (const ThreadPool &) = delete;
    */

private:
    std::vector<std::thread> _threads; //线程
    std::queue<std::function<void()>> _tasks; //线程任务
    std::atomic<bool> _done; //任务是否完成
    std::mutex _mutex; //锁
};

#endif
