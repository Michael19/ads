#include <iostream>

#include "pqueue.h"
#include "insertion_sort.h"
#include "heap_sort.h"

using namespace std;

// add thread to add elements for other priority

int main()
{
//    int* first = new int[5];
//    int* second = new int[5];

//    for (int i = 0; i < 5; ++i) {
//        first[i] = i * 2;
//        second[i] = i * 3;
//    }
//    int * out = nullptr;

//    merge(first, second, 5, out);


//    for (int i = 0; i < 10; ++i) {
//        std::cout << out[i] << " ";
//    }
//    std::cout <<std::endl;

//    return 0;

    const int cnt = 1e7;
    int * data = new int[cnt];
    for (int u = 0; u < cnt; ++u) {
        data[u] = std::rand() % static_cast<int>(1e5);
//        std::cout <<  data[u] << " ";
    }
//    std::cout << std::endl;

    mergesort(data, cnt, 600);
//    for (int u = 0; u < cnt; ++u) {
//        std::cout << data[u] << " ";
//    }

    return 0;
}
