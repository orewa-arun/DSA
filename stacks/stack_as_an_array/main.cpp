#include<iostream>
using namespace std;

// alias
#define MAX_SIZE 1000

class Stack{
    private:
        int top;
        int arr[MAX_SIZE];
    
    public:
        Stack(){
            top = -1;
        }

        bool push(int ele){
            // we add elements to stack from top = 0 to top = 999
            if(top >= (MAX_SIZE - 1)){
                cout << "stack is full";
                return false;
            }else{
                // pre-increment operator must be used not post-increment
                // increment top and then add ele to the array
                arr[++top] = ele;
                return true;
            }
        } 

        int pop(){
            if(top == -1){
                cout << "stack is empty";
                return 0;
            }
            return arr[top--]; // Return top element and decrement top index
        }

        int peek(){
            if(top == -1){
                cout << "stack is empty";
                return 0;
            }
            return arr[top];
        }

        bool isEmpty(){
            return (top == -1);
        }

        void display(){
            if(top == -1){
                cout <<"stack is empty";
                return;
            }else{
                for(int i = 0; i<=top; ++i){
                    cout << arr[i] << endl;
                }
            }
        }
};

int main(){
    Stack s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(10);

    cout << s.pop() <<"\n";

    s.display();
    return 0;
}