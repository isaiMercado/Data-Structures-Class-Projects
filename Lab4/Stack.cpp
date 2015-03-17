/* 
 * File:   Stack.cpp
 * Author: misaie
 * 
 * Created on May 19, 2014, 9:26 AM
 */

#include "Stack.h"



Stack::Stack() {
}

Stack::~Stack() {
}

    void Stack::pop()
    {
        int a = cont.at(0);
        cont.remove(a);
    }

    void Stack::push(int ID)
    {
        cont.insertHead(ID);
    
    }
    
    int Stack::top()
    {
        return cont.at(0);
    }
    
    bool Stack::empty()
    {
        if (cont.size() == 0 ) { return true;}
        else { return false; }
    }
    
    bool Stack::contains(int ID)
    {
        for(int i = 0; i < cont.size() ; i++)
        {
            if ( ID == cont.at(i)) { return true; }
        }
        return false;
    }
    
    int Stack::size()
    {
        return cont.size();
    }

