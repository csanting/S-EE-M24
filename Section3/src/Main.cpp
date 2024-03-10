// For testing
#include <cassert>
#include <vector>

#include "../inc/LinkedList.hpp"

// Check if 2 lists are equivalent
bool compareLists(LinkedList inputList1, LinkedList inputList2) {
    Node *list1Iterator = inputList1.head;
    Node *list2Iterator = inputList2.head;

    // Iterate through each list and compare Person
    while (list1Iterator != NULL && list2Iterator != NULL) {
        if (!list1Iterator->data.comparePerson(list2Iterator->data)) {
	    return false;
	}
	list1Iterator = list1Iterator->next;
	list2Iterator = list2Iterator->next;
    }

    // Only return true if both lists are same length
    return (list1Iterator == NULL && list2Iterator == NULL);
}

// Check the list has the expected Person entries
bool compareListContents(LinkedList inputList, vector<Person> expectedList) {
    Node *listIterator = inputList.head;

    for(size_t i = 0; i < expectedList.size(); i++) {
        if (!listIterator->data.comparePerson(expectedList[i])) {
            return false;
	}
	listIterator = listIterator->next;
    }

    // Make sure no additional entries in the list
    return (listIterator == NULL);
}

void testAddPerson() {
    LinkedList testList;

    Person person1("Adam", 25, "Cake");
    Person person2("Bill", 42, "Cake");
    Person person3("Charles", 21, "Cookie");
    Person person4("Dave", 95, "Cake");
    Person person5("Ethan", 15, "Cookie");
    Person person6("Frank", 0, "Cake");

    vector<Person> expectedList{person1, person2, person3, person4, person5, person6};

    testList.appendPerson(person1);
    testList.appendPerson(person2);
    testList.appendPerson(person3);
    testList.appendPerson(person4);
    testList.appendPerson(person5);
    testList.appendPerson(person6);

    assert(compareListContents(testList, expectedList));
    cout << "Test Add Person Passed" << endl;

}

void testAddNode() {
    LinkedList testList;

    Person person1("Adam", 25, "Cake");
    Node *node1 = new Node;
    node1->data = person1;

    Person person2("Bill", 42, "Cake");
    Node *node2 = new Node;
    node2->data = person2;

    Person person3("Charles", 21, "Cookie");
    Node *node3 = new Node;
    node3->data = person3;

    Person person4("Dave", 95, "Cake");
    Node *node4 = new Node;
    node4->data = person4;

    Person person5("Ethan", 15, "Cookie");
    Node *node5 = new Node;
    node5->data = person5;

    Person person6("Frank", 0, "Cake");
    Node *node6 = new Node;
    node6->data = person6;

    vector<Person> expectedList{person1, person2, person3, person4, person5, person6};

    testList.appendNode(node1);
    testList.appendNode(node2);
    testList.appendNode(node3);
    testList.appendNode(node4);
    testList.appendNode(node5);
    testList.appendNode(node6);

    assert(compareListContents(testList, expectedList));
    cout << "Test Add Node Passed" << endl;
}

void testSortList() {
    LinkedList baseList, sortedList, expectedList;

    Person person1("Adam", 25, "Cake");
    Person person2("Bill", 42, "Cake");
    Person person3("Charles", 21, "Cookie");
    Person person4("Dave", 95, "Cake");
    Person person5("Ethian", 15, "Cookie");
    Person person6("Frank", 0, "Cake");
    
    baseList.appendPerson(person1);
    baseList.appendPerson(person2);
    baseList.appendPerson(person3);
    baseList.appendPerson(person4);
    baseList.appendPerson(person5);
    baseList.appendPerson(person6);

    expectedList.appendPerson(person6);
    expectedList.appendPerson(person5);
    expectedList.appendPerson(person3);
    expectedList.appendPerson(person1);
    expectedList.appendPerson(person2);
    expectedList.appendPerson(person4);
    //expectedList.printList();

    sortedList = baseList.sortList();
    //sortedList.printList();

    assert(compareLists(sortedList, expectedList));
    cout << "Test Sort List Passed" << endl;
}

int main() {
    try {
        testAddPerson();
	testAddNode();
	testSortList();
    } 
    catch (exception &e) {
        cout << "Failed Test: " << e.what() << endl;
    }

    return 0;
}
