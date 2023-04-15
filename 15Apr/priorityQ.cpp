#include<iostream>
#include<queue>

using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Comp{
    public:
    bool operator()(Node* a, Node* b){ //operator overloading 
        return a->data < b->data;
    }
};

int main(){
    // creating a pq
    priority_queue<int> pqmax; // max priority queue;
    // insert
    pqmax.push(1);
    pqmax.push(3);
    pqmax.push(5);
    cout<<pqmax.top()<<" ";
    pqmax.push(7);
    pqmax.push(6);
    cout<<pqmax.top()<<" ";
    pqmax.push(2);
    while(!pqmax.empty()){
        cout<<pqmax.top()<<" ";
        pqmax.pop();
    }

    cout<<endl;
    // Min Priority Queue
    priority_queue<int, vector<int> , greater<int> > pqmin;
    pqmin.push(1);
    pqmin.push(3);
    pqmin.push(5);
    cout<<pqmin.top()<<" ";
    pqmin.push(7);
    pqmin.push(6);
    cout<<pqmin.top()<<" ";
    pqmin.push(2);
    while(!pqmin.empty()){
        cout<<pqmin.top()<<" ";
        pqmin.pop();
    }

    // custom Comparator
    cout<<endl;
    priority_queue<Node*, vector<Node*>, Comp> pqNode;
    pqNode.push(new Node(1));
    pqNode.push(new Node(3));
    pqNode.push(new Node(5));
    pqNode.push(new Node(7));
    while(!pqNode.empty()){
        cout<<pqNode.top()->data<<" ";
        pqNode.pop();
    }
}