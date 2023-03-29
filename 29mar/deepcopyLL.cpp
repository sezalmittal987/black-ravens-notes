#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x, Node* link){
        this->data = x;
        this->next = link;
    }
};


void insertAtFirst(Node** head, int x){
    Node* curr = new Node(x, *head);
    *head = curr;
}


void printLL(Node* head){
    Node* curr = head;
    while( curr ){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

Node* deepCopy( Node* head){
    Node* chead = NULL, *tail = NULL;
    Node* curr = head;
    while( curr ){
        Node* nn = new Node(curr->data, NULL);
        if(!chead){
            chead = nn;
            tail = nn;
        }
        else{
            tail->next = nn;
            tail = nn;  
        }
        curr = curr->next;
    }
    return chead;
}

int main(){
    Node* head = NULL;
    insertAtFirst(&head, 4);
    insertAtFirst(&head, 3);
    insertAtFirst(&head, 2);
    insertAtFirst(&head, 1);
    printLL(head);
    Node* chead = deepCopy(head);
    printLL(chead); 
}