
/*
    Two Heaps | Data Stream | Dynamic Median

    Approach:
    - Max Heap stores the smaller half.
    - Min Heap stores the larger half.
    - Max Heap can have at most one extra element.
    - Rebalance whenever heap sizes differ by more than 1.
    - Median is calculated from heap tops.

    Time Complexity:
    addNum()    : O(log n)
    findMedian(): O(1)

    Space Complexity:
    O(n)

    Self Note:
    1. C++ size_t trap: Never subtract unsigned sizes directly (a.size() - b.size()), as underflow can wrap into a huge positive number.  
    Compare first (a.size() > b.size() + 1) to avoid underflow!
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;

    MedianFinder() {}

    void addNum(int num) {
        if(max_heap.empty()){
            max_heap.push(num);
        }
        else if(num < max_heap.top()){
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }

        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size() + 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if(max_heap.size() == min_heap.size()){
            return ((double)max_heap.top() + min_heap.top())/2.0;
        }
        else return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 1.5

    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2

    return 0;
}
