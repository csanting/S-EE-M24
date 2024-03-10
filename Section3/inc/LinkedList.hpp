#include "Person.hpp"

struct Node{
    Person data;
    struct Node *next;
};


class LinkedList {
    public:
        LinkedList();

	void appendPerson(Person newPerson);
	void appendNode(Node *newNode);
	void printList();
	LinkedList sortList();

        Node *head;
	Node *tail;

    private:
        int listLength;	

        LinkedList copyList();
	
	Node* splitList(Node* head, int n);
	Node* mergeLists(Node* l1, Node* l2, Node* head);
};
