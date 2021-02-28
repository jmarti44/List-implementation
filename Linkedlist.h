#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef int element_type;
class Linkedlist{
    private:
    struct Node
    {
        // default constructor is available
        // may introduce your own constructor if you like
        element_type elem;  // Data
        Node * next;        // Pointer to the next node in the chain
        Node * prev;        // Pointer to the previous node in the chain
    };
    Node * head;
    Node * tail;
    Node * current;
  
    
    public:
  
    Linkedlist();
    ~Linkedlist();
    typedef element_type& reference;
    typedef const element_type& const_reference;  
    explicit Linkedlist(unsigned int n);

    
    bool empty() const;
    void clear ();
    reference back();
    const_reference back() const;
    reference front ();
    const_reference front() const;

    Linkedlist& operator = (const Linkedlist&list);

    void pop_back();
    void pop_front();
    void push_back (const element_type& x);
    void push_front (const element_type& x);
    void sort();
    void check() const;
    void rcheck() const;
    void insert( unsigned int pos, const element_type& x);
    void erase(unsigned int pos);
    
};

#endif



    

