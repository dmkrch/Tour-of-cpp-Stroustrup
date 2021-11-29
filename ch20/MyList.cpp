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
    MyList() {
        // not so clear example. Just to begin() and end() work
        firstNode = new ListNode<T>();
        firstNode->prev = nullptr;
        firstNode->succ = nullptr;
        firstNode->val = T();
        lastNode = firstNode;
    }
    // ops: insert, erase, push_back, push_front, pop_front, pop_back
    class iterator;

    iterator begin() { return iterator(firstNode); }
    iterator end() { return iterator(lastNode); }

    iterator insert(iterator p, const T& v);    // insert v element after element that being pointed as iterator p
    iterator erase(iterator p);     // remove element that iterator p points to
    void push_back(const T& v);    // add to back of list
    void push_front(const T& v);    // add to front of list
    void pop_front();   // remove first element
    void pop_back();    // remove last element

    T& front(); // first element
    T& back();  // last element

private:    
    ListNode<T>* firstNode;
    ListNode<T>* lastNode;
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

    bool operator!=(const iterator& it) const {
        return it.currentNode!=currentNode;
    }

private:
    ListNode<T>* currentNode;
};



int main() {
    MyList<int> list1;

    // now we can do:
    for (MyList<int>::iterator p = list1.begin(); p != list1.end(); ++p)
        std::cout << *p << std::endl;

    // or use auto for iterators to avoid repeating code:
    for (auto p = list1.begin(); p != list1.end(); ++p)
        std::cout << *p << std::endl;

    // and we can use this: (begin(), end() ++, !=, ==, *  ops are required for iterators)
    for (double x : list1) 
        std::cout << x << std::endl;

    return 0;
}