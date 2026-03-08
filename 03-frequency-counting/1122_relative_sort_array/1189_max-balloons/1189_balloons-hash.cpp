/*
Approach: Frequency Map (Hash Map)

We count the frequency of every character in the input string.
To form the word "balloon", we need:
b -> 1
a -> 1
l -> 2
o -> 2
n -> 1

The number of times we can form "balloon" is limited by the
minimum available required characters.

Time Complexity: O(n)
Space Complexity: O(1)  (only 26 possible characters)
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;

        for(char ch : text){
            freq[ch]++;
        }

        int no_of = 0;

        if(freq.find('b')!=freq.end()){
            no_of = freq['b'];
        }
        else{
            no_of=0;
        }

        if(freq.find('a')!=freq.end()){
            no_of = min(freq['a'],no_of);
        }
        else{
            no_of=0;
        }

        if(freq.find('l')!=freq.end()){
            if(freq['l']>=2)
                no_of = min(freq['l']/2,no_of);
            else{
                no_of = 0;
                return 0;
            }
        }

        if(freq.find('o')!=freq.end()){
            if(freq['o']>=2)
                no_of = min(freq['o']/2,no_of);
            else{
                no_of = 0;
                return 0;
            }
        }

        if(freq.find('n')!=freq.end()){
            no_of = min(freq['n'],no_of);
        }
        else{
            no_of = 0;
        }

        return no_of;
    }
};

int main() {
    Solution sol;

    string test1 = "nlaebolko";
    cout << "Test 1 Output: " << sol.maxNumberOfBalloons(test1) << endl; // Expected 1

    string test2 = "loonbalxballpoon";
    cout << "Test 2 Output: " << sol.maxNumberOfBalloons(test2) << endl; // Expected 2

    return 0;
}