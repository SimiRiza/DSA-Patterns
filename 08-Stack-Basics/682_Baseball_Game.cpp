// LC Baseball Game
// Approach: Stack Simulation
// We simulate operations using a stack and compute final sum

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int total_sum = 0;
        int last_start= 0, sec_start=0;

        for(string ch : operations){

            if(ch=="C"){
                if(!st.empty())
                    st.pop();
            }
            else if(ch=="D"){
                st.push((st.top())*2);
            }
            else if(ch=="+"){
                if(!st.empty()){
                    last_start = st.top();
                    st.pop();
                    if(!st.empty()){
                        sec_start = st.top();
                        st.pop();

                        // restore in correct order
                        st.push(sec_start);
                        st.push(last_start);

                        st.push((last_start) + sec_start);    
                    }
                }
            }
            else{
                int num = stoi(ch);
                st.push(num);
            }
        }

        while(!st.empty()){
            total_sum += st.top();
            st.pop();
        }

        return total_sum;
    }
};

// ---- Main with 2 test cases ----
int main() {
    Solution obj;

    vector<string> t1 = {"5","2","C","D","+"};
    cout << "Output1: " << obj.calPoints(t1) << endl; // Expected: 30

    vector<string> t2 = {"5","-2","4","C","D","9","+","+"};
    cout << "Output2: " << obj.calPoints(t2) << endl; // Expected: 27

    return 0;
}