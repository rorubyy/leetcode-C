#include <iostream>
#include <unordered_map>
using namespace std;

class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> checkin;
    unordered_map<string, pair<int, int>> travelTimes; // first int: travel total time, second int: travel times
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkin[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        string travelPlace = checkin[id].first + "," + stationName;
        int time = t - checkin[id].second;
        checkin.erase(id);

        if (travelTimes.find(travelPlace) != travelTimes.end())
        {
            travelTimes[travelPlace].first += time;
            travelTimes[travelPlace].second++;
        }
        else
        {
            travelTimes[travelPlace] = make_pair(time, 1);
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        string travelPlace = startStation + "," + endStation;
        if (travelTimes.find(travelPlace) != travelTimes.end())
            return (double)travelTimes[travelPlace].first / travelTimes[travelPlace].second;
        else
            return 0;
    }
};
int main()
{
    UndergroundSystem *obj = new UndergroundSystem();
    obj->checkIn(0, "abc", 5);
    obj->checkOut(0, "def", 7);
    double param_3 = obj->getAverageTime("abc", "def");
}