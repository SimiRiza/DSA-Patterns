#include <iostream>
#include <queue>
using namespace std;

/*
Approach: Single Queue Rotation
- Use one queue
- For pop(): rotate (size-1) elements to back so last element comes to front
- Then remove it
*/

class MyStack {
private:
    queue<int> q;   // internal queue

public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);  // simply push to back
    }
    
    int pop() {
        int i = q.size() - 1;

        // rotate first (n-1) elements to back
        while(i != 0){
            int front_e = q.front();
            q.push(front_e);
            q.pop();
            i--;
        }

        // now last inserted element is at front
        int num = q.front();  
        q.pop();              // remove it
        return num;
    }
    
    int top() {
        // last inserted element is always at back (without rotation)
        return q.back();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/*
Self Notes:
- queue = FIFO → only front removal allowed
- trick = rotate elements to simulate LIFO
- pop() is O(n), push() is O(1)
*/

int main() {
    MyStack* obj = new MyStack();

    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl; // 2

    cout << obj->pop() << endl; // 2
    cout << obj->empty() << endl; // false

    return 0;
}