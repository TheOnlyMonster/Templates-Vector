#ifndef HEADER_H
#define HEADER_H
#include <bits/stdc++.h>
using namespace std;
template <class T,size_t S>
class Vector{
    private:
        T *arr;
        void increase_capacity();
        int size;
        int capacity;
    public:
        typedef T *Iterator;
        Vector();
        Vector(const T (&new_arr)[S]);
        ~Vector();
        void push_back(T);
        void insert(Iterator, T);
        void clear();
        void erase(Iterator);
        void erase(Iterator,Iterator);
        bool empty();
        int Size();
        int Capacity();
        int resize();
        T pop_back();
        T &operator[](int);
        Iterator begin();
        Iterator end();
};
#endif