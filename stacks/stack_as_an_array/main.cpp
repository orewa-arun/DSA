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

        int length(){
            return (top + 1);
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


        void sort(){
            
            Stack tmp;

            while(!isEmpty()){
                int x = pop();
                
                // if tmp ele > x, then remove in tmp until tmp is sorted when x is added 
                // i.e remove until x is the largest element in tmp
                while(!tmp.isEmpty() && tmp.peek() > x){
                    push(tmp.pop());
                }

                // append when tmp.peek() < x
                // i.e when tmp is sorted
                tmp.push(x);
            }

            // descending order
            while(!tmp.isEmpty()){
                push(tmp.pop());
            }
        }
};

// s passed as reference
void reverse(Stack * s){
    
    // s->top = -1; // inaccessible in outline functions
    int n = s->length();
    int * arr = new int[n];

    int i=0;
    while(!s->isEmpty()){
        arr[i++] = s->pop();
    }

    for(int i=0; i<n; ++i){
        s->push(arr[i]);
    }
}

// s passed as value
float average(Stack s){
    int sum = 0;
    int length = s.length();

    while(!s.isEmpty()){
        sum += s.pop();
    }

    return (float) sum/length;
}

// s passed as value
int largest_number(Stack s){
    int largest = -1;

    while(!s.isEmpty()){
        int x = s.pop();
        if(largest < x){
            largest = x;
        }
    }

    return largest;
}

void insert_at_nth(int data, int n, Stack * s){

    int len = s->length();
    Stack tmp;

    for(int i=0; i< (len - n + 1); ++i){
        tmp.push(s->pop());
    }

    s->push(data);

    while(!tmp.isEmpty()){
        s->push(tmp.pop());
    }
}

int main(){
    Stack s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(4);

    // cout << s.pop() <<"\n";

    s.sort();
    // s.display();

    reverse(&s);

    cout << "Average value of stack : " << average(s) << endl;
    cout << "Largest value of stack : " << largest_number(s) << endl;

    insert_at_nth(100,4,&s);
    s.display();

    return 0;
}