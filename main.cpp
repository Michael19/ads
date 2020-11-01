#include <iostream>

#include "pqueue.h"
#include "insertion_sort.h"

using namespace std;

// add thread to add elements for other priority

int main()
{
    PQueue<int> queue;

    size_t cnt = 1e4;


    for (int i = 0; i < cnt; ++i) {
        queue.enqueue(std::rand() % 30, i);
    }

    std::cout << queue << std::endl;

    for (int i = 0; i < cnt; ++i) {
        std::cout << queue.dequeue() << std::endl;
    }
    int * data = new int[cnt];
    for (int u = 0; u < cnt; ++u) {
        data[u] = std::rand() % 500;
    }

    insertion_sort(data, cnt);
    for (int u = 0; u < cnt; ++u) {
        std::cout << data[u] << " ";
    }

    return 0;
}
