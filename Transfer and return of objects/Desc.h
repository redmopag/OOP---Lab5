#pragma once
#include "Base.h"
class Desc : public Base
{
public:
	Desc()
	{
		std::cout << "Desc()\n";
	}
	Desc(Desc* obj)
	{
		std::cout << "Desc(Desc* obj)\n";
	}
	Desc(Desc& obj)
	{
		std::cout << "Desc(Desc& obj)\n";
	}
	~Desc() override
	{
		std::cout << "~Desc()\n";
	}
	void className() override { std::cout << "Desc\n"; }
};

