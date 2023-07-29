#include<iostream>

using namespace std;

struct Node{
    int val;
    Node * next;
};

Node * head = NULL;

void insert_node(int n){
    // pointer to a new Node
    Node * new_node = new Node;
    // accessing the new node attributes using the new_node pointer 
    // and -> operator
    new_node->val = n;
    new_node->next = head;
    head = new_node;
}

void reverse(){
    Node * current = head;
    Node * prev = NULL;
    Node * next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;

        // Advance prev and current by one pos
        prev = current;
        current = next;
    }

    head = prev;
}

void display_all(){
    Node * tmp =  head;

    while(tmp != NULL){
        cout << "Node details :" << endl;
        cout << tmp << endl;
        cout << tmp->next << endl;
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int main(){
    insert_node(10);
    insert_node(9);
    insert_node(8);
    insert_node(7);
    insert_node(6);
    insert_node(5);

    display_all();

    reverse();

    display_all();
}