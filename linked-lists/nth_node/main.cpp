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

void insert_at_nth(int n, int ele, Node ** head_ptr){
    Node * tmp = * head_ptr;

    for(int i=1; i<(n-1); ++i){
        if(tmp == NULL){
            return;
        }
        tmp = tmp->next;
    }

    Node * new_node = new Node;
    new_node->val = ele;
    new_node->next = tmp->next;

    tmp->next = new_node;
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

    int n = 7;
    cout << n << "th element is" << " " << get_nth(n,&head) << endl << endl;

    insert_at_nth(4,50,&head);
    display_all(&head);

    return 0;
}