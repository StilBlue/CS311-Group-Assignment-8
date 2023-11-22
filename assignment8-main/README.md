<h1 align="center">CS311 Group Assignment 8 </h1>
<h2 align="center">Total points: 10</h2>

In this group (2-3 students) assignment, you will design and implement a practical application to find the shortest route between cities, using the graph data structures.

## Description
Your program will read city data and road data from two files.
- city.txt -- It contains info of 20 cities with 5 columns: ID, City_Code(2 letters), City_Name, Population, and Elevation.
- road.txt -- It contains 3 columns: From_City, To_City, and Distance. Note that each road is one-directional from the from_city to the to_city, and the distances are not supposed to realistic. 

The executable should be called `prog8` and run with two command-line arguments. The first argument is the two-letter code of the from_city and the second argument is the code of the to_city. For example:
```
./prog8 AN BK
```
When the program runs, it should first print out your group names and the info about the two cities, for example:
```
Author: xxxxxx and xxxxxxx
Date: xx/xx/20xx
Course: CS311 (Data structures and Algorithms)
Description : Program to find the shortest route between cities 
----------------------------------------------------------------
From City: ANAHEIM, population 1273000, elevation 310
To City: BAKERSFIELD, population 31100, elevation 390
```
Then it prints out the shortest route, for example:
```
The shortest distance from ANAHEIM to BAKERSFIELD is 225
through the route: ANAHEIM->VICTORVILLE->CHINO->GRPVE->ISABELLA->BAKERSFIELD
```
If the input city code dosen't exist, the program should exit and print out an error message, for example 
```
Invalid city code: AA
```
If there is not a path between two cities, it should print out 
```
No route from WRIGHTWOOD to KERNVILLE
```

## Testing

You should thoroughly test the correctness and robustness of your program with various command-line inputs. It shouldn't crash with invalid inputs, but exit gracefully and print out error and usage message. You can compare your results to the included "sample_results.txt" file. 



## Submission 
You have to submit the pdf (Only pdf please) version of your report in Canvas. The group members' names should be mentioned in the report. Only one member of each group will upload a report. 

## Design and Implmentation
You will work as a group of 2-3 for this assignment. No starter code will be provided.  

Please write your group name into this document. 

https://docs.google.com/document/d/1mw8wpsCsZJQOVdRKWfKJrSrJYX-1YNGrbuoHTFmgjTU/edit?usp=sharing


For this assignment, your group will turn in a program report (representative code will be added in the appendix of the report) and discuss the design and implementation of the program, and the results. 


## Problem Description 
In this section, describe the problem you are solving and the functionalities of your program to solve the problem.

## Program Design
Describe the overall design of your program. 
- What algorithm did you choose for implementing the shortest path problem? Why this algorithm is applicable here?
- What classes do you use or add? Why do you choose to use those classes?

## System Implementation
- Describe the details of your implementations. Did you run into problems in your implementation? How did you overcome those problems?

## Results
- Did your results match the output in the “sample_results.txt” file? 
- What are your answers to the following questions:
   - The shortest distance and path from FI to GG
   - The shortest distance and path from PD to PM
   - The shortest distance and path from PM to PD
   - The Shortest distance and path from SB to PR
## Conclusion
- Did your results match the output of the test program? Did you run into problems in your implementation? How did you overcome those problems?

## Appendix
- You have to provide screenshots of all of your code.

 




