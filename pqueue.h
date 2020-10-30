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

    PR_Element<T>& operator =(const PR_Element<T>& other){
        this->pointer_to_data = other.pointer_to_data;
        this->priority = other.priority;
        this->size = other.size;
    }

    bool is_empty()const{
        return size == 0;
    }


};

template<class T>
class PQueue;

template<class T>
ostream& operator<<(ostream& os, const PQueue<T>& dt);

template<class T>
class PQueue{
public:
    template<T>
    friend ostream& operator<<(ostream& os, const PQueue<T>& dt);

public:
    PQueue(): _data(nullptr), _priority(nullptr), _size(0){

    }

    ~PQueue()
    {
        if(_priority)
            delete[] _priority;
    }

    void resize(){

        PR_Element<T>* _priority_temp = nullptr;
        _priority_temp =   new PR_Element<T>[_size + SIZE_OF_BLOCKS_PRIORITY];


        for (int i = 0; i < _size; ++i) {
            _priority_temp[i] = _priority[i];
        }
        for (int i = _size; i < _size+ SIZE_OF_BLOCKS_PRIORITY; ++i) {
            T* data = new T[SIZE_OF_BLOCKS];
            _priority_temp[i].pointer_to_data = data;
        }

        delete[] _priority;
        _priority = _priority_temp;

    }

    void copy_priority(int new_pos){
        PR_Element<T> new_elem = _priority[_size], buffer;
        for (int i = 1; i < _size+1; ++i) {

            if(i > new_pos){
                //                if(!(_priority[i].is_empty()))
                 buffer = _priority[i] ;

                _priority[i] =_priority[new_pos];
                _priority[new_pos] = buffer;
                if(buffer.is_empty())
                    break;
            }
        }
        _priority[new_pos] = new_elem;

    }

    void enqueue(int priority, T item)
    {
        // init
        if(!_priority){
            _priority = new PR_Element<T>[SIZE_OF_BLOCKS_PRIORITY];

            for (int i = 0; i < SIZE_OF_BLOCKS_PRIORITY; ++i) {
                T* data = new T[SIZE_OF_BLOCKS];
                _priority[i].pointer_to_data = data;
            }
        }

        bool is_insert(false);
        int new_pos = _size;
        for (int j = 0; j < _size; ++j) {
            if(_priority[j].priority < priority){
                new_pos = j;
                break;
            }

            if(_priority[j].priority == priority){
                is_insert = true;
                new_pos = j;
                break;
            }
        }

        std::cout << "new_pos = " << new_pos << std::endl;

        if(!(_size % SIZE_OF_BLOCKS_PRIORITY) && !is_insert && _size > 0){
            // resize and copy data;

            resize();
            copy_priority(new_pos);
        }
        else if(!is_insert && new_pos < _size){
            copy_priority(new_pos);
        }

        _priority[new_pos].pointer_to_data[_priority[new_pos].size] = item;
        _priority[new_pos].size++;

        if(!is_insert)
        {
            _priority[new_pos].priority = priority;
            _size++;
        }

#if 0


        bool is_insert = false;// check if data into deque
        int new_pos = _size;
        if(new_pos != 0){
            for (int i = 0; i < _size; ++i) {
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
        }

        if(!is_insert)
        {
            if(!(_size % SIZE_OF_BLOCKS_PRIORITY) || new_pos < _size)
            {
                PR_Element<T>* _priority_temp = nullptr;
                if(!(_size % SIZE_OF_BLOCKS_PRIORITY))
                {
                    _priority_temp =   new PR_Element<T>[_size + SIZE_OF_BLOCKS_PRIORITY];
                }
                else{
                    _priority_temp =   new PR_Element<T>[int(_size / SIZE_OF_BLOCKS_PRIORITY) * SIZE_OF_BLOCKS_PRIORITY];
                }
                _size++;

                for (int j = 0; j < _size; ++j)
                {
                    if(j == new_pos)
                    {
                        _priority_temp[j].pointer_to_data = new T[SIZE_OF_BLOCKS];
                        _priority_temp[j].size++;
                        _priority_temp[j].pointer_to_data[0] = item;
                        _priority_temp[j].priority=priority;
                    }
                    else if(j > new_pos){
                        _priority_temp[j] = _priority[j-1];
                        std::cout << "_priority_temp[j].pointer_to_data[0] " << _priority_temp[j].pointer_to_data[0] << std::endl;
                    }
                    else{
                        _priority_temp[j] = _priority[j];
                    }
                }

                delete[] _priority;
                _priority = _priority_temp;
            }
            else
            {
                _priority[_size].pointer_to_data = new T[SIZE_OF_BLOCKS];
                _priority[_size].size++;
                _priority[_size].pointer_to_data[0] = item;
            }
        }

#endif

    }

    T dequeue(){
        if(_priority && _size > 0){


            T out = _priority[0].pointer_to_data[0];

            T* temp_data = _priority[0].pointer_to_data;
            _priority[0].pointer_to_data = temp_data[1];

            delete temp_data;
            return out;


        }

        return T();
    }

    void print() const{
        size_t s = _size;
        for (int i = 0; i < s; ++i) {
            size_t ss = _priority[i].size;
            std::cout << _priority[i].priority << " : ";
            for (int j = 0; j < ss; ++j) {
                std::cout << _priority[i].pointer_to_data[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    size_t size()const{
        return _size;
    }

private:



private:
    T** _data;
    PR_Element<T>* _priority; // массив указателей на данные, отсортированный по приоритетам
    size_t _size; // количество приоритетов

    const size_t SIZE_OF_BLOCKS = 1000;
    const size_t SIZE_OF_BLOCKS_PRIORITY = 20;
};

template<class T>
ostream& operator<<(ostream& os, const PQueue<T>& dt)
{
    dt.print();

    return os;
}

#endif // PQUEUE_H

