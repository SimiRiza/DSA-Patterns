// Approach: Sliding Window
// We maintain a window of size k and count vowels efficiently while sliding.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();

        // Step 1: count vowels in first window
        int count = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) count++;
        }

        int maxCount = count;

        // Step 2: slide the window
        for(int i = k; i < n; i++){
            // remove left char
            if(isVowel(s[i - k])) count--;

            // add right char
            if(isVowel(s[i])) count++;

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

// ----------- MAIN FUNCTION (for testing) -----------
int main() {
    Solution sol;

    // Test 1
    string s1 = "abciiidef";
    int k1 = 3;
    cout << sol.maxVowels(s1, k1) << endl; // Expected: 3

    // Test 2
    string s2 = "aeiou";
    int k2 = 2;
    cout << sol.maxVowels(s2, k2) << endl; // Expected: 2

    return 0;
}