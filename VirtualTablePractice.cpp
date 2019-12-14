 // VirtualTablePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <Windows.h>

class cX {
public:
	virtual void function1() { std::cout << "Function1 called" << std::endl; }
	int int1 = 5;

	
};



class derivedcX : public cX
{
public:
	virtual void function2() { std::cout << "Function2 called" << std::endl; }
	virtual void function3() { std::cout << "Function3 called" << std::endl; }

};





derivedcX* y = new derivedcX;

//::std::uint32_t* AddressOfClass = reinterpret_cast<::std::uint32_t*>(x);
::std::uint32_t* AddressOfDerivedClass = reinterpret_cast<::std::uint32_t*>(y);
::std::uint32_t* AddressOfFirstFunction = reinterpret_cast<::std::uint32_t*>(*AddressOfDerivedClass + 0x0);
int(*ptrToClassFunc1)() = reinterpret_cast<int(*)()>(*AddressOfFirstFunction);
::std::uint32_t* AddressOfDerivedFunction = reinterpret_cast<::std::uint32_t*>(*AddressOfDerivedClass + 0x4);
int(*ptrToDerivedClassFunc2)() = reinterpret_cast<int(*)()>(*AddressOfDerivedFunction);
::std::uint32_t* AddressOfDerivedFunction3 = reinterpret_cast<::std::uint32_t*>(*AddressOfDerivedClass + 0x8);
int(*ptrToDerivedClassFunc3)() = reinterpret_cast<int(*)()>(*AddressOfDerivedFunction3);

int main()
{	
	
	ptrToClassFunc1();
	
	std::cout << std::endl;
	
	ptrToDerivedClassFunc2();
	
	std::cout << std::endl;

	ptrToDerivedClassFunc3();
	while (true)
	{
		if (GetAsyncKeyState(VK_RSHIFT))
		{
			delete y;
			return 0;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
