#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Approach: Monotonic Decreasing Stack

- Store indices of previous stock prices in a stack.
- Remove all indices whose prices are less than or equal to
  the current price because they can never be the answer
  for future span calculations.

Time Complexity:
- Amortized O(1) per next() call
Space Complexity:
- O(n)
*/
class StockSpanner {
public:
    stack<int> st;      // Stores indices of prices
    vector<int> arr;    // Stores all stock prices

    StockSpanner() {

    }

    int next(int price) {

        // Add current price to history
        arr.push_back(price);

        int count = 1;

        // Remove all smaller/equal prices
        while (!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }

        // If no greater element exists on the left,
        // span covers all days seen so far
        if (st.empty())
            count = arr.size();
        else
            count = arr.size() - st.top() - 1;

        // Store current index
        st.push(arr.size() - 1);

        return count;
    }
};

int main() {

    StockSpanner sp;

    // Test Case 1
    cout << sp.next(100) << endl; // 1
    cout << sp.next(80)  << endl; // 1
    cout << sp.next(60)  << endl; // 1
    cout << sp.next(70)  << endl; // 2
    cout << sp.next(60)  << endl; // 1
    cout << sp.next(75)  << endl; // 4
    cout << sp.next(85)  << endl; // 6

    return 0;
}
/*
Self Note:
- Don't actually need the arr vector.
- A cleaner solution stores {price, span} pairs directly
  in the stack and accumulates spans while popping.
*/