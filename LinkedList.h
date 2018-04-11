#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

template <class T>
class LinkedList
{
  template <typename V>
  friend ostream& operator<<(ostream&, LinkedList<V>&);

  
  class Node {
	   friend class LinkedList<T>;
	   private:
	   T* data;
       Node* next;
  };

  public:
    LinkedList();
    ~LinkedList();
    int  getSize() const;

	LinkedList<T>& operator+=(T*);
	LinkedList<T>& operator-=(T*);
	T* operator[](int) const;

  private:
    Node *head;
};

//Linked list Template Constructor
template <class T>
LinkedList<T>::LinkedList()
	:head(0)
{
  
}

//Linked list Template Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    Node *currNode, *nextNode;

	currNode = head;

	 while (currNode != 0) {
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	  }
}

/*Function: getSize()
  Purpose: Returns the size of the Linked list*/
template <class T>
int LinkedList<T>::getSize() const
{
	if (head == 0)
		return 0;
	else {	
		Node *currNode;

		currNode = head;

		int size = 0;
		while (currNode != 0) {
			currNode = currNode->next;
			size++;
		}
		return size;
	}
}

/*Function: +=
  in: Location of general object, object
  out: Modified Linked list
  Purpose: Adds the object to the Linked list*/
template <class T>
LinkedList<T>& LinkedList<T>::operator+=(T *object)
{
	Node *currNode = this->head;

	Node* tmpNode = new Node;
    tmpNode->data = object;
    tmpNode->next = 0;

	 if (head == 0) 
		head = tmpNode;
	  else { 
		  Node *currNode, *prevNode = 0;

		  currNode = head;

		  while (currNode != 0) { 
			if (*(currNode->data) > *(tmpNode->data)) 
			  break;
			prevNode = currNode;
			currNode = currNode->next;
		  }

			 if (prevNode != 0) 
			prevNode->next = tmpNode;
		 
			else 
				 head = tmpNode;
		  tmpNode->next  = currNode;
	   }
	return *this;
}

/*Function: -=
  in: Location of general object, object
  out: Modified Linkedlist
  Purpose: Adds the object to the Linked list*/
template <class T>
LinkedList<T>& LinkedList<T>::operator-=(T *object)
{ 
 Node *currNode, *prevNode;

  prevNode = 0;
  currNode = this->head;

  while (currNode != 0) {
    if ((currNode->data == object))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
	return *this;
  
 

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode->data;
  delete currNode;

  return *this;
}

/*Function: []
  in: Integer index
  Purpose: returns the object in the list at the indicated index position*/
template <class T>
T* LinkedList<T>::operator[](int index) const {
	Node *currNode = this->head;
	int i = 0, flag = 0;

	while (currNode != 0) {
		if (i == index) {
			flag = 1;
			break;
		}
		i++;
		currNode = currNode->next;
	}
	if (flag == 0)
		return 0;
	else
		return currNode->data;
}

/*Function: <<
  in: Reference to outstream output and templated Linked list
  out: Modified output
  Purpose: Contains each object's data in a string format by calling the output operator by the Linked list itself*/
template <class T>
ostream& operator<<(ostream& output, LinkedList<T>& list) {
	int i = 0, num = 0;

	while (list[i] != 0) {	
 	 	output << *(list[i]);
		i++;
	}

  	output << endl;

  return output;
}

#endif

