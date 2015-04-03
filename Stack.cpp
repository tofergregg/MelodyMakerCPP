/*
 * Stack.cpp
 *
 *  Created on: Mar 20, 2015
 *      Author: Chris Gregg
 */

#include <iostream>
#include "Stack.h"

Stack::Stack() {
        stack_array = new Note[STACK_INIT_CAPACITY];
        capacity = STACK_INIT_CAPACITY;
        size = 0; // no elements yet
        _top = 0;
}

// copy constructor
Stack::Stack(const Stack &source) { // copy constructor
        size = source.size; // set size
        capacity = source.capacity; // set capacity
        // create new array and copy
        stack_array = new Note[capacity];
        for (int i=0;i<size;i++){
                stack_array[i]=source.stack_array[i];
        }
        _top = source._top;
}

// assignment overload
Stack &Stack::operator=(const Stack &source)
{
        if (this != &source) { // check for alias
                delete [] stack_array; // must delete original stack_array
                size = source.size; // set size
                capacity = source.capacity; // set capacity
                // create new array and copy
                stack_array = new Note[capacity];
                for (int i=0;i<size;i++){
                        stack_array[i]=source.stack_array[i];
                }
                _top = source._top; // set top for new Stack
        }
        return *this;
}

Stack::~Stack() {
        delete [] stack_array;
}

// enStack a Note onto at the back of the Stack
void Stack::push(Note s) {
        // check if we need to expand
        if (size==capacity) {
                expand();
        }
        // _top always points to the next available element
        // place in Stack
        
        stack_array[_top]=s;
        _top++;
        size++; // just added an element
}

Note Stack::top() {
        return stack_array[_top-1];
}

// deStack a Note from the front of the Stack
Note Stack::pop() {
        // _top always points to the next available item
        // assume Stack is not empty
        _top--;
        Note s = stack_array[_top]; // the front of the Stack
        size--;
        return s;
}

// returns true if there are elements in the
// stack, false otherwise
bool Stack::isEmpty() {
        return size==0;
}

// expand the circular Stack
void Stack::expand() {
        // a bit trickier than regular dynamic arra
        // expanding -- we must ensure that we move the
        // circular array properly to the front of the new Stack
        
        // 1. create new array with twice the capacity
        Note *new_stack_array = new Note[capacity*2];
        
        // 2. copy the elements to the beginning of the new Stack
        for (int i=0;i<size;i++) {
                new_stack_array[i] = stack_array[i];
        }
        
        // 3. delete old Stack
        delete [] stack_array;
        
        // 4. set stack_array to new Stack
        stack_array = new_stack_array;
        
        // 5. update capacity
        capacity*=2;
        
}

