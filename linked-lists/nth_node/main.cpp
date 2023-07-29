#include<iostream>

using namespace std;

struct Node{
    int val;
    Node * next;
};

// outline function
void insert_node(int n,Node ** head_ptr){
    Node * head = * head_ptr;

    Node * new_node = new Node;
    new_node->val = n;
    new_node->next = head;

    *head_ptr = new_node;
}

int get_nth(int n, Node ** head_ptr){
    
    Node * tmp = * head_ptr;

    for(int i=1; i<n; ++i){
        if (tmp == NULL){
            return -1;
        }
        tmp = tmp->next;
    }
    
    return tmp->val;
}

void display_all(Node **head_ptr){
    Node * tmp = * head_ptr;

    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }    
}

int main(){
    Node * head = NULL;

    for (int i=0 ; i<7 ; ++i){
        insert_node(i*3,&head);
    }

    display_all(&head);

    int n = 4;
    cout << n << "th element is" << " " << get_nth(n,&head) << endl;

    return 0;
}