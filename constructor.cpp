#include <iostream>
using namespace std;

class Student
{
public:
    int age;

    Student()   // Constructor
    {
        age = 18;
    }
};

int main()
{
    Student s;
    cout << s.age << endl;
    return 0;
}
