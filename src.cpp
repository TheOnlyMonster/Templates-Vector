#include "header.h"
template <class T,size_t S>
Vector<T,S>::~Vector(){
    delete[] arr;
    capacity = 0;
    size = 0;
}
template <class T,size_t S>
typename Vector<T,S>::Iterator Vector<T,S>::begin(){
    return arr;
}
template <class T,size_t S>
typename Vector<T,S>::Iterator Vector<T,S>::end(){
    return (arr + size);
}
template <class T,size_t S>
Vector<T,S>::Vector(const T (&new_arr)[S])
{
    this->size = S;
    this->capacity = size * 2;
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = new_arr[i];
    }
}
template <class T,size_t S>
Vector<T,S>::Vector(){
    this->size = S;
    this->capacity = size * 2;
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = 0;
    }
}
template <class T,size_t S>
T& Vector<T,S>::operator[](int index){
    return *(arr + index);
}
template <class T,size_t S>
void Vector<T,S>::push_back(T t){
    if(size==capacity){
        increase_capacity();
    }
    *(arr + size) = t;
    size++;
}
template <class T,size_t S>
void Vector<T,S>::increase_capacity(){
    T *new_arr = new T[size * 2];
    for (int i = 0; i < size; i++)
    {
        *(new_arr + i) = *(arr + i);
    }
    delete[] arr;
    arr = new_arr;
    capacity = size * 2;
}
template <class T,size_t S>
T Vector<T,S>::pop_back(){
    T *temp_arr = new T[--size];
    for (int i = 0; i < size; i++)
    {
        *(temp_arr + i) = *(arr + i);
    }
    delete[] arr;
    arr = temp_arr;
    return *(arr + size - 1);
}
template <class T,size_t S>
void Vector<T,S>::insert(Iterator it_position, T t){
    if(size==capacity){
        increase_capacity();
    }
    int it_index = it_position - begin();
    int dist = end() - it_position;
    T *temp_arr = new T[dist];
    for (int i = it_index, j=0; j < dist; i++,j++)
    {
        *(temp_arr + j) = *(arr + i);
    }
    *(it_position) = t;
    for (int i = it_index + 1, j=0; j < dist; i++,j++)
    {
        *(arr + i) = *(temp_arr + j);
    }
    delete[] temp_arr;
    size++;
}
template <class T,size_t S>
void Vector<T,S>::erase(Iterator it_position){
    int it_index = it_position - begin();
    T *temp_arr = new T[capacity];
    auto it = begin();
    for (int i = 0, j = 0; i < size; i++, it++, j++)
    {
        if(it!=it_position){
            *(temp_arr + j) = *(arr + i);
        }
        else{
            j--;
        }
    }
    size--;
    delete[] arr;
    arr = temp_arr;
}
template <class T,size_t S>
void Vector<T,S>::clear(){
    delete[] arr;
    size = 0;
    capacity = 2;
    arr = new T[capacity];
}
template <class T,size_t S>
void Vector<T,S>::erase(Iterator it1,Iterator it2){
    if (it1 <= it2){
        int index_iterator = it2 - begin();
        int before = it1 - begin();
        T *temp_arr = new T[capacity];
        for (int i = 0; i < before; i++)
        {
            *(temp_arr + i) = *(arr + i);
        }
        for (int i = index_iterator+1,j=before; i < size; i++,j++)
        {
            *(temp_arr + j) = *(arr + i);
        }
        size -= (index_iterator - before + 1);
        delete[] arr;
        arr = temp_arr;
    }
}
template <class T,size_t S>
bool Vector<T,S>::empty(){
    return (size == 0) ? true : false;
}
template <class T,size_t S>
int Vector<T,S>::Size(){
    return size;
}
template <class T,size_t S>
int Vector<T,S>::Capacity(){
    return capacity;
}
template <class T,size_t S>
int Vector<T,S>::resize(){
    capacity = 2 * size;
    return capacity;
}
