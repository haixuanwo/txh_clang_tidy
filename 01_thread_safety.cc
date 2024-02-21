/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-21 10:57:24
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-21 11:32:18
 * @Description: file content
 */

/*
clang++ -Wthread-safety 01_thread_safety.cc
./a.out
*/

// @uncomplete

#include <thread>
#include <mutex>
using namespace std;

class Counter
{
public:
    void increase();
    int get() const;

private:
    // mutable MutexLock mutex_;
    mutable mutex mutex_;
    // int count_ GUARDED_BY(mutex_);
    int count_;
};

void Counter::increase()
{
    // MutexLockGuard L(mutex_);   // 与成员变量同名，导致锁失败
    lock_guard<std::mutex> L(mutex_);
    ++count_; // Good
}

int Counter::get() const
{
    // warning: reading variable'count_'
    // requires holding mutex 'mutex_'.
    return count_; // Data race!
}

Counter counter;

void test_thread()
{
    while (1)
    {
        counter.increase();
        counter.get();
    }
}

int main()
{
    thread th1(test_thread);
    thread th2(test_thread);

    th1.join();
    th2.join();

    return 0;
}
