#include<iostream>

using namespace std;

# define MAX_SIZE 1000

class Queue{
    private :
        int front = -1;
        int back = -1;
        int arr[MAX_SIZE];

    public :

        void enqueue(int data){

            if (back == MAX_SIZE - 1){
                cout << "Queue is full!" << endl;
            }

            if (front == -1){
                front = 0;
            }

            arr[++back] = data;
        }

        int dequeue(){
            if(front == -1){
                cout << "queue is empty" << endl;
            }

            // only one element is left
            if(front == back){
                int x = arr[front];
                front = -1;
                back = -1;
                return x;
            }
            
            return arr[front++];
        }

        void display(){

            if(front == -1){
                cout<<"Queue is empty" << endl;
                return;
            }

            cout << "Queue elements are : ";
            for(int i=front; i<(back+1); ++i){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        int peekRear(){
            return arr[back];
        }

        int peekFront(){
            return arr[front];
        }

};

int main(){

    Queue q;

    q.enqueue(9);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}