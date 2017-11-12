#include "TestCode.h"



TestCode::TestCode()
{
	
}


TestCode::~TestCode()
{
}

void TestCode::testContact()
{
	cout << endl << "Testing Contact Class : " << endl << endl;

	Contact testContact = Contact("1,male,Mr.,Hugo,L,Casey,3867 Hillcrest Circle,Rockford,MN,55373,HugoLCasey@dayrep.com,6/5/1990");
	cout << "toString : " << testContact.toString() << endl;
	cout << "Gender : " << testContact.getGender() << endl;
	cout << "Title : " << testContact.getTitle() << endl;
	cout << "First Name : " << testContact.getFirstName() << endl;
	cout << "Middle Initial : " << testContact.getMiddleInitial() << endl;
	cout << "Last Name : " << testContact.getLastName() << endl;
	cout << "Street Address : " << testContact.getStreetAddress() << endl;
	cout << "City : " << testContact.getCity() << endl;
	cout << "State : " << testContact.getState() << endl;
	cout << "Zip Code : " << testContact.getZipCode() << endl;
	cout << "Email Address : " << testContact.getEmailAddress() << endl;
	cout << "Birthday : " << testContact.getBirthday() << endl;
}

void TestCode::testContactList()
{
	cout << endl << "Testing ContactList class : " << endl << endl;

	ContactList testContactList = ContactList();
	cout << "Is Empty : " << testContactList.isEmpty() << endl;
	testContactList.fillFromFile("TestFile.csv");
	cout << "Is Empty : " << testContactList.isEmpty() << endl;

	testContactList.testCode();

	cout << endl;
	testContactList.deleteContactByLastName("Casey");

	testContactList.testCode();

	//vector<Contact> testResults = testContactList.searchByLastName("Casey");
	//for (vector<Contact>::iterator it = testResults.begin(); it != testResults.end(); it++) {
	//	cout << it->toString() << endl;
	//	cout << it->getGender() << endl;
	//	cout << it->getBirthday() << endl;
	//}
	//testContactList.deleteContact("1, male, Mr., Hugo, L, Casey, 3867 Hillcrest Circle, Rockford, MN, 55373, HugoLCasey@dayrep.com, 6 / 5 / 1990");
	//testContactList.testCode();
}

void TestCode::testMenuIO()
{
	MenuIO testMenu = MenuIO();
	testMenu.intValidator(1, 3);
	testMenu.stringValidator("test value");
}
