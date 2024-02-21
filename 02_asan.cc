/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-02-21 11:28:54
 * @LastEditors: Clark
 * @LastEditTime: 2024-02-21 11:32:42
 * @Description: file content
 */

/*
clang++ -fsanitize=address -g 02_asan.cc
g++ -fsanitize=address -g 02_asan.cc
./a.out
*/

struct Node
{
    Node* next;
    int value;
};

void freeListBad(Node* head)
{
    for (; head != nullptr; head = head->next)
    {
        delete head;
    }
}

int main()
{
    Node head;
    freeListBad(&head);

    return 0;
}
