#include "../inc/LinkedList.hpp"

LinkedList::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->listLength = 0;
}

// Append new Person to list by creating new Node
void LinkedList::appendPerson(Person newPerson) {
    Node *newNode = new Node;
    newNode->data = newPerson;
    newNode->next = NULL;

    if (this->head == NULL) {
        this->head = newNode;
	this->tail = newNode;
	this->listLength = 1;
    }
    else {
        this->tail->next = newNode;
        this->tail = this->tail->next;
	this->listLength++;
    }
}

void LinkedList::appendNode(Node *newNode) {
    if (this->head == NULL) {
        this->head = newNode;
	this->tail = newNode;
	this->listLength = 1;
    }
    else {
        this->tail->next = newNode;
	this->tail = this->tail->next;
	this->listLength++;
    }

}

void LinkedList::printList() {
    Node *iterator = this->head;
    while (iterator != NULL) {
        iterator->data.printPerson();
	iterator = iterator->next;
    }
}

// Iterative MergeSort returning a copy of the original list
LinkedList LinkedList::sortList() {
    // Create a copy to work on
    LinkedList copyList = this->copyList();
    Node* copyHead = copyList.head;
    
    // Check for empty or single element lists
    if (!copyHead || !copyHead->next) {
        return copyList;
    }

    Node* startNode;
 
    // Dummy node as a convenient reference point
    Node dummyNode;
    dummyNode.next = copyHead;
    
    // Nodes to track current sub lists
    Node *leftNode, *rightNode, *currentTail;

    // Split the problem into smaller lists, increasing list size each iteration
    for (int currentSize = 1; currentSize < this->listLength; currentSize *= 2) {
        currentTail = &dummyNode;
        startNode = dummyNode.next;

        // Split lists into sub lists before sorting and merging merging
        while (startNode != NULL) {
            leftNode = startNode;
            rightNode = splitList(leftNode, currentSize);
            startNode = splitList(rightNode, currentSize);
            currentTail = mergeLists(leftNode, rightNode, currentTail);
        }
    }

    // Populate result list safely by iterating through sorted list
    LinkedList resultList;

    startNode = dummyNode.next;
    while (startNode != NULL) {
        resultList.appendPerson(startNode->data);
	startNode = startNode->next;
    }

    return resultList;
}


// Private

// Create data copy of list
LinkedList LinkedList::copyList() {
    LinkedList outputList;

    Node *currentNode = this->head;

    while (currentNode != NULL) {
        Node *newNode = new Node;
	newNode->data = currentNode->data;
	newNode->next = NULL;

	outputList.appendNode(newNode);

	currentNode = currentNode->next;
    }
    return outputList;    
}

// Split a list into two parts according to splitLength index
Node* LinkedList::splitList(Node* startingNode, int splitLength) {
    // Iterate to the split point
    while (splitLength > 1 && startingNode) {
        splitLength--;
        startingNode = startingNode->next;
    }
    if (!startingNode) {
        return NULL;
    }

    // Get pointer to node after split point
    Node* newStartingNode = startingNode->next;
    startingNode->next = NULL;

    return newStartingNode;
}

// Merge lists and return the last node after merge
Node* LinkedList::mergeLists(Node* leftNode, Node* rightNode, Node* startingNode) {
    Node* currentNode = startingNode;

    // Iterate through left and right list according to age comparison until reaching end of one list
    while (leftNode != NULL && rightNode != NULL) {
        if (leftNode->data.getAge() < rightNode->data.getAge()) {
            currentNode->next = leftNode; 
	    leftNode = leftNode->next;
        } 
	else {
            currentNode->next = rightNode; 
	    rightNode = rightNode->next;
        }
        currentNode = currentNode->next;
    }

    // Append remaining items from longer list
    if (leftNode != NULL) {
        currentNode->next = leftNode;
    }
    else {
        currentNode->next = rightNode;
    }

    // Get the end of the list to return
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    return currentNode;
}
