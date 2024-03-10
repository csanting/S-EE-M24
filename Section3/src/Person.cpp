#include "../inc/Person.hpp"

Person::Person():
name(""),
age(0),
cake_or_cookie("Cookie") {

}

Person::Person(string name, int age, string cake_or_cookie) {
    this->name = name;
    this->age = age;
    this->cake_or_cookie = cake_or_cookie;
}

string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}

string Person::getCake_or_cookie() {
    return this->cake_or_cookie;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setCake_or_cookie(string cake_or_cookie) {
    if (!cake_or_cookie.compare("Cake") || !cake_or_cookie.compare("Cookie")) {
        this->cake_or_cookie = cake_or_cookie;
    }
    else {
        // I like cookies better so default to Cookie if invalid string is passed
	this->cake_or_cookie = "Cookie";
    }
}

void Person::printPerson() {
    cout << name << ", " << age << ", " << cake_or_cookie << endl;
}

bool Person::comparePerson(Person otherPerson) {
    if (this->getCake_or_cookie().compare(otherPerson.getCake_or_cookie())) {
	return false;
    }
    if (this->getAge() != otherPerson.getAge()) {
        return false;
    }
    if (this->getName().compare(otherPerson.getName())) {
        return false;
    }
    return true;
}
