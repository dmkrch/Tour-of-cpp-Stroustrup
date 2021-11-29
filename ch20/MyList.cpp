#include <iostream>


template<typename T>
struct ListNode {
    ListNode* prev; // previous element
    ListNode* succ; // next element   
    T val;  // value
};



template<typename T>
class MyList {
public:
    // ops: insert, erase, push_back, push_front, pop_front, pop_back
    class iterator;

    iterator begin();
    iterator end();

    iterator insert(iterator p, const T& v);    // insert v element after element that being pointed as iterator p
    iterator erase(iterator p);     // remove element that iterator p points to
    void push_back(const T& v);     // add to back of list
    void push_front(const T& v);    // add to front of list
    void pop_front();   // remove first element
    void pop_back();    // remove last element

    T& front(); // first element
    T& back();  // last element
};



template<typename T>
class MyList<T>::iterator {
public:
    iterator(ListNode<T>* p) : currentNode{p} {}
    // now we need to overload 4 operations: ++, --, *, ==
    // overload of ++
    iterator& operator++() {
        currentNode = currentNode->succ;
        return *this;
    }

    iterator& operator--() {
        currentNode = currentNode->prev;
        return *this;
    }

    T& operator*() {
        return currentNode->val;
    }

    bool operator==(const iterator& it) const {
        return it.currentNode==currentNode;
    }

private:
    ListNode<T>* currentNode;
};



int main() {

    return 0;
}