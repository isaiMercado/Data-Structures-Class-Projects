/* 
 * File:   Queue.cpp
 * Author: misaie
 * 
 * Created on May 19, 2014, 9:26 AM
 */

#include "Queue.h"

Queue::Queue() {
}

Queue::~Queue() {
}

    void Queue::pop()
    {
        cont.remove(cont.at(0));
    }

    void Queue::push(int ID)
    {
        cont.insertTail(ID);
    }
    
    int Queue::top()
    {
        return cont.at(0);
    }
    
    bool Queue::empty()
    {
        if (cont.size() == 0 ) { return true;}
        else { return false; }
    }
    
    bool Queue::contains(int ID)
    {
        for(int i = 0; i < cont.size() ; i++)
        {
            if ( ID == cont.at(i)) { return true; }
        }
        return false;
    }
    
    int Queue::size()
    {
        return cont.size();
    }
