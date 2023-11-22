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

using namespace std;

void readFiles();
void printGroupInfo();

int main() {

    //Step 1: Open and read information from city.txt and road.txt
    readFiles();

    return 0;
}

void readFiles() {

    fstream cityFile; //Intializing cityFile as read/write type.
    fstream roadFile; //Initializing roadFile as read/write type.
    
    string line; //Initializing line as a string to get data from files.

    if(!cityFile.is_open()) { //If the city file is not open...
        cityFile.open("city.txt", ios::in); //Open the city file.
        
        //Get a line from the city file.
        //Process data from line.
        //Repeat until end of file.
        do{
            //Initializing integers with negative value for error detection,(program uses all positive integers).
            int cityNumID = -1; //Initializing number associated with the city.
            string cityCode; //Initializing abbreviation associated with the city.
            string cityName; //Initializing the name of the city.
            int cityPop = -1; //Initializing the population of the city.
            int cityElev = -1; //Initializing the elevation of the city.

            cityFile >> cityNumID >> cityCode >> cityName >> cityPop >> cityElev; //Read from city.txt and store file data accordingingly.
            
            //This line is for test purposes only to make sure. Will edit out later. Lets me know if properly reading from file.
            cout << "\nCity Number ID: " << cityNumID << ", City Code: " << cityCode << ", City Name: " << cityName << ", City Population: " << cityPop << ", City Elevation: " << cityElev << endl;            
        }while(getline(cityFile, line));

        cityFile.close(); //Close cityFile
    }
    else {
        cout << "Error opening/closing file." << endl; //Error catcher in event can't open or close file properly.
    }
}

//This function prints our group and assignment information.
void printGroupInfo() {
    cout << "\nAuthors: Toan Nguyen and Sawyer Sieja" << endl;
    cout << "Date: 11/29/2023" << endl;
    cout << "Course: CS311 (Data Structures and Algorithms)" << endl;
    cout << "Description: This program finds the shortest route between cities." << endl;
    cout << "----------------------------------------------------------------" << endl;
}