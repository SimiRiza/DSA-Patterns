// Approach: Sliding Window
// Description: Maintain a window of size k and count vowels inside it.
// Slide the window and update the count efficiently.

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
        int start=0,end=0,count=0;

        // Build first window
        while(end < k){
            if (isVowel(s[end]))
                count++;
            end++;
        }

        int max_vowels = count;

        // Sliding window
        while(end < s.length()){
            if (isVowel(s[start]))
                count--;
            start++;

            if (isVowel(s[end]))
                count++;
            end++;

            max_vowels = max(count,max_vowels);
        }

        return max_vowels;
    }
};

int main() {
    Solution obj;

    // Test 1
    cout << obj.maxVowels("abciiidef", 3) << endl; // Expected: 3

    // Test 2
    cout << obj.maxVowels("aeiou", 2) << endl; // Expected: 2

    return 0;
}