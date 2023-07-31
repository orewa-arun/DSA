#include<iostream>

using namespace std;

struct Node{
    int data;
    Node * next;
};

class Stack{
    private:
        Node * top;

    public:
        Stack(){
            top = NULL;
        }  

        void push(int n){
            
            Node * new_node = new Node;
            new_node->data = n;
            new_node->next = top;

            top = new_node;
        }

        int pop(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return -1;
            }

            Node * tmp = top;
            int data = tmp->data;
            top = top->next;

            delete tmp;
            return data;
        }

        void display(){

            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }   

            Node * tmp = top;

            cout << "Stack elements are : " << endl;
            while(tmp != NULL){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }

        int peek(){
            return top->data;
        }

        bool isEmpty(){
            return (top == NULL);
        }
};

void sort(Stack * s){
    Stack tmp;

    while(!s->isEmpty()){
        int x = s->pop();

        while(!tmp.isEmpty() && tmp.peek() > x){
            s->push(tmp.pop());
        }

        tmp.push(x);
    }

    while(!tmp.isEmpty()){
        s->push(tmp.pop());
    }
}

void insert_at_nth(int data,int n,Stack * s){
    Stack tmp;

    for(int i=0; i<(n-1); ++i){
        tmp.push(s->pop());
    }

    s->push(data);

    while(!tmp.isEmpty()){
        s->push(tmp.pop());
    }
}

void delete_at_nth(int n,Stack * s){
    Stack tmp;

    for(int i=0; i<(n-1); ++i){
        tmp.push(s->pop());
    }
    
    s->pop();

    while(!tmp.isEmpty()){
        s->push(tmp.pop());
    }
}

bool is_present_in_tmp(int x, int * arr, int len){
    for(int i=0; i<len; ++i){
        if(arr[i] == x){
            return true;
        }
    }

    return false;
}


void remove_recurrences(Stack * s){
    int * tmp = new int[100];
    int len = 0;

    while(!s->isEmpty()){
        int x = s->pop();

        bool check = is_present_in_tmp(x,tmp,len);

        if(!check){
            tmp[len++] = x;
        }
    }

    //copy all array elements into stack
    for(int i=0; i<len; ++i){
        s->push(tmp[len - 1 - i]);
    }

}

int main(){
    Stack s;

    for(int i=0; i<5; ++i){
        s.push(i+1);
    }

    s.push(5);
    s.push(7);
    s.push(2);
    s.push(1);

    // int x = s.pop();

    // cout << "popped element is " << x << endl;

    sort(&s);
    insert_at_nth(10,3,&s);
    delete_at_nth(3,&s);
    remove_recurrences(&s);

    s.display();
}