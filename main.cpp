#include <iostream>

#include "pqueue.h"
#include "insertion_sort.h"
#include "heap_sort.h"

using namespace std;

// add thread to add elements for other priority

int main()
{
    const int cnt = 1e2;
    int * data = new int[cnt];
    for (int u = 0; u < cnt; ++u) {
        data[u] = std::rand() % static_cast<int>(1e2);
    }

    heap_sort(data, cnt);
    for (int u = 0; u < cnt; ++u) {
        std::cout << data[u] << " ";
    }

    return 0;
}
