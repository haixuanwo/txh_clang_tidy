/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-21 11:58:21
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-21 12:43:39
 * @Description: file content
 */

#include <thread>
#include <mutex>
using namespace std;

/*
clang++ 05_unique_lock.cc
*/

// What’s wrong with follow code of thread-safe counter?
class Counter
{
 public:
    void increase()
    {
        std::unique_lock<std::mutex> (mu_); // WRONG, no locking at all
        // std::unique_lock<std::mutex> L(mu_); // Correct
        ++count_;
    }

 private:
    mutable std::mutex mu_;
    int count_ = 0;
};

Counter counter;

void test_thread()
{
    while (1)
    {
        counter.increase();
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
