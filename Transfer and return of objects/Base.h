#pragma once
#include <iostream>
#include <string>

class Base
{
public:
	Base()
	{
		std::cout << "Base()\n";
	}
	Base(Base* obj)
	{
		std::cout << "Base(Base* obj)\n";
	}
	Base(const Base& obj)
	{
		std::cout << "Base(Base& obj)\n";
	}
	virtual ~Base()
	{
		std::cout << "~Base()\n";
	}
	virtual void className() { std::cout << "Base\n"; }
};

