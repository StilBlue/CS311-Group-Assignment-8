#include <iostream>
#include <string>
#include <fstream>
#include "CityInfo.h"

using namespace std;

class CityMap
{
public:
    int weight[20][20];
    vector<CityInfo> cityList;
    
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

CityMap::CityMap()
{
    fstream roadFile; //Initializing roadFile as read/write type.
    fstream cityFile; //Intializing cityFile as read/write type.
    
    string line; //Initializing line as a string to get data from files.

    if(!cityFile.is_open()) { //If the city file is not open...
        cityFile.open("city.txt", ios::in); //Open the city file.
    }

    //Get a line from the city file.
    //Process data from line.
    //Repeat until end of file.
    do{
        CityInfo temp;
        //Initializing integers with negative value for error detection,(program uses all positive integers).
        cityFile >> temp.numID >> temp.code >> temp.name >> temp.pop >> temp.elev; //Read from city.txt and store file data accordingingly.

        cityList.push_back(temp);
        //This line of code prints each line being read from file. TEST PURPOSES ONLY.
        //(It works!)
    }while(getline(cityFile, line));

    cityFile.close(); //Close cityFile

    //Assign -1 to every vertex in weight
    for (int i = 0; i < cityList.size(); i++)
    {
        for (int j = 0; j < cityList.size(); j++)
        {
            weight[i][j] = -1;
        }
    }
    
    if(!roadFile.is_open()) { //If the road file is not open...
        roadFile.open("road.txt", ios::in); //Open the road file.

        //Initializing integers with negative value for error detection,(program uses all positive integers).
        int fromCity = -1;
        int toCity = -1;
        int cityDistance = -1;
        
        //Get a line from the road file.
        //Process data from line.
        //Repeat until end of file.
        do{
            roadFile >> fromCity >> toCity >> cityDistance; //Read from road.txt and store file data accordingingly.
            
            //Save data into weight
            weight[fromCity][toCity] = cityDistance;
        }while(getline(roadFile, line));

        roadFile.close(); //Close roadFile
    }
    else {
        cout << "Error opening/closing file." << endl; //Error catcher in event can't open or close file properly.
    }
    
}

int CityMap::CityNumber(string cityCode)
{
    //If the cityCode match a CityInfo in cityList, return city name of that CityInfo
    for (int i = 0; i < cityList.size(); i++)
    {
        if (cityList[i].code == cityCode)
            return cityList[i].numID;
    }
    return -1;
}

void CityMap::FindShortestRoute(string a, string b)
{
    //Use CityNumber function to get city number of a and b
    int cityA = CityNumber(a);
    int cityB = CityNumber(b);

    bool visited[cityList.size()];
    int distance[cityList.size()];
    string path[cityList.size()];

    //Initialize all value of visited[] to false
    //Initialize all value of distance[] to largest integer possible
    //Initialize all value of path[] to empty string
    for (int i = 0; i < cityList.size(); i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
        path[i] = "";
    }

    //Assign 0 to distance of vertex A, making it the starting point
    distance[cityA] = 0;
    while (!VisitedAll(visited))
    {
        //Assign the city number of the closest vertex to u
        int u = FindClosestUnprocessedVertex(distance,visited);
        
        //Mark u as visited vertex
        visited[u] = true;

        for (int v = 0; v < cityList.size(); v++)
        {
            //If v vertex is not marked as visited
            //and having an edge connecting from u to v
            //and the distance from u to v is less than or equal the current distance of v
            if (!visited[v] && weight[u][v] > -1 && distance[v] >= distance[u] + weight[u][v])
            {
                //Assign the distance from u to v to the distance of v
                distance[v] = distance[u] + weight[u][v];

                //Assign the path of u to path[v]
                path[v] = path[u] + cityList[u].name + "->";
            }
        }
    }

    //Error message if city distance is less than 0
    if (distance[cityB] < 0)
    {
        cout << "No route from " << cityList[cityA].name << " to " << cityList[cityB].name << endl;
    }
    else
    {
        //Print output
        cout << "The Shortest Distance from " << cityList[cityA].name << " to " << cityList[cityB].name << " is " << distance[cityB] << endl;

        cout << "through the route: ";
        cout << path[cityB] << cityList[cityB].name << endl;
    }
}

bool CityMap::VisitedAll(bool list[])
{
    //Return false if detect a false inside list[]
    for (int i = 0; i < cityList.size(); i++)
    {
        if (!list[i])
            return false;
    }
    return true;
}

int CityMap::FindClosestUnprocessedVertex(int distance[], bool visited[])
{
    //Initialize minimun distance to largest integer possible
    int minDist = INT_MAX;
    int closest = -1;
    
    for (int i = 0; i < cityList.size(); i++)
    {
        //Assign the city number with the smallest value in distance[] to closest
        if (distance[i] <= minDist && !visited[i])
        {
            minDist = distance[i];
            closest = i;
        }
    }
    return closest;
}

bool CityMap::CityExist(string city)
{
    for (int i = 0; i < cityList.size(); i++)
    {
        if (cityList[i].code == city)
            return true;
    }
    cout << "Invalid City Code: " << city << endl;
    return false;
}

void CityMap::PrintCityInfo(string cityCode)
{
    int num = CityNumber(cityCode);
    cout << "City: " << cityList[num].name
         << ", population " << cityList[num].pop
         << ". elevation " << cityList[num].elev
         << "\n";
}