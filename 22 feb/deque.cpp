#include<iostream>
#include<deque>

using namespace std;

int main(){
    // create
    deque<int> d;

    // insertion - back
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    // insertion -front
    d.push_front(4);
    d.push_front(5);
    d.push_front(6);

    // deletion - back
    d.pop_back();

    // deletion - front
    d.pop_front();

    // check whether the queue is empty
    cout<<d.empty()<<endl;

    // see front
    cout<<d.front()<<endl;

    //see back
    cout<<d.back()<<endl;

    // see all the element
    while(d.empty() == false){
        cout<<d.front()<<endl;
        d.pop_front();
    }
}