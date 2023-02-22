#include<iostream>

using namespace std;

// our own implementation of stack
class stack{
    private: // access modifiers
    int a[100000]; // storing the stack values
    int sz = 0; // size of the stack

    public : 
    // push, pop, empty, top
    void push(int x){
        a[sz] = x;
        sz++;
    }   

    void pop(){
        sz--;
    } 

    bool empty(){
        if(sz == 0 ) return true;
        return false;
    }

    int top(){
        // if( sz == 0 )  throw error; 
        return a[sz-1];
    }
};

int main(){
    stack s;
    // adding values to the stack
    s.push(1); //1
    s.push(5); // 1 5
    s.push(8); // 1 5 8

    cout<<s.top()<<endl; // 8
    //remove
    s.pop(); // 1 5

    // check if stack is empty
    cout<< s.empty() << endl; // false

    // check the element on the top
    cout<<s.top()<<endl; // 5

    // print all the elements in the stack
    s.push(8); // 1 5 8
    s.push(2); // 1 5 8 2
    while(s.empty() == false){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}