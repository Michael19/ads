#ifndef _HEAP_SORT_
#define _HEAP_SORT_

#include <cmath>
#include <utility>
#include "insertion_sort.h"
#include <thread>

enum VertexType{

    Parent,
    LeftChild,
    RightChild
};


int vertex(int i, VertexType t){

    switch (t) {
    case VertexType::Parent:
        return i ? std::floor((i-1) / 2) : 0;
        break;
    case VertexType::LeftChild:
        return i * 2 + 1;
        break;
    default:
        return i * 2 + 2;
        break;
    }

}

template<class T>
void Drown(T* data, int i, size_t size){
    int left = vertex(i, VertexType::LeftChild);
    int right = vertex(i, VertexType::RightChild);

    int largest = i;
    if( left < size && data[left] > data[right])
        largest = left;

    if(right < size && data[right] > data[largest])
        largest = right;

    if(largest != i){
        std::swap(data[i], data[largest]);
        Drown(data, largest, size);
    }

}

template<class T>
void DrownStack(T* data, int i, size_t size){
    int largest = i;

    do
    {
        int left = vertex(i, VertexType::LeftChild);
        int right = vertex(i, VertexType::RightChild);

        i = largest;

        if( left < size && data[left] > data[right])
            largest = left;

        if(right < size && data[right] > data[largest])
            largest = right;

        if(largest != i){
            std::swap(data[i], data[largest]);
            //            Drown(data, largest, size);
        }

    }while(largest != i);

}

template<class T>
void BuildHeap(T* data, size_t size){
    for (int i =  std::floor((size - 1) / 2); i >= 0 ;--i) {
        DrownStack(data, i, size);
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
    for (int i = size - 1; i >= 1; --i) {
        s--;
        std::swap(data[0], data[i]);
        DrownStack(data, 0, s);
    }
}

template<class T>
void merge(T* data, size_t size, int middle){

    T* merged = new T[size];

    int idx_min_f = 0, idx_min_s = 0;

    for (int i = 0; i < size; ++i) {

        if(idx_min_f == middle || (middle + idx_min_s != size && data[idx_min_f] >= data[middle + idx_min_s]))
        {
            merged[i] = data[middle + idx_min_s];
            idx_min_s++;
        }
        else
            merged[i] = data[idx_min_f++];
    }

    for (int i = 0; i < size; ++i) {
        data[i] = merged[i];
    }
    delete[] merged;

}

template<class T>
void partion_sort(T* data, size_t size, size_t min_size)
{
    if(size <= min_size){
        std::thread t1(insertion_sort<T>, data, size);
        t1.detach();
        return;
    }

    partion_sort(data, std::floor(size/ 2), min_size);
    T* part = data + static_cast<int>(std::floor(size/ 2));
    partion_sort(part, size - std::floor(size/ 2), min_size);

    merge(data, size, static_cast<int>(std::floor(size/ 2)));

}

template<class T>
void mergesort(T* data, size_t size, size_t min_size)
{
    partion_sort(data, size, min_size);

}


#endif
