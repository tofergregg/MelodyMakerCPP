/*
 * Queue.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: Chris Gregg
 */

#include <iostream>
#include "Queue.h"

Queue::Queue() {
	queue_array = new Note[QUEUE_INIT_CAPACITY];
	capacity = QUEUE_INIT_CAPACITY;
	size = 0; // no elements yet
	front = 0;
	back = 0;
}

// copy constructor
Queue::Queue(const Queue &source) { // copy constructor
	size = source.size; // set size
	capacity = source.capacity; // set capacity
	// create new array and copy
	queue_array = new Note[capacity];
	for (int i=0;i<size;i++){
		queue_array[i]=source.queue_array[(source.front + i) % capacity];
	}
	front = 0; // set front for new queue
	back = size; // set back for new queue
}

// assignment overload
Queue &Queue::operator=(const Queue &source)
{
	if (this != &source) { // check for alias
		delete [] queue_array; // must delete original queue_array
		size = source.size; // set size
		capacity = source.capacity; // set capacity
		// create new array and copy
		queue_array = new Note[capacity];
		for (int i=0;i<size;i++){
			queue_array[i]=source.queue_array[(source.front + i) % capacity];
		}
		front = 0; // set front for new queue
		back = size; // set back for new queue
	}
	return *this;
}

Queue::~Queue() {
	delete [] queue_array;
}

// enqueue a Note onto at the back of the queue
void Queue::enqueue(Note s) {
	// check if we need to expand
	if (size==capacity) {
		expand();
	}
	// back always points to the next available element
	// place in queue

	queue_array[back]=s;
	back++;
	if (back==capacity) back=0; // wrap around
	size++; // just added an element
}

Note Queue::peek() {
        return queue_array[front];
}

// dequeue a Note from the front of the queue
Note Queue::dequeue() {
	// front always points to the first item in the queue
	// assume queue is not empty
	Note s = queue_array[front]; // the front of the queue
	front++;
	if (front==capacity) front = 0; // wrap around
	size--;
	return s;
}

// returns true if there are elements in the
// stack, false otherwise
bool Queue::isEmpty() {
	return size==0;
}

// expand the circular queue
void Queue::expand() {
	// a bit trickier than regular dynamic arra
	// expanding -- we must ensure that we move the
	// circular array properly to the front of the new queue

	// 1. create new array with twice the capacity
	Note *new_queue_array = new Note[capacity*2];

	// 2. copy the elements to the beginning of the new queue
	for (int i=0;i<size;i++) {
		new_queue_array[i] = queue_array[(i+front)%capacity];
	}

	// 3. delete old queue
	delete [] queue_array;

	// 4. set queue_array to new queue
	queue_array = new_queue_array;

	// 5. reset front and back
	front = 0;
	back = size;

	// 6. update capacity
	capacity*=2;

}

