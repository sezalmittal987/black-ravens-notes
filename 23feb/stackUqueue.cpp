#include<iostream>
#include<queue>
using namespace std;

class stack{
    private : 
    queue<int> q, qe;
    public : 
    void pop(){
        // transferring q -> qe 
        int x = q.front();
        q.pop();
        while(!q.empty()){
            qe.push(x);
            x = q.front();
            q.pop();
        }
        // tansfer qe -> q;
        while(!qe.empty()){
            x = qe.front();
            q.push(x);
            qe.pop();
        }
    }
    void push(int x){
        q.push(x);
    }
    bool empty(){
        return q.empty();
    }
    int top(){
        return q.back();
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