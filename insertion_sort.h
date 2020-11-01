#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

template<class T>
void insertion_sort(T* data, size_t size){
    int i(0);
    for (int j = 0; j < size; ++j) {
        T key = data[j];
        i = j-1;
        while(i > 0 && data[i] > key)
        {
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = key;
    }
}

template<class T>
void shell_insertion_sort(T* data, size_t size){

}

#endif // INSERTION_SORT_H
