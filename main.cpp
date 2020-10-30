#include <iostream>

#include "pqueue.h"

using namespace std;

int main()
{
    PQueue<int> queue;
    queue.enqueue(1, 5);
     std::cout << queue << std::endl;
    queue.enqueue(2, 7);
     std::cout << queue << std::endl;
    queue.enqueue(4, 2);
     std::cout << queue << std::endl;
    queue.enqueue(4, 6);
     std::cout << queue << std::endl;
    queue.enqueue(1, 8);

    std::cout << queue << std::endl;

    for (int i = 0; i < 1e5; ++i) {
        queue.enqueue(std::rand() % 30, i);
//         std::cout << queue << std::endl;
    }

     std::cout << queue << std::endl;

    return 0;
}
