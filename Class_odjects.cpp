#include <iostream>
using namespace std;

class Car
{
public:
    int speed;

    void drive()
    {
        cout << "Car is driving at " << speed << " km/h" << endl;
    }
};

int main()
{
    Car c1;        // Object
    c1.speed = 60;
    c1.drive();
    return 0;
}
//end