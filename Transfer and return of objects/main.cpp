#include <iostream>
#include <Windows.h>
#include "Base.h"
#include "Desc.h"
#include <memory>

void func1(Base obj)
{
	std::cout << "func1(Base obj)\n";
	obj.className();
}
void func2(Base* obj)
{
	std::cout << "func2(Base* obj)\n";
	obj->className();
}
void func3(Base& obj)
{
	std::cout << "func3(Base& obj)\n";
	obj.className();
}
void func_unique_ptr(std::unique_ptr<Base> base)
{
	std::cout << "func_unique_ptr(std::unique_ptr<Base> base)\n";
	base->className();
}

Base func1()
{
	std::cout << "Base func1()\n";
	Base b;
	return b;
};
Base* func2()
{ 
	std::cout << "Base* func2()\n";
	Base b;
	return &b;
};
Base& func3()
{ 
	std::cout << "Base& func3()\n";
	Base b;
	return b;
};
Base func4()
{ 
	std::cout << "Base func4()\n";
	Base* b = new Base;
	return *b;
};
Base* func5()
{ 
	std::cout << "Base* func5()\n";
	Base* b = new Base;
	return b;
};
Base& func6()
{
	std::cout << "Base& func6()\n";
	Base* b = new Base;
	return *b;
};
// Создаёт и возвращает unique_ptr
std::unique_ptr<Base> func_unique_ptr()
{
	std::cout << "std::unique_ptr<Base> func_unique_ptr()\n";
	std::unique_ptr<Base> base = std::make_unique<Base>();
	return base;
}

// Принимает, использует shared_ptr
void func_shared_ptr(std::shared_ptr<Base> base)
{
	std::cout << "func_shared_ptr(std::shared_ptr<Base> base)\n";
	base->className();
}
std::shared_ptr<Base> func_shared_ptr()
{
	std::cout << "std::shared_ptr<Base> func_shared_ptr()\n";
	std::shared_ptr<Base> base = std::make_shared<Base>();
	return base;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		std::cout << "Передача объектов в 3 функции:\n";
		Base* b = new Base;
		func1(*b);
		func2(b);
		func3(*b);
		delete b;
		std::cout << "\n";
		Desc* d = new Desc;
		func1(*d);
		func2(d);
		func3(*d);
		delete d;
	}

	std::cout << "\n\n";

	{
		std::cout << "Возврат объектов из функции:\n";
		std::cout << "Статическое создание объектов:\n";
		Base b1 = func1();
		Base* b2 = func2();
		Base& b3 = func3();

		std::cout << "Динамическое создание объектов:\n";
		Base b4 = func4();
		Base* b5 = func5();
		Base& b6 = func6();
		delete b5;
		delete& b6;
		// Появится 4 деструктора: два выше указанных и 2 от b1 и b4, у них автоматическая
		// продолжительность жизни, так как они объявлены на стеке
		// Следовательно они удаляются автоматически после выхода из области видимости 
	}

	std::cout << "\n\n";

	{
		std::cout << "Умные указатели (unique_ptr):\n";
		std::unique_ptr<Base> base = std::make_unique<Base>();
		// Передали через семантику перемещения указатель base, в функции он и удаляется
		func_unique_ptr(std::move(base));
		// Следовательно base равен null - пустой
		if (base == NULL)
			std::cout << "unique_ptr is null\n";

		// Создаём в функции новый unique_ptr и возвращаем его с функции, используя семантику перемещения
		base = func_unique_ptr();
		std::cout << "unique_ptr is "; 
		base->className();
	}

	std::cout << "\n\n";

	{
		std::cout << "Умные уазатели (shared_ptr):\n";
		// Создаём указатель shared_ptr
		std::shared_ptr<Base> base1 = std::make_shared<Base>();
		func_shared_ptr(base1);
		// Указатель не пустой, хотя тот, который мы передали в функцию уничтожился
		std::cout << "Shared_ptr is ";
		base1->className();

		std::shared_ptr<Base> base2 = func_shared_ptr();
		base2->className();
	}
}