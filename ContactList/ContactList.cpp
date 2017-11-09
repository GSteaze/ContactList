#include "ContactList.h"



bool ContactList::compareContact(Contact a, Contact b)
{
	if (a.getFirstName()[0] < b.getFirstName()[0]) {
		return true;
	}
	else if (a.getFirstName()[0] == (b.getFirstName()[0])) {
		if (a.getLastName()[0] < b.getLastName()[0]) {
			return true;
		}
	}
	return false;
}

ContactList::ContactList()
{
}


ContactList::~ContactList()
{
}

void ContactList::orderContactList()
{
}

void ContactList::fillFromFile()
{
}

void ContactList::searchByLastName()
{
}

void ContactList::searchByFirstName()
{
}

void ContactList::searchByCity()
{
}

void ContactList::deleteContact()
{
}

void ContactList::deleteAllContacts()
{
}

void ContactList::addContact()
{
}
