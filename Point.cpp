#include <iostream>
#include "point.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
 point :: point(){ // Default Constructor, sets X = Y = 0
     x=0;
     y=0;
 }
 point :: point(float x1,float y1){ //Constructor. Initializes both X and Y. Parameters passed from main to initialise the data members x and y which store the x and y coordinates, x1 takes the x-coordinate y1 takes the y-coordinate
     x=x1;
     y=y1;
 }
 void point :: SetX(float x1){ //parameter passed from main to set value for data member x
     x=x1;            // Set X value
 }
 void point :: SetY(float y1){ //parameter passed from main to set value for data member y
     y=y1;            // Set Y value
 }
 float point :: GetX(){
     return x;        // Getter function thet returns the X-coordinate stored in data memeber X
 }
 float point :: GetY(){
     return y;        // Getter function thet returns the Y-coordinate stored in data memeber Y
 }
 void point :: DisplayPoint(){
     cout<<'('<<x<<','<<y<<")"; // Displays point as (X , Y)
 }
float point :: Distance(point &p){// finction returns distance between current point object and another point and has object of class point passed as parameter
    return pow(pow(p.GetX()-x,2)+pow(p.GetY()-y,2),0.5);// formula to calculate distance between point passed as parameter and the point of the current object
}
point Center(point *C,int n){ //a pointer to class point is passed to function along with number of elements it points to in the array
    point p;float totalX=0,totalY=0; //Declared class p of class point to store the point with coordinates of the center of the cluster of points. Declared variable totalX to store the sum of Xcoordinates in the points array. Declared variable totalY to store the sum of Ycoordinates in the points array.
    for(int i=0;i<n;i++){ //loop to access each point in the array
        totalX=totalX+(*(C+i)).GetX(); //Add the Xcoordinate of point in the current accessed array element to the current sum of Ycoordinates by accessing the getter function for the Xcoordinate since X data member is private so cannot be accessed form outside the class
        totalY=totalY+(*(C+i)).GetY(); //Add the Ycoordinate of point in the current accessed array element to the current sum of Ycoordinates by accessing the getter function for the Ycoordinate since Y data member is private so cannot be accessed form outside the class
    }
    p.SetX(totalX/n); //Calculates the average of the Xcoordinates and sets it to the data member X of the point that will be returned by the function by accessing the setter function for the Xcoordinate since X data member is private so cannot be accessed form outside the class
    p.SetY(totalY/n); //Calculates the average of the Ycoordinates and sets it to the data member Y of the point that will be returned by the function by accessing the setter function for the Ycoordinate since Y data member is private so cannot be accessed form outside the class
    return p; //returns the point objecr back to main
}
char Closest(point *A,point *B,point P,int n){ //pointer to cluster A and pointer to cluster B is passed as parameters to the function. Point P which we will check if it is closer to cluster A or B is passed too. The number of points in each cluster is passed as parameter to the function too.
    point CenterA,CenterB; //Declared objects CenterA and CenterB of class point which stores the center of cluster A and B respectively
    float DistanceA,DistanceB; //Declared variables to store the distance between point P and the center of cluster A and B respectively
    CenterA=Center(A,n); // Calls function Center which return the point that is the center of cluster A
    CenterB=Center(B,n); // Calls function Center which return the point that is the center of cluster B
    DistanceA=P.Distance(CenterA); //Point P calls the class function Distance which calculates distance between point P and the point passed as parameter in this case center of cluster A. Then it stores this distance in variable DistanceA
    DistanceB=P.Distance(CenterB); //Point P calls the class function Distance which calculates distance between point P and the point passed as parameter in this case center of cluster B. Then it stores this distance in variable DistanceB
    if(DistanceA<DistanceB) // checks which distance value is smaller
        return 'A'; //If distanceA value is smaller this means point P is closer to center of cluster A so it function returns char 'A' indicating that point P is closer to cluster A than to cluster B
    else
        return 'B'; //If distanceA value is smaller this means point P is closer to center of cluster A so it function returns char 'A' indicating that point P is closer to cluster A than to cluster B
}
int main(){
    point *A,*B,P; //declares a pointer of class point to each array of clusters and a class P to store a point
    int n=200; //declares variable to store the number of points in both clusters A and B
    A=new point[n]; //makes a dynamic array of class point to store the points in cluster A
    B=new point[n]; //makes a dynamic array of class point to store the points in cluster B
    srand(time(NULL));
    for(int i=0;i<200;i++){ //loop to access each array element
        
        (*(A+i)).SetX((rand() % 19) + 71); // generates random value in range 70.0 < x < 90.0 and stores it in the X data member of the current object element of the array
        (*(A+i)).SetY((rand() % 19) + 71); //generates random value in range 70.0 < y < 90.0 and stores it in the Y data member of the current object element of the array
        (*(B+i)).SetX((rand() % 19) + 21); //generates random value in range 20.0 < x < 40.0 and stores it in the X data member of the current object element of the array
        (*(B+i)).SetY((rand() % 19) + 21); //generates random value in range 20.0 < y < 40.0 and stores it in the Y data member of the current object element of the array
    }
    srand(time(NULL));
    for(int i=0;i<20;i++){ //loop to generate 20 different points randomely
        P.SetX((rand() % 94) + 6); // generates random value in range 5.0 < x < 100.0 and stores it in the X data member of object P
        P.SetY((rand() % 94) + 6); //generates random value in range 5.0 < y < 100.0 and stores it in the Y data member of object P
        P.DisplayPoint();
        cout<<' '<<" belongs to cluster: "<<Closest(A,B,P,n)<<endl;
    }
}
