#include<iostream>
#include<queue>

using namespace std;

int main(){
    // creation 
    queue<int> q;
    //insertion
    q.push(1);
    q.push(2);
    q.push(5);

    // pop
    q.pop();

    // see front element
    cout<<q.front();

    // see back element
    cout<<q.back();

    // check if queue is eempty or not
    cout<<q.empty();

    // size of queue
    cout<<q.size();
}