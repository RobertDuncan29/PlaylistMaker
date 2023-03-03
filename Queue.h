#pragma once
#include "LinkedList.h"

using namespace std;

template <class T>
class Queue : public LinkedList<T> {
protected:
	int queueSize = 0;
public:
	Queue<T>() : LinkedList<T>() {
		// cout << "default constructor for Queue" << endl;
	}
	void enqueue(T v) {
		this->postpend_node(v);  queueSize++;
	}
	T dequeue(void) {
		if (queueSize > 0) {
			T x = this->get_head_value();
			this->delete_node_with_target_value(x);
			queueSize--;
			cout << "We went ahead and got rid of " << x << endl;
			return x;
		}
	}
};