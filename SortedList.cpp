
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = 0;  // 0
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {

    return false;
}

template<class T>
void SortedList<T>::AddItem(T item) {

    for (int i = 0; i < length; i++) {
        if (info[i] > item) {

            //slide over all elements
            for (int j = length; j != i+1; j--) {
                info[j] = info[j-1];
            }
            info[i] = item;
            length++;
            return;
        }
    }

}

template<class T>
void SortedList<T>::DeleteItem(T item) {

    for (int i = 0; i < length; i++) {
        if (info[i] == item) {

            //slide over all elements
            for (int j = i+1; j < length; j++) {
                info[j] = info[j-1];
            }
            length--;
            return;
        }
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

