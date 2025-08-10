#include <iostream>
#include <string>

using namespace std;

class vehicle {

private:   //encapsulation ka part -> jaha data members ko private kr do

string brand;
int year;

//jab constructor banega tabhi brand and year uske liye hain 

protected:
  vehicle (string b, int y) : brand(b),year(y) {}
     
public:
void setbrand(string b){
    brand = b;
}

string getbrand(){
    return brand;
}


void setyear(int y){
    year = y;
}

int getyear(){
    return year;
}

virtual void displayinfo() = 0;  //force kiya hain derived class apna display info show krein 

 virtual ~vehicle() {

  cout << "vehicle destroyed" << endl;

 }

};




//inheritance + polymorphism jab hoga toh kya hoga 



class car : public vehicle {
private:
int seats;

  public: 
   car(string b,int y, int s) : vehicle(b,y) , seats(s) {}


   void displayinfo() override {

  cout << "car: " << getbrand() << "(" << getyear() << "), seats :" << seats << endl;


   }

};


class bike : public vehicle {
private:

bool hasgear;
  
public:
  bike(string b, int y, bool g) : vehicle(b,y) , hasgear(g) {}
  
  void displayinfo() override {
    cout << "bike: " << getbrand() << "(" << getyear() << "), gear: " << (hasgear ? "yes":"no") << endl;
  }
};






int main() {
    vehicle* v1 = new car("Toyota", 2020, 5);
    vehicle* v2 = new bike("Yamaha", 2022, true);

    v1->displayinfo(); // Polymorphism → Car version
    v2->displayinfo(); // Polymorphism → Bike version

    delete v1;
    delete v2;
}
