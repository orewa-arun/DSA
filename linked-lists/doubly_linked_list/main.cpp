#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * prev;
    Node * next;
};

void append_data(Node ** head_ptr, int data){

    Node * new_node = new Node;
    new_node->data = data;
    new_node->next = * head_ptr;
    new_node->prev = NULL;

    if(* head_ptr != NULL){
        (*head_ptr)->prev = new_node;
    }

    *head_ptr = new_node;
}

void display_all(Node ** head_ptr){
    Node * tmp = * head_ptr;
    Node * end = NULL;

    cout << "traversersal forward " << endl;

    while(tmp != NULL){
        cout << tmp->data << endl;
        end = tmp;
        tmp = tmp->next;
    }

    cout << "traversersal backward " << endl;

    while(end !=NULL){
        cout << end->data << endl;
        end = end->prev;
    }
}

void reverse(Node ** head_ptr){
    Node * current = * head_ptr;
    Node * next = NULL;
    
    while( current != NULL){
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        *head_ptr = current;
        current = next;
    }
}

int main(){
    Node * head = NULL;

    for( int i=0; i<10; ++i){
        append_data(&head,i*3);
    }

    display_all(&head);

    reverse(&head);

    display_all(&head);

    return 0;
}