#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

/*
Approach:
- Count the frequency of each character using unordered_map
- Push (frequency, character) into a max heap (priority_queue)
- Repeatedly pop from the heap and append the character 'frequency' times

Time Complexity:
- O(n log k), where n = length of string, k = number of unique characters
Space Complexity:
- O(k) for unordered_map and priority_queue
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char_count;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            char_count[ch]++;
        }

        // Step 2: Max heap storing (frequency, character)
        priority_queue<pair<int, char>> pq;
        for (auto it : char_count) {
            pq.push({it.second, it.first});
        }

        string result = "";

        // Step 3: Build result string by popping from heap
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            // Append character 'frequency' times
            result += string(top.first, top.second);
        }

        return result;
    }
};

// Sample test cases
int main() {
    Solution sol;
    cout << sol.frequencySort("tree") << endl;    // eetr / eert
    cout << sol.frequencySort("cccaaa") << endl;  // cccaaa / aaaccc
    cout << sol.frequencySort("Aabb") << endl;    // bbAa / bbaA
    return 0;
}
