#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    for (int i = 0; i < nums.size(); i++) {

        cout << "\n===== i = " << i << " =====\n";

        for (int end = nums.size() - 1; end >= i; end--) {

            cout << "end = " << end << " -> Printing subarray: ";

            for (int start = i; start <= end; start++) {

                cout << "[start=" << start
                     << ", nums[" << start << "]="
                     << nums[start] << "] ";
            }

            cout << endl;
        }
    }

    return 0;
}