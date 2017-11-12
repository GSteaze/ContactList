#include "TestCode.h"



TestCode::TestCode()
{
	testContact();
}


TestCode::~TestCode()
{
}

void TestCode::testContact()
{
	cout << "Testing Contact Class : " << endl << endl;

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
