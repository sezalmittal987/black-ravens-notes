#include<iostream>
#include<string>
using namespace std;

struct student{
    char name[50];
    char gender[50];
    int age;
};

int main(){
    student s1;
    cout<<sizeof(s1)<<endl;
    cin>>s1.name>>s1.gender>>s1.age;
    cout<<"Name : "<<s1.name<<endl;
    cout<<"Age : "<<s1.age<<endl;
    cout<<"Gender : "<<s1.gender<<endl;
}
