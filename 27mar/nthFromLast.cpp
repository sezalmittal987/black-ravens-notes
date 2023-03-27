/*
https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
*/

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    Node* ans = NULL;
    Node* last = head;
    for( int i = 0 ; i < n -1 ; i++ ){
        last = last -> next;
        if( last == NULL) return -1;
    }
    ans = head;
    while( last ->next != NULL){
        last = last -> next;
        ans = ans->next;
    }
    return ans->data;
}

