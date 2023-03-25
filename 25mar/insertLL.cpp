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

Node* insertAtLast(Node* head, int x){
    if( !head ){
        head = new Node(x, NULL);
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr=curr->next;
    }
    curr->next = new Node(x, NULL);
    return head;
}

void insertAtLast2(Node** head, int x){
    if(*head == NULL){
        Node* curr = new Node(x, NULL);
        *head = curr;
        return;
    }
    Node* curr = *head;
    while(curr->next != NULL){
        curr=curr->next;
    }
    curr->next = new Node(x, NULL);
    return ;
}

Node* insertAtFirst(Node* head, int x){
    Node* curr = new Node(x, head);
    head = curr;
    return head;
}

void insertAtFirst2(Node** head, int x){
    Node* curr = new Node(x, *head);
    *head = curr;
}

void insertAtMid(Node** head, int pos, int x){
    Node* curr = *head;
    int i = 0;
    Node* newNode = new Node(x, NULL);
    if( pos == 0 or *head == NULL ){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while( i < (pos-1) and curr->next != NULL ){
        i++;
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
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
    Node* head2 = NULL;
    insertAtMid(&head2, 0, 6);
    insertAtMid(&head2, 1, 3);
    insertAtMid(&head2, 1, 4);
    insertAtMid(&head2, 7, 7);
    printLL(head2);
}