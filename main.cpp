#include <iostream>

#include "pqueue.h"

using namespace std;

int main()
{
    PQueue<int> queue;
    queue.enqueue(1, 5);
    queue.enqueue(2, 7);
    queue.enqueue(4, 2);
    queue.enqueue(4, 6);
    queue.enqueue(4, 8);

    return 0;
}
