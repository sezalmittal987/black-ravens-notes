#include<iostream>
#include<string>
using namespace std;

int currentCars = 0;

class car{
    public : 
    int tyres;
    string color = "Red";
    int maxspeed = 100;
    int mileage = 8;

    car(){
        cout<<"A car has been created!"<<endl;
        currentCars += 1;
    }

    car(int t, string c, int s, int m){
        currentCars += 1;
        tyres = t;
        color = c;
        maxspeed = s;
        mileage = m;
    }
 
    void changeColor(string newColor){
        color = newColor;
        cout<<"Changing color of the car to "<<color<<endl;
    }

    void changeTyres(int tyres ){
        // tyres = tyres; // scope  : tyres will be the one in the parameters.
        this->tyres = tyres;
        (*this).tyres = 8; //both are same just different notation
    }

    void displayData(){
        cout<<"No. of Tyres : "<<tyres<<endl;
        cout<<"Color of the car : "<<color<<endl;
        cout<<"Max. speed of the car : "<<maxspeed<<"kmph"<<endl;
        cout<<"Mileage of the car : "<<mileage<<"kmpl"<<endl;
    }

    ~car(){
        cout<<"Car with color "<<color<<" has been destroyed!"<<endl;
        currentCars -=1;
    }
};

int main(){
    car xuv;
    // cin>>xuv.tyres;
    // cin>>xuv.color>>xuv.maxspeed>>xuv.mileage;
    // xuv.displayData();
    // xuv.changeColor("Green");
    // xuv.displayData();
    // xuv.displayData();
    car a(1, "red", 1, 2);
    // a.displayData();
    car b(2 ,"blue", 12, 3);
    b.changeTyres(8);
    b.displayData();
    if( true) {
        car c; //scope
        cout<<currentCars;
    }
    cout<<currentCars;
    cout<<"10000"<<endl;
}