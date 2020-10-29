#ifndef PQUEUE_H
#define PQUEUE_H

#include <ostream>
using namespace std;

template<class T>
struct PR_Element{
    T* pointer_to_data;
    int priority;
    size_t size; // size of data

    PR_Element():pointer_to_data(nullptr), priority(-1), size(0){

    }


};

template<class T>
ostream& operator<<(ostream& os, const PQueue<T>& dt)
{
    os << dt._size << std::endl;
    return os;
}


template<class T>
class PQueue{
public:
    friend ostream& operator<<(ostream& os, const PQueue<T>& dt);

public:
    PQueue():_data(nullptr), _priority(nullptr), _size(0){

    }

    ~PQueue()
    {
        if(_data)
            delete[] _data;

        if(_priority)
            delete[] _priority;
    }

    void enqueue(int priority, T item)
    {
        // init
        if(!_data || !_priority){
            if(_data)
                delete[] _data;

            if(_priority)
                delete _priority;

            _data = new T*[SIZE_OF_BLOCKS_PRIORITY];
            _priority = new PR_Element<T>[SIZE_OF_BLOCKS_PRIORITY];
        }

//        if(!(_size % SIZE_OF_BLOCKS)){
//            T* temp_data = new T[_size + SIZE_OF_BLOCKS];
//            int* temp_priority = new int[_size + SIZE_OF_BLOCKS];

//            for (int i = 0; i < _size; ++i) {
//                temp_data[i] = _data[i];
//                temp_priority[i] = _priority[i];
//            }

//            delete[] _data;
//            delete[] _priority;

//            _data = temp_data;
//            _priority = temp_priority;
//        }

        bool is_insert = false;// check if data into deque
        int new_pos = _size+1;
        for (int i = 0; i < _size-1; ++i) {
            if(_priority[i].priority == priority){
                // в очереди есть с таким приоритетом

                if(!(_priority[i].size % SIZE_OF_BLOCKS)){
                    T* temp_data = new T[_priority[i].size + SIZE_OF_BLOCKS];

                    for (int j = 0; j < _priority[i].size + SIZE_OF_BLOCKS; ++j) {
                        temp_data[j] = _priority[i].pointer_to_data[j];
                    }

                    delete[] _priority[i].pointer_to_data;

                    _priority[i].pointer_to_data = temp_data;

                }
                is_insert != true;
                break;
            }
            else if(_priority[i].priority < priority){
                // данные с наивысшем приоритетом
                new_pos = 0;
                break;
            }

            else if(_priority[i].priority > priority && _priority[i+1].priority < priority){
                // данные с новым промежуточным приоритетом
                new_pos = i+1;
                break;
            }
        }

        if(!is_insert)
        {
            if(!(_size % SIZE_OF_BLOCKS_PRIORITY) || new_pos <= _size)
            {
                PR_Element<T>* _priority_temp = new PR_Element<T>[_size + SIZE_OF_BLOCKS_PRIORITY];

                for (int j = 0; j < _size; ++j)
                {
                    if(j == new_pos)
                    {
                        _priority_temp[j].pointer_to_data = new T[SIZE_OF_BLOCKS];
                        _priority_temp[j].size++;
                        _priority_temp[j].pointer_to_data[0] = item;
                    }
                    else if(j > new_pos){
                        _priority_temp[j] = _priority[j];
                    }
                    else{
                        _priority_temp[j] = _priority[j+1];
                    }
                }
            }
            else{
                _priority[_size].pointer_to_data = new T[SIZE_OF_BLOCKS];
                _priority[_size].size++;
                _priority[_size].pointer_to_data[0] = item;
            }
        }

    }

    T dequeue(){
        if(_data && _priority && _size > 0){

            T return_element = _data[0];



            return return_element;
        }

        return T();
    }

private:



private:
    T** _data; // данные
    PR_Element<T>* _priority; // массив указателей на данные, отсортированный по приоритетам
    size_t _size; // количество приоритетов

    const size_t SIZE_OF_BLOCKS = 10;
    const size_t SIZE_OF_BLOCKS_PRIORITY = 10;
};

#endif // PQUEUE_H

