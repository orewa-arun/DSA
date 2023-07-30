#include<iostream>

using namespace std;

struct Node{
    int val;
    Node * next;
};

// outline function
void insert_node(int n, Node ** head_ptr){
    Node * head = * head_ptr;

    Node * new_node = new Node;
    new_node->val = n;
    new_node->next = head;

    *head_ptr = new_node;
}

void delete_at_n(int n, Node ** head_ptr){
    Node * tmp = * head_ptr;

    for(int i=1; i<(n-1); ++i){
        if(tmp == NULL){
            return;
        }
        tmp = tmp->next;
    }

    Node * delete_element = tmp->next;
    tmp->next = (tmp->next)->next;
    delete delete_element;
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

int get_length(Node ** head_ptr ){
    Node * tmp = * head_ptr;
    
    int len = 0;
    while( tmp != NULL){
        tmp = tmp->next;
        len++;
    }

    return len;
}

int k_from_middle_towards_head(int k, Node ** head_ptr){
    int length = get_length(head_ptr);

    Node * tmp = * head_ptr;

    for ( int i=1; i<(length/2 + 1 - k); ++i){
        tmp = tmp->next;
    }

    return tmp->val;
}


int main(){
    Node * head = NULL;

    for (int i=0 ; i<7 ; ++i){
        insert_node(i*3,&head);
    }

    int n = 7;
    int k = 2;
    cout << n << "th element is" << " " << get_nth(n,&head) << endl << endl;
    cout << k << "th element from middle is" << " " << k_from_middle_towards_head(k,&head) << endl << endl;

    insert_at_nth(4,50,&head);
    delete_at_n(5,&head);
    
    display_all(&head);

    return 0;
}