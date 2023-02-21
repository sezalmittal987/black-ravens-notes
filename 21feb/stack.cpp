#include<iostream>
#include<stack>

using namespace std;

int main(){
    // create
    stack<int> s;

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
    s.push(8);
    s.push(2);
    while(s.empty() == false){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}