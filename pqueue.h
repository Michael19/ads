#ifndef PQUEUE_H
#define PQUEUE_H


template<class T>
struct PR_Element{
    T* pointer_to_data;
    int priority;
    size_t size; // size of data

    PR_Element():pointer_to_data(nullptr), priority(-1), size(0){

    }


};

template<class T>
class PQueue{
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

            _data = new T[SIZE_OF_BLOCKS_PRIORITY];
            _priority = new PR_Element[SIZE_OF_BLOCKS_PRIORITY];
        }

        if(!(_size % SIZE_OF_BLOCKS)){
            T* temp_data = new T[_size + SIZE_OF_BLOCKS];
            int* temp_priority = new int[_size + SIZE_OF_BLOCKS];

            for (int i = 0; i < _size; ++i) {
                temp_data[i] = _data[i];
                temp_priority[i] = _priority[i];
            }

            delete[] _data;
            delete[] _priority;

            _data = temp_data;
            _priority = temp_priority;
        }

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


            if(!(_size % SIZE_OF_BLOCKS_PRIORITY))
            {
                _priority

                T* temp_data = new T[_size + SIZE_OF_BLOCKS_PRIORITY];

                for (int j = 0; j < _size + SIZE_OF_BLOCKS_PRIORITY; ++j) {
                    if(j == new_pos)
                    {
                        temp_data[j] = new T[SIZE_OF_BLOCKS];
                        temp_data[j][]
                    }
                }


                _data = new T*[_size + SIZE_OF_BLOCKS_PRIORITY];
            }



        }

        if(new_pos)

        for (int i = new_pos; i < _size+1; ++i) {
            _data[i+1] = _data[i];
            _priority[i+1] = _priority[i];
        }

        _data[new_pos] = item;
        _priority[new_pos] = priority;

        _size++;

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
    PR_Element* _priority; // массив указателей на данные, отсортированный по приоритетам
    size_t _size; // количество приоритетов

    const size_t SIZE_OF_BLOCKS;
    const size_t SIZE_OF_BLOCKS_PRIORITY;
};

#endif // PQUEUE_H

