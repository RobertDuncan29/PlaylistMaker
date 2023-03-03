#pragma once

template <class T>
class ListNode {
protected:
	ListNode<T>* nextNode;
	ListNode<T>* previousNode; 
	MyString key;
	T value;
public:
	ListNode(T v, MyString k = " ") { 
		nextNode = NULL;
		previousNode = NULL; 
		key = k;
		value = v;
	}
	ListNode<T>* ptrToNextNode(void) {
		return nextNode;
	}
	// lines 22 - 24 are each separate get_x functions so that the output
	// will properly display what aspect of the band is being printed to the user
	MyString& get_band(void) { cout << "Band: "; return key; } 
	MyString& get_album(void) { cout << "Album: "; return key; }
	MyString& get_songs(void) { cout << "Track: "; return key; }
	MyString& get_key(void) { return key; }
	T& get_value(void) { return value; }
	void set_nextNode(ListNode<T>* p)
	{
		if (p == NULL) { cout << "setting nextNode pointer to NULL" << endl; }
		nextNode = p;
	}
};

template <class T>
class LinkedList {
protected:
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	LinkedList<T>();
	ListNode<T>* ptrToHeadNode(void) { return head; }
	void postpend_node(T v, MyString k = ""); 
	void print_bands(void);
	void print_albums(void);
	void print_songs(void);
	void print(void);
	int delete_node_with_target_value(T v);
	ListNode<T>* return_head(void) { return head; }
	ListNode<T>* return_tail(void) { return tail; }
	T get_head_value(void) { return head->get_value(); }
	T get_tail_value(void) { return tail->get_value(); }
};

template <class T>
LinkedList<T>::LinkedList() {
	head = NULL; 
	tail = NULL; 
}

template <class T>
void LinkedList<T>::postpend_node(T v, MyString k) {
	ListNode<T>* p = new ListNode<T>(v, k);
	if (p == NULL) { cout << "error: new node pointer is NULL" << endl; }
	if (head == NULL) { 
		head = p;
		tail = p;
	}
	else {
		tail->set_nextNode(p);
		tail = p;
	}
}
// basic print member function needed for class Queue
template <class T>
void LinkedList<T>::print(void) {
	cout << " " << endl;
	ListNode<T>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->get_value() << endl;
		ptr = ptr->ptrToNextNode();
	}
}
// print member function to print the bands
template <class T>
void LinkedList<T>::print_bands(void) {
	cout << " " << endl;
	ListNode<T>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->get_band() << " | " << ptr->get_value() << endl;
		ptr = ptr->ptrToNextNode();
	}
}
// print member function to print the albums for a given band
template <class T>
void LinkedList<T>::print_albums(void) {
	cout << " " << endl;
	ListNode<T>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->get_album() << " | " << ptr->get_value() << endl;
		ptr = ptr->ptrToNextNode();
	}
}
// print member function to print the songs for a given album
template <class T>
void LinkedList<T>::print_songs(void) {
	cout << " " << endl;
	ListNode<T>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->get_songs() << " | " << ptr->get_value() << endl;
		ptr = ptr->ptrToNextNode();
	}
}
// Used for member function of Class Queue 'Dequeue', to remove the front of the queue
// and to reassign the order of the items in the queue and ensure the pointers are pointing
// in the necessary direction
template <class T>
int LinkedList<T>::delete_node_with_target_value(T v) {
	ListNode<T>* ptr = head;
	ListNode<T>* prev_ptr = head;
	if (head->get_value() == v) { 
		head = head->ptrToNextNode(); 
		return 1;
	}
	else {  
		while (ptr != NULL && (ptr->get_value() != v)) {
			prev_ptr = ptr;
			ptr = ptr->ptrToNextNode();
		}
		if (ptr == NULL) return 0; 
		else { 
			prev_ptr->set_nextNode(ptr->ptrToNextNode());
			return 1;  
		}
	}
	return 0;
}

template <class T>
ostream& operator <<(ostream& strm, LinkedList<T> LL) {
	LL.print();
	return strm;
}
