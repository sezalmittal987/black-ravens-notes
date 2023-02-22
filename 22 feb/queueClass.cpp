#include<iostream>

using namespace std;

class queue{
    private:
    int a[100000];
    int f = 0 ; // left boundary of the queue
    int b = 0 ;  // right + 1 boundary of the queue

    public:

    //front, back, push, pop, empty, size
    int front(){
        // if( f == b ) throw error
        return a[f];
    }
    int back(){
        // if( f == b ) throw error
        return a[b - 1];
    }
    void push(int x){
        a[b] = x;
        b++;
    }
    void pop(){
        if( f != b ) f++;
    }
    bool empty(){
        if( f == b ) return true;
        return false;
    }
    int size(){
        return b-f;
    }
};

int main(){

    queue q;
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