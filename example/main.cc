#include "Person.hpp"
using namespace std;

int main()
{
    Person P1("Dennis", 10000);
    Person P2("Mars", 1000);

    cout << P1 << P2;

    P1.Salary = 20000;
    P2.Salary = 100;
    cout << P1 << P2;
}