/*
 * Queue.h
 *
 *  Created on: Sep 21, 2014
 *      Author: Chris Gregg
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Note.h"

#define QUEUE_INIT_CAPACITY 2

class Queue {
public:
	// constructor
	Queue();

	// copy constructor
	Queue(const Queue &source);

	// assignment overload
	Queue &operator=(const Queue &source);

	// destructor
	~Queue();

	// enqueue a char onto at the back of the queue
	void enqueue(Note c);

	// dequeue a char from the front of the queue
	Note dequeue();
        
        // peek at the front of the queue
        Note peek();

	// returns true if there are elements in the
	// stack, false otherwise
	bool isEmpty();

private:
	Note *queue_array; // the dynamic array for the stack
	int capacity; // the capacity of the stack
	int size; // how many characters there are in the stack
	int front; // the front of the queue
	int back;  // the back of the queue
	void expand(); // expand the circular queue
};

#endif /* QUEUE_H_ */
