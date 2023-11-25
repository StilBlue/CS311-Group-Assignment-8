#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

class CityMap
{
public:
    int weight[20][20];
    vector<CityInfo> cityList;
    int totalCity;
    
    //Construct the city info and road map by reading city.txt and road.txt file
    CityMap();
    
    //Print informations of a city
    void PrintCityInfo(string cityCode);

    //Using Dijkstra Algorithm to find the shortest route
    void FindShortestRoute(string a, string b);
    int FindClosestUnprocessedVertex(int distance[], bool visited[]);
    bool VisitedAll(bool list[]);
    
    //Return city number from city code
    int CityNumber(string cityCode);

    //Check if the city exist in data
    bool CityExist(string city);
};