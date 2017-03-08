// shiyan1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

template<class T>
class Node {
		//friend class Singlylist {};
public:
	T data;
	Node<T> *next;
	Node(T data, Node<T>*next = NULL) {
		this->data = data;
		this->next = next;

	}
};
template<class T>
class Singlylist {
public:
	Node<T> *head;
	Singlylist(T values[], int n);
	~Singlylist();
	int count();
	void replaceFirst(T key, T x);
	void replaceALL(T key, T x);
	void removeALL();
	Node<T>*first();
	Node<T>*next(Node<T> *p);
	Node<T>*previous(Node<T> *p);
	Node<T>*last();
	bool isSorted(bool asc = true);
	T max(Singlylist<T> &list);
	void reverse(Singlylist<T> &list);
	Singlylist<T> sub(int i, int n);
	bool contain(Singlylist<T> &list);
	
};
template<class T>
Singlylist<T>::Singlylist(T values[], int n) {
	this->head = new Node<T>();
	Node<T> *rear = this->head;
	for (int i = 0; i<n; i++) {
		rear->next = new Node<T>(values[i]);
		rear = rear->next;
	}
}
template<class T>
Singlylist<T>::~Singlylist() {
	this->removeALL();
	delete this->head;
}
template<class T>
int Singlylist<T>::count() {
	int i = 1;
	for (Node<T> *p = this->head; p->next != NULL; p = p->next)i++;
	return i;
}
template<class T>
void Singlylist<T>::removeALL() {
	for (Node<T> *p = this->head; p->next != NULL; p = p->next) {
		delete p->data; delete p->next;
		
	}
	head->next = NULL;
}
template<class T>
void Singlylist<T>::replaceFirst(T key, T x) {
	for (Node<T> *p = this->head; p->next != NULL; p = p->next) {
		if (p->data == key)p->data = x;
		break;
	}
}
template<class T>
void Singlylist<T>::replaceALL(T key, T x) {
	for (Node<T> *p = this->head; p->next != NULL; p = p->next) {
		if (p->data == key)p->data = x;
	}
}
template<class T>
Node<T>*Singlylist<T>::first() {
	return Node<T> *p = this->head;
};
template<class T>
Node<T>*Singlylist<T>::next(Node<T> *p) {
	for (Node<T>*q = this->head; q->next != NULL; q = q->next) {
		if (q == p)return q->next;
	}
}
template<class T>
Node<T>*Singlylist<T>::previous(Node<T> *p) {
	Node<T>*q = this->head; 
	while(q->data!=NULL){
		if (q->next == p) { return q; }
		else q = q->next;
	}
}
template<class T>
Node<T>*Singlylist<T>::last() {
	for (Node<T> *p = this->head; p->next != NULL; p = p->next)return p->next;
}
template<class T>
bool Singlylist<T>::isSorted(bool asc = true) {
	int i = 0, j = 0;
	for (Node<T> *p = this->head; p-> != NULL; p = p->next) {
		if (p->data >= p->next->data)i++;
		if (p->data < p->next->data) n++;
		if (i == this.count() || n == this.count())return asc;
		else return asc = false;

	}
}
template<class T>
T Singlylist<T>::max(Singlylist<T> &list) {
	Node<T> *p = this->head->next;
	T max = p->data;
	for (p->next; p->next != NULL; p = p->next) {
		if (p->data > max)max = p->data;
	}
	return max;
	
	}
template<class T>
void Singlylist<T>::reverse(Singlylist<T> &list) {
	Node<T> *p = this->head->next, *front = NULL;
	while (p != NULL) { 
		Node<T> *succ = p->next;
		p->next = front;
		front = p;
		p = succ;
	}
	this->head->next = front;

}
template<class T>
Singlylist<T> Singlylist<T>::sub(int i, int n) {
	T a[n + 1] = {};
	Singlylist<T> list(a, n);
	int m = this.count();
	Node<T> *p = this->head;
	Node<T> *q = list->head;
	for (int j = 2; j <= i; j++) p = p->next;
	for (int k = i; k < i + n - 1; k++) {
		q->next = p->next;
		p = p->next;
		q = q->next;
	}
	return list;
	
}
template<class T>
bool Singlylist<T>::contain(Singlylist<T> &list) {
	Node<T> *p = list.head;
	Node<T> *q = this.head;
	int n = list.count(), j = 0;
	for (int i = 1; i <= n; i++) {
		if (p == q) { p = p->next; q = q->next;j++ }
		else break;
	}
	if (j == n)return true;
	else return false;
}




int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Singlylist<int>list(a, 10);
	int b=list.count();
	
    return 0;
}

