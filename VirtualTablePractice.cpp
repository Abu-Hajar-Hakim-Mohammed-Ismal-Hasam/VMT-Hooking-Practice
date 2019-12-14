 // VirtualTablePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <Windows.h>

class cX {
public:
	virtual void function1() { std::cout << "Function1 called" << std::endl; }
	int int1 = 5; // Does not include this variable as it is not stored in the vtable (not "virtual")

	
};


class derivedcX : public cX
{
public:
	virtual void function2() { std::cout << "Function2 called" << std::endl; }
	virtual void function3() { std::cout << "Function3 called" << std::endl; }

};


derivedcX* derivedClass = new derivedcX;

::std::uint32_t* AddressOfDerivedClass = reinterpret_cast<::std::uint32_t*>(derivedClass);
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
			delete derivedClass;
			return 0;
		}
	}
}
