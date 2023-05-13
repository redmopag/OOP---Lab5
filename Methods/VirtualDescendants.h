#pragma once
#include "Virtuals.h"

class DescendantVirtual : public AncestorVirtual
{
public:
	DescendantVirtual() { std::cout << "DescendantVirtual()\n"; }
	virtual ~DescendantVirtual() { std::cout << "virtual ~DescendantVirtual()\n"; }

	void method() override
	{
		std::cout << "virtual void DescendantVirtual::method()\n";
	}
};

class DescendantNotVirtual : public AncestorNotVirtual
{
public:
	DescendantNotVirtual() { std::cout << "DescendantNotVirtual()\n"; }
	virtual ~DescendantNotVirtual() { std::cout << "virtual ~DescendantNotVirtual()\n"; }

	void method()
	{
		std::cout << "void DescendantNotVirtual::method()\n";
	}
};