//
//  Stack.h
//  MelodyMaker
//
//  Created by Chris Gregg on 3/20/15.
//

#ifndef __MelodyMaker__Stack__
#define __MelodyMaker__Stack__

#include <stdio.h>
#include "Note.h"

#define STACK_INIT_CAPACITY 2

class Stack {
public:
        // constructor
        Stack();
        
        // copy constructor
        Stack(const Stack &source);
        
        // assignment overload
        Stack &operator=(const Stack &source);
        
        // destructor
        ~Stack();
        
        // enStack a char onto at the back of the Stack
        void push(Note c);
        
        // deStack a char from the front of the Stack
        Note pop();
        
        // peek at the front of the Stack
        Note top();
        
        // returns true if there are elements in the
        // stack, false otherwise
        bool isEmpty();
        
private:
        Note *stack_array; // the dynamic array for the stack
        int capacity; // the capacity of the stack
        int size; // how many characters there are in the stack
        int _top; // the top of the Stack
        void expand(); // expand the circular Stack
};
#endif /* defined(__MelodyMaker__Stack__) */
