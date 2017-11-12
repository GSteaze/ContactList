#include <iostream>
#include "MenuIO.h"
#include "TestCode.h"

using namespace std;

int main() {

	//MenuIO menu = MenuIO();

	TestCode test = TestCode();
	test.testContact();
	test.testContactList();
	//test.testMenuIO();

	system("pause");
	return 0;
}
