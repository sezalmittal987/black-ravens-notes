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

void deleteAtLast(Node** head){
    Node* curr = *head;
    //empty
    if( curr == NULL ) return;
    //only one node
    if( curr->next == NULL){
        *head = NULL;
        return;
    }
    while(curr->next and curr->next->next != NULL){
        curr = curr->next;
    }
    curr->next = NULL;
}

void deleteAtFirst(Node** head){
    Node* curr = *head;
    if( curr == NULL ) return;
    *head = curr->next;
}

void deleteAtMid(Node** head, int pos){
    Node* curr = *head;
    int i = 0;
    // empty LL
    if(curr == NULL) return;
    // Start
    if( pos == 0 ) *head = curr->next;
    while( i < (pos - 1) and curr->next!= NULL){
        i++;
        curr = curr->next;
    }
    // pos>length
    if( i < pos - 1) return;
    // Last 
    if( curr->next) curr->next = curr->next->next;
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
    deleteAtMid(&head2, 0);
    printLL(head2);
    deleteAtMid(&head2, 1);
    printLL(head2);
    deleteAtMid(&head2, 2);
    printLL(head2);
    deleteAtMid(&head2, 0);
    printLL(head2);
    deleteAtMid(&head2, 0);
    printLL(head2);
}