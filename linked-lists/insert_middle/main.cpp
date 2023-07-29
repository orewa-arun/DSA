#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
};

// outline functions
void insert_node(int n,Node ** head_ptr){
    // cout << "After function" << endl;
    // cout << head_ptr << endl;
    // cout << *head_ptr << endl;

    Node * head = *head_ptr;

    Node * new_node = new Node;
    new_node->next = head;
    new_node->val = n;

    *head_ptr = new_node;

    // cout << "After new node" << endl;
    // cout << head_ptr << endl;
    // cout << *head_ptr << endl;
    // cout << head << endl;
}

// outline functions
void display_all(Node ** head_ptr){
    Node * tmp = *head_ptr;

    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int total_elements(Node ** head_ptr){
    Node * tmp = * head_ptr;
    int count = 0;

    while(tmp != NULL){
        tmp = tmp->next;
        count++;
    }

    return count;
}

void insert_node_middle(int n,Node ** head_ptr){
    int total = total_elements(head_ptr);

    Node * tmp = *head_ptr;

    // because the tmp already starts from head
    // i.e it started with first position
    for(int i=1; i< total/2; ++i){
        tmp = tmp->next;
    }

    Node * new_node = new Node;
    new_node->next = tmp->next;
    new_node->val = n;

    tmp->next = new_node;
}

int main(){
    Node * head =  NULL;

    // cout << &head << endl;
    // cout << head <<  endl;

    insert_node(1,&head);
    insert_node(2,&head);
    insert_node(3,&head);
    insert_node(4,&head);

    insert_node_middle(10,&head);
    
    display_all(&head);
}