#include<iostream>

using namespace std;

struct Node{
    int val;
    // Node pointer named next
    Node* next;
};

// Defining a Node ptr named head as NULL
Node * head = NULL;

// nodes are inserted backwardly
void insert_node(int n){
    Node * new_node = new Node;
    new_node->val = n;
    new_node->next = head;

    head = new_node;
}

void display_all_nodes(){
    Node * traverse_ptr = head;

    while(traverse_ptr != NULL){
        cout << "Node details : " << endl;
        cout << traverse_ptr << endl;
        cout << traverse_ptr->next << endl;
        cout << traverse_ptr->val << endl;
        traverse_ptr = traverse_ptr->next;
    }
}

int main(){
    // cout << head << endl;
    // cout << &head << endl;
    insert_node(1);
    insert_node(2);
    insert_node(3);

    display_all_nodes();
}