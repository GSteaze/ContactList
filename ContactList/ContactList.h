#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Contact.h"

using namespace std;

class ContactList
{
private:
	vector<Contact> _contactList;

public:
	ContactList();
	~ContactList();

	bool compareContact(Contact &a, Contact &b);


	void orderContactList();

	void fillFromFile(string);

	vector<Contact> searchByLastName(string);

	vector<Contact> searchByFirstName(string);

	vector<Contact> searchByCity(string);

	vector<Contact> searchByBirthMonth(int);

	vector<Contact> searchByBirthYear(int);

	vector<Contact> searchByAge(int);

	void deleteContact(string);

	void deleteAllContacts();

	void addContact();

	bool isEmpty();

	void testCode();

};

