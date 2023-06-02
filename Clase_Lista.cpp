// Clase_Lista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Daniel Alejandro Medina Vazquez

#include <iostream>
#include <string>
using namespace std;


class Node {

private:

	int Data;

	Node* Next;

	Node* Prev;

public:

	Node(int data) {

		Data = data;

		Next = nullptr;

		Prev = nullptr;

	}

	void setNext(Node* next) {

		Next = next;

	}


	void setPrev(Node* prev) {

		Prev = prev;

	}


	void setData(int data) {

		Data = data;

	}


	int getData() {

		return Data;

	}

	Node* getNext() {

		return Next;

	}

	Node* getPrev() {

		return Prev;

	}

};

class List {

private:

	Node* Head;

public:

	List() {

		Head = NULL;

	}


	Node* getPosition(int position) {

		Node* currentNode = Head;

		int c;

		for (c = 0; c < position; c++) {

			currentNode = currentNode->getNext();

		}

		return currentNode;

	}


	void insertHead(int data) {

		Node* newNode = new Node(data);

		if (Head == NULL) {

			Head = newNode;

		}

		else {

			newNode->setNext(Head);

			Head = newNode;

		}

	}


	void insertCustom(int position, int data) {

		Node* newNode = new Node(data);

		if (position == NULL) {

			newNode->setNext(Head);

		}

		else {

			Node* previousNode = getPosition(position - 2);

			Node* currentNode = previousNode->getNext();

			newNode->setNext(currentNode);

			previousNode->setNext(newNode);

		}

	}


	void insertTail(int data) {

		Node* newNode = new Node(data);

		if (Head == NULL) {

			Head = newNode;

		}

		else {

			Node* currentNode = Head;

			while (currentNode->getNext() != NULL) {

				currentNode = currentNode->getNext();

			}

			currentNode->setNext(newNode);

		}

	}


	void printList() {

		Node* currentNode = Head;

		while (currentNode != NULL) {

			cout << currentNode->getData() << ", ";

			currentNode = currentNode->getNext();

		}

		cout << endl;

	}


	void deleteNode(int position) {

		Node* prevNode = getPosition(position - 2);

		Node* deleteNode = prevNode->getNext();

		prevNode->setNext(deleteNode->getNext());



		delete deleteNode;

	}


	~List() {

		Node* currentNode = Head;

		while (currentNode != NULL) {

			Node* nextNode = currentNode->getNext();

			delete currentNode;

			currentNode = nextNode;

		}

	}


};

class Stack {

private:

	Node* Top;

public:

	Stack() {

		Top = NULL;

	}


	bool isEmpty() {

		if (Top == nullptr) return true;

		else return false;

	}



	void push(int data) {

		if (Top == nullptr) {

			Node* newNode = new Node(data);

			Top = newNode;

		}

		else {

			Node* newNode = new Node(data);

			Top->setNext(newNode);

			newNode->setPrev(Top);

			Top = newNode;

		}


	}


	int pop() {

		if (isEmpty()) {

			cout << "Stack underflow" << endl;

			return 0;

		}

		else {

			int topValue = Top->getData();

			Node* tempNode = Top;

			Top = Top->getPrev();

			delete(tempNode);

			return topValue;

		}

	}


	int count() {

		if (isEmpty()) {

			cout << "Stack underflow" << endl;

			return 0;

		}

		else {

			int counter = 1;

			Node* tempNode = Top;

			while (tempNode->getPrev() != nullptr) {

				counter++;

				tempNode = tempNode->getPrev();

			}

			return counter;

		}

	}


	int peek() {

		return Top->getData();

	}


	void change(int position, int data) {

		if (position != 0) {

			if (isEmpty()) {

				cout << "Stack underflow";

			}

			else {

				int counter = 1;

				Node* tempNode = Top;

				while (counter != position) {

					if (tempNode->getPrev() == nullptr) {

						cout << "There's no position " << position << " Maybe try a different number" << endl;

						return;

					}

					tempNode = tempNode->getPrev();

					counter++;

				}

				tempNode->setData(data);

			}

		}

		else {

			cout << "Please enter a valid number";

		}

	}


	void display() {

		Node* tempNode = Top;

		cout << "Stack contains: " << endl;

		while (tempNode != nullptr) {

			cout << tempNode->getData() << endl;

			tempNode = tempNode->getPrev();

		}

	}


};

class Queue {

private:

	Node* Front;

	Node* Rear;

public:

	Queue() {

		Front = NULL;

		Rear = NULL;

	}

	bool isEmpty() {

		if (Front == NULL) return true;

		else return false;

	}


	void enqueue(int data) {

		if (isEmpty()) {

			Node* newNode = new Node(data);

			Front = newNode;

			Rear = newNode;

		}

		else {

			Node* newNode = new Node(data);

			Rear->setPrev(newNode);

			Rear = newNode;


		}

	}



	int dequeue() {

		if (isEmpty()) {

			cout << "Queue is empty" << endl;

			return 0;

		}

		else {

			int value;

			Node* tempNode = Front;

			value = Front->getData();

			Front = Front->getPrev();

			delete tempNode;

			return value;

		}

	}


	int count() {

		if (isEmpty()) {

			cout << "Queue is empty" << endl;

			return 0;

		}

		else {

			int counter = 1;

			Node* tempNode = Front;

			while (tempNode->getPrev() != nullptr) {

				counter++;

				tempNode = tempNode->getPrev();

			}

			return counter;

		}

	}


	void display() {

		if (isEmpty()) cout << "Queue is empty" << endl;

		else {

			Node* tempNode = Front;

			cout << "Queue contains: " << endl;

			while (tempNode != nullptr) {

				cout << tempNode->getData() << endl;

				tempNode = tempNode->getPrev();

			}

		}

	}

};


int main()

{

	List list;

	list.insertHead(1);

	list.insertTail(2);

	list.insertTail(3);

	list.deleteNode(3);

	list.printList();


	return 0;

}