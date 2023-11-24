#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CityInfo;

class CityInfo
{
    public:
        //Infos of the city
        int numID;
        string code;
        string name;
        int pop;
        int elev;

        //Class constructor
        CityInfo() {numID = -1; code = ""; name = ""; pop = -1; elev = -1;};
};
