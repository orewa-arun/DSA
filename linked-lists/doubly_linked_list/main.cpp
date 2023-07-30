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

void insert_at_n_from_head(int n, int data, Node ** head_ptr){
    Node * tmp = *head_ptr;

    for(int i=1 ; i<(n-1); ++i){
        if(tmp == NULL){
            return;
        }
        tmp = tmp->next;
    }

    Node * new_node = new Node;
    new_node->data = data;
    new_node->next = tmp->next;
    new_node->prev = tmp;
    tmp->next = new_node;

    tmp = new_node->next;

    if(tmp != NULL){
        tmp->prev = new_node;
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

    insert_at_n_from_head(3,40,&head);

    display_all(&head);

    reverse(&head);

    display_all(&head);

    return 0;
}