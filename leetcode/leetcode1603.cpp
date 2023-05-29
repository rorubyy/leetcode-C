#include <iostream>
#include <vector>
using namespace std;

class ParkingSystem
{
public:
    vector<int> availableSlot{0, 0, 0};
    ParkingSystem(int big, int medium, int small)
    {
        availableSlot[0] = big;
        availableSlot[1] = medium;
        availableSlot[2] = small;
    }

    bool addCar(int carType)
    {
        if (availableSlot[carType - 1] > 0)
        {
            availableSlot[carType - 1]--;
            return true;
        }
        return false;
    }
};
int main()
{
    int big = 1, medium = 1, small = 0;
    ParkingSystem *obj = new ParkingSystem(big, medium, small);
    obj->addCar(1);
    obj->addCar(2);
    obj->addCar(3);
    obj->addCar(1);
}
