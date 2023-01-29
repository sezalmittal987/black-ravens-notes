#include<iostream>
#include<string>
using namespace std;

class student{
    public : 
    char name[50];
    char gender[50];
    int age;

    void increaseAge( int x ){
        age += x;
    }

    void printData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Gender : "<<gender<<endl;
    }
};

int main(){
    student s1;
    cout<<sizeof(s1)<<endl;
    cin>>s1.name>>s1.gender>>s1.age;
    s1.printData();
    s1.increaseAge(2);
    s1.printData();
}
