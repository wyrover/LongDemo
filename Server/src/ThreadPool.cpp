
#include "ThreadPool.h"


ThreadPool::ThreadPool(int nthreads)
    : _done(false)
{
    if(nthreads <= 0)
    {
        nthreads = std::thread::hardware_concurrency();
        nthreads = (nthreads == 0 ? 2 : nthreads);
    }

    for(unsigned i = 0; i < nthreads; ++i)
    {
        _threads.push_back(std::thread([this]
        {
            while (!_done.load(std::memory_order_acquire))
            {
               std::function<void()> task;
               {
                   std::unique_lock<std::mutex> ulk(this->_mutex);
                   //this->cond_.wait(ulk, [this]{ return stop_.load(std::memory_order_acquire) || !this->tasks_.empty(); });
                   if (_done.load(std::memory_order_acquire))
                       return;
                   task = std::move(this->_tasks.front());
                   this->_tasks.pop();
               }
               task();
            }
        }));
    }
}


ThreadPool::~ThreadPool()
{

}

void ThreadPool::stop()
{
    _done.store(true, std::memory_order_release);
}
