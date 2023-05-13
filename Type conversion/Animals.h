#pragma once
#include <string>

class Animal
{
public:
	virtual std::string className()
	{
		return "Animal";
	}
	virtual bool isA(const std::string& className)
	{
		return className == "Animal";
	}
};

class Cat : public Animal
{
public:
	std::string className() override { return "Cat"; }
	bool isA(const std::string& className) override
	{
		return className == "Cat" || Animal::isA(className);
	}
	virtual void catchMouse() { std::cout << "catch mouse\n"; }
};

class Dog : public Animal
{
public:
	std::string className() override { return "Dog"; }
	bool isA(const std::string& className) override
	{
		return className == "Dog" || Animal::isA(className);
	}
	virtual void chaseCat() { std::cout << "chase cat\n"; }
};

class BullDog : public Dog
{
public:
	std::string className() override { return "Bulldog"; }
	bool isA(const std::string& className) override
	{
		return className == "Bulldog" || Dog::isA(className);
	}
	void chaseCat() override { std::cout << "bulldog chase cat\n"; }
};