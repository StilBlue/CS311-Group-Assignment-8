/*
* main.cpp
* Authors: Toan Nguyen, Sawyer Sieja
* CS311
* Assignment 8
* Description: 
*   This program will find the shortest route between cities, using the graph data structures.
*/
#include <iostream>
#include <string>
#include <fstream>
#include "graph.h"

using namespace std;

void printGroupInfo();

int main(int argc, char** argv) {

    //Print the information of the group
    printGroupInfo();

    //Check if the argument 1 and 2 exist
    if (argv[1] == NULL || argv[2] == NULL)
    {
        cout << "Need More Argument!" << endl;
        return -1;
    }
    
    //Initialize the city map
    CityMap map;
    
    //End program if city code in argument 1 doesn't exist in city map
    if (!map.CityExist(argv[1]))
        return -1;
    //End program if city code in argument 2 doesn't exist in city map
    if (!map.CityExist(argv[2]))
        return -1;

    cout << "from ";
    map.PrintCityInfo(argv[1]);
    cout << "to ";
    map.PrintCityInfo(argv[2]);
    cout << "----------------------------------------------------------------\n";
    map.FindShortestRoute(argv[1], argv[2]);

    return 0;
}

//This function prints our group and assignment information.
void printGroupInfo() {
    cout << "\nAuthors: Toan Nguyen, Sawyer Sieja and Chase Rhubottom" << endl;
    cout << "Date: 11/29/2023" << endl;
    cout << "Course: CS311 (Data Structures and Algorithms)" << endl;
    cout << "Description: This program finds the shortest route between cities." << endl;
    cout << "----------------------------------------------------------------" << endl;
}