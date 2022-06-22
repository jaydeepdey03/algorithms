#include <iostream>

using namespace std;

class Emp{
    public:
    string name;
    int sal;
    int age;

    Emp(string name, int age, int sal){
        this->name = name;
        this->age = age;
        this->sal = sal;
    }
};

int main()
{
   Emp e("jaydeep", 12,12);
    return 0;
}