/* 
 * File:   Deque.cpp
 * Author: misaie
 * 
 * Created on May 19, 2014, 9:26 AM
 */

#include "Deque.h"

Deque::Deque() {
}

Deque::~Deque() {
}

    void Deque::pop_right()
    {
        //cout << "pop_right " << cont.at(cont.size()-1) << endl;
        cont.remove(cont.at(cont.size()-1));
    }
    
    void Deque::pop_left()
    {
        //cout << "pop_left " << cont.at(0) << endl;
        cont.remove(cont.at(0));
    }

    void Deque::push_right(int ID)
    {
        //cout << "push_right " << ID << " size " << size() << endl;
        cont.insertTail(ID);  
         
    }
    
    void Deque::push_left(int ID)
    {
        //cout << "push_left " << ID << " size " << size() << endl;
        cont.insertHead(ID); 
    }
    
    int Deque::show_right()
    {
        //cout << "show_right " << cont.at(cont.size()-1) << endl;
        return cont.at(cont.size()-1);
    }
    
    int Deque::show_left()
    {
        //cout << "show_left " << cont.at(0) << endl;
        return cont.at(0);
    }
    
    bool Deque::empty()
    {
        if (cont.size() == 0 ) { return true;}
        else { return false; }
    }
    
    bool Deque::contains(int ID)
    {
        for(int i = 0; i < cont.size() ; i++)
        {
            if ( ID == cont.at(i)) { return true; }
        }
        return false;
    }
    
    int Deque::size()
    {
        return cont.size();
    }
