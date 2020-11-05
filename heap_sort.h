#ifndef _HEAP_SORT_
#define _HEAP_SORT_

#include <cmath>
#include <utility>

enum VertexType{

    Parent,
    LeftChild,
    RightChild
};


int vertex(int i, VertexType t){

    switch (t) {
    case VertexType::Parent:
        return std::floor((i-1) / 2);
        break;
    case VertexType::LeftChild:
        return i * 2;
        break;
    default:
        return i * 2 + 1;
        break;
    }

}

template<class T>
void Drown(T* data, int i, size_t size){
    int left = vertex(i, VertexType::LeftChild);
    int right = vertex(i, VertexType::RightChild);

    int largest = i;
    if( left <= size && data[left] > data[right])
        largest = left;

    if(right <= size && data[right] > data[largest])
        largest = right;

    if(largest != i){
        std::swap(data[i], data[largest]);
        Drown(data, largest, size);
    }

}

template<class T>
void BuildHeap(T* data, size_t size){
    for (int i =  std::floor((size - 1) / 2); i > 0 ;--i) {
        Drown(data, i, size);
    }
}


template<class T>
void heap_sort(T* data, size_t size)
{
    BuildHeap(data,size);
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout <<std::endl;

    size_t s = size;
    for (int i = size - 1; i > 1; --i) {
        s--;
        std::swap(data[0], data[i]);
        Drown(data, 0, s);
    }
}

#endif
