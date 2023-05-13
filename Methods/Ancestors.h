#pragma once
#include <iostream>

class Ancestor
{
public:
	Ancestor() { std::cout << "Ancestor()\n"; }
	virtual ~Ancestor() { std::cout << "virtual ~Ancestor()\n"; }

	virtual void method1()
	{
		std::cout << "Ancestor::method1()\n";
		method2();
	}

	void method2()
	{
		std::cout << "Ancestor::method2()\n";
	}
};

class AncestorForVirt
{
public:
	AncestorForVirt() { std::cout << "AncestorForVirt()\n"; }
	virtual ~AncestorForVirt() { std::cout << "virtual ~AncestorForVirt()\n"; }

	virtual void method1()
	{
		std::cout << "virtual void AncestorForVirt::method1()\n";
		method2();
	}

	virtual void method2()
	{
		std::cout << "virtual void AncestorForVirt::method2()\n";
	}
};