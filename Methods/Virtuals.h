#pragma once
#include <iostream>

class AncestorVirtual
{
public:
	AncestorVirtual() { std::cout << "AncestorVirtual()\n"; }
	virtual ~AncestorVirtual() { std::cout << "virtual ~AncestorVirtual()\n"; }

	virtual void method() { std::cout << "virtual void AncestorVirtual::method()\n"; }
};

class AncestorNotVirtual
{
public:
	AncestorNotVirtual() { std::cout << "AncestorNotVirtual()\n"; }
	virtual ~AncestorNotVirtual() { std::cout << "virtual ~AncestorNotVirtual()\n"; }

	void method() { std::cout << "void AncestorNotVirtual::method()\n"; }
};