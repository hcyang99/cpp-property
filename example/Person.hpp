#pragma once

#include <string>
#include <iostream>
#include "../Property.hpp"

class Person
{
    private:
        struct SalarySetHandler
        {
            bool operator()(int x)
            {
                if (x < MINIMUM_SALARY)
                {
                    std::cerr << "Salary cannot be less than " << MINIMUM_SALARY << ".\n";
                }
                return x >= MINIMUM_SALARY;
            }
        };

    public:
        static const int MINIMUM_SALARY = 1000;
        Person(std::string n, int s)
        {
            Name = n;
            Salary = s;
        }

        MyProperty::ReadOnlyProperty<std::string, Person> Name;
        MyProperty::Property<int, SalarySetHandler> Salary;
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    return os << "Name: " << static_cast<std::string>(p.Name) << ", Salary:"
        << p.Salary << "\n";
}
