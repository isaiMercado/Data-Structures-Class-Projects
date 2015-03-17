/* 
 * File:   Stack.h
 * Author: misaie
 *
 * Created on May 19, 2014, 9:26 AM
 */

#ifndef STACK_H
#define	STACK_H
#include "LinkedList.h"


class Stack {
public:
    Stack();
    ~Stack();
    
    void pop();
    void push(int ID);
    int top();
    bool empty();
    bool contains(int ID);
    int size();
    
private:
    
    LinkedList<int> cont; 

};

#endif	/* STACK_H */

