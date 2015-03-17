/* 
 * File:   Queue.h
 * Author: misaie
 *
 * Created on May 19, 2014, 9:26 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H
#include "LinkedList.h"


class Queue {
public:
    Queue();
    ~Queue();
    
    void pop();
    void push(int ID);
    int top();
    bool empty();
    bool contains(int ID);
    int size();
    
private:
    
    LinkedList<int> cont; 

};

#endif	/* QUEUE_H */

