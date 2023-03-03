class point
 {
private:
     float x; //Data member for x-coordinate
     float y; //Data member for y-coordinate
 public:
     point(); // Default Constructor, sets X = Y = 0
     point(float x1,float y1); //Constructor. Initializes both X and Y. Parameters passed from main to initialise the data members x and y which store the x and y coordinates, x1 takes the x-coordinate y1 takes the y-coordinate
     void SetX(float x1); //parameter passed from main to set value for data member x, Set X value

     void SetY(float y1); //parameter passed from main to set value for data member y, Set Y value
     float GetX();// Getter function thet returns the X-coordinate stored in data memeber X

     float GetY();// Getter function thet returns the Y-coordinate stored in data memeber Y

     void DisplayPoint();// Displays point as (X , Y)

     float Distance(point &p); // distance between current point object and another point p

 };
