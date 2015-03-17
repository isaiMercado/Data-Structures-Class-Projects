/* 
 * File:   Deque.h
 * Author: misaie
 *
 * Created on May 19, 2014, 9:26 AM
 */

#ifndef DEQUE_H
#define	DEQUE_H
#include "LinkedList.h"

class Deque {
public:
    Deque();
    ~Deque();
    
    void pop_right();
    void pop_left();
    void push_right(int ID);
    void push_left(int ID);
    int show_right();
    int show_left();
    bool empty();
    bool contains(int ID);
    int size();
    
private:
    
    LinkedList<int> cont; 

};

#endif	/* DEQUE_H */

