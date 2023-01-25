#include<iostream>
using namespace std;

int main(){
    int a = 5;
    cout<<(&a)<<endl;
    cout<<*(&a)<<endl; 

    int* p = (&a);
    cout<<p<<endl;

    cout<<&(*(&a))<<endl; //address of a 
    cout<<(&(*(&a)))<<endl; //value of a

    // cout<<&(&(*(&a)))<<endl; // error

    cout<<&(p)<<endl; // address of p 

    int** q = &p;
    cout<<q<<endl; // address of p

    cout<<**q<<endl;
    cout<<&q<<endl; //address of q
    // cout<<&&p<<endl; // gives error

    cout<<sizeof(int*)<<endl;
    cout<<sizeof(char*)<<endl;

    char c = 'a';
    void* p1 = &c;
    int d = 12;
    // cout<< *p1 <<endl;
    cout<<*((char*)p1)<<endl;

    p1 = &d;
    cout<<*((int*)p1)<<endl;
    

}