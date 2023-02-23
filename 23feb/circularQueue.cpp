#include<iostream>
using namespace std;

class queue{
    private:
    const static int N = 10; // capacity of the queue
    int a[N];
    int f = 0, r = 0; // f -> left boundary, r -> right +1 boundary
    int sz = 0; // size of queue

    public:
    // push , pop, front, back, empty, size
    void push( int x ){
        if( sz == N ) {
            cout<<"Queue is full!!"<<endl;
            return;
        }
        a[r] = x;
        // r++;
        // if(r == N) r = 0;
        r = (r+1)%N;
        sz += 1;
    }  
    void pop(){
        if(sz == 0 ){
            cout<<"Queue is already empty!!"<<endl;
            return;
        }
        f = (f + 1)%N;
        sz -= 1;
    }
    int front(){
        if( sz == 0) {
            cout<<"Queue is empty!!"<<endl;
            return -1 ;
        }
        return a[f];
    }
    int back(){
        if( sz == 0) {
            cout<<"Queue is empty!!"<<endl;
            return -1 ;
        }
        // if( r == 0 ) return a[N-1];
        // return a[r-1]; 
        return a[ (r-1 + N )%N ];
    }

    bool empty(){
        if( sz == 0 ) return true;
        return false;
    }

    int size(){
        return sz;
    }
};
int main(){

    queue q;
    //insertion
    q.push(1);
    q.push(2);
    q.push(5);

    // pop
    q.pop(); // 2 5

    // see front element
    cout<<q.front(); // 2

    // see back element
    cout<<q.back(); // 5

    // check if queue is eempty or not
    cout<<q.empty(); // false or 0

    // size of queue
    cout<<q.size(); // 2
}