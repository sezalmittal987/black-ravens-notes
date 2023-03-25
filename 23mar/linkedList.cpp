#include<iostream>

using namespace std;

class Node {
    public :
    int data;
    Node* next;
};

bool search(Node* head, int x){
    Node* curr = head;
    while(curr){
        if( curr -> data == x) return true;
        curr = curr->next;
    }
    return false;
}

Node* insertLast( Node* head, int x){
    if( !head ) {
        head = new Node();
        head->data = x;
        head->next = NULL;
        return head;
    }
    Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = new Node();
    curr->next->data = x;
    curr->next->next = NULL;
    return head;
}

void printLL(Node* head){
    Node* curr = head;
    while( curr ){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node();
    // (*head).data = 1;
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // printLL(head);
    // cout<<search(head, 2);
    // cout<<search(head, 3);
    // cout<<search(head, 5);

    // insertLast(head, 5);
    // printLL(head);
    Node* head2 = NULL;
    cout<<head2<<endl;
    head2 = insertLast(head2, 6);
    printLL(head2);
}