#pragma once
#include "Ancestors.h"
#include <iostream>

class ForMethods : public Ancestor
{
public:
	ForMethods() { std::cout << "ForMethods()\n"; }
	virtual ~ForMethods() { std::cout << "virtual ~ForMethods()\n"; }

	void method2()
	{
		std::cout << "void ForMethods::method2()\n";
	}
};

class ForVirtMeth : public AncestorForVirt
{
public:
	ForVirtMeth() { std::cout << "ForVirtMeth()\n"; }
	virtual ~ForVirtMeth() { std::cout << "virtual ~ForVirtMeth()\n"; }

	void method2() override
	{
		std::cout << "virtual void ForVirtMeth::method2()\n";
	}
};