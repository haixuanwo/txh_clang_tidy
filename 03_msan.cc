/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-21 10:43:35
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-21 11:37:28
 * @Description: file content
 */

/*
clang++ -fsanitize=memory -fsanitize-memory-track-origins -g 03_msan.cc
./a.out
*/

#include <cstdio>

class Foo
{
 public:
    void print()
    {
        if (initialized_)
        {
            printf("Good!\n");
        }
    }
 private:
    bool initialized_;
};

int main()
{
    Foo foo;
    foo.print();
}
