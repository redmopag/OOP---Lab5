#include <iostream>
#include <Windows.h>
#include "Animals.h"
#include <time.h>

Animal* creator(int num)
{
	switch (num)
	{
	case 0:
		return new Cat();
	case 1:
		return new Dog();
	default:
		return new BullDog();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(NULL);
	int size = 10;
	Animal** array = new Animal * [size];
	for (int i = 0; i < size; ++i)
		array[i] = creator(rand() % 3);

	std::cout << "Приведение типов:\n";
	std::cout << "Вывод массива живтоных:\n";
	for (int i = 0; i < size; ++i)
		std::cout << i << " - " << array[i]->className() << "\t";
	std::cout << "\nИспользование classname:\n";

	for (int i = 0; i < size; ++i)
		if (array[i]->className() == "Dog" || array[i]->className() == "Bulldog")
		{
			std::cout << i << " - ";
			static_cast<Dog*>(array[i])->chaseCat();
		}

	std::cout << "\nИспользование isA:\n";

	for (int i = 0; i < size; ++i)
		if (array[i]->isA("Dog"))
		{
			std::cout << i << " - ";
			static_cast<Dog*>(array[i])->chaseCat();
		}

	std::cout << "\nиспользование dynamic_cast:\n";

	for (int i = 0; i < size; ++i)
	{
		Dog* d = dynamic_cast<Dog*>(array[i]);
		if (d != nullptr)
		{
			std::cout << i << " - ";
			d->chaseCat();
		}
	}

	for (int i = 0; i < size; ++i)
		delete array[i];
	delete[] array;
}