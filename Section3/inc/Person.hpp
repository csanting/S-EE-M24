#include <string>
#include <iostream>

using namespace std;

// Custom Person class
class Person {
    public:
        Person();
	Person(string name, int age, string cake_or_cookie);

	// Get
	string getName();	
	int getAge();
	string getCake_or_cookie();

	// Set
	void setName(string name);
	void setAge(int age);
	void setCake_or_cookie(string cake_or_cookie);

        void printPerson();
	bool comparePerson(Person otherPerson);
    private:
        string name;
	int age;
	string cake_or_cookie;
};
