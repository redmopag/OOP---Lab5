#include <iostream>
#include "Descendants.h"
#include "VirtualDescendants.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        std::cout << "Вызов метода1 у класса потомка. Невиртуальный метод2 переопределён в классе-потомке ForMethods:\n";
        ForMethods forMethods;
        forMethods.method1();
    }

    std::cout << "\n\n";

    {
        std::cout << "Вызов метода1 у класса потомка. Виртуальный метод2 переопределён в классе-потомке ForVirtMeth:\n";
        ForVirtMeth forVirtMeth;
        forVirtMeth.method1();
    }

    std::cout << "\n\n";

    {
        std::cout << "Обращение к объекту-потомку через указатель на базовый класс (в базовом классе метод невиртуальный):\n";
        AncestorNotVirtual* anv = new DescendantNotVirtual;
        anv->method();
        delete anv;

        std::cout << "Обращение к объекту-потомку через указатель на класс-потомок:\n";
        DescendantNotVirtual* dnv = new DescendantNotVirtual;
        dnv->method();
        delete dnv;
    }

    std::cout << "\n\n";

    {
        std::cout << "Обращение к объекту через указатель на базовый класс (в базовом классе метод виртуальный):\n";
        AncestorVirtual* av = new DescendantVirtual;
        av->method();
        delete av;

        std::cout << "Обращение к объекту через указатель на класс-потомок:\n";
        DescendantVirtual* dv = new DescendantVirtual;
        dv->method();
        delete dv;
    }
}