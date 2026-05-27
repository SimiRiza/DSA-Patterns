/*
Approach: Queue Rotation Simulation
Description:
- Put all students into a queue.
- If front student's preference matches current sandwich,
  student takes sandwich and leaves.
- Otherwise move student to back of queue.
- Use "attempts" as a counter to detect if all remaining
  students rotated once without taking a sandwich.
- If that happens, no further progress is possible.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> studentQueue;

        // Convert students vector into queue
        for(int studentPreference : students){
            studentQueue.push(studentPreference);
        }

        int sandwichIndex = 0;

        // Buffer size -> number of students still waiting
        int remainingStudents = students.size();

        // Tracks unsuccessful rotations
        int attempts = 0;

        while(!studentQueue.empty()){

            // Take front student
            int currentStudent = studentQueue.front();
            studentQueue.pop();

            // Student likes current sandwich
            if(currentStudent == sandwiches[sandwichIndex]){

                // Move to next sandwich
                sandwichIndex++;

                // One student leaves queue
                remainingStudents--;

                // Reset because progress happened
                attempts = 0;
            }
            else{
                // Move student to back of queue
                studentQueue.push(currentStudent);

                // One unsuccessful try
                attempts++;
            }

            // Entire remaining queue rotated once
            // and nobody took sandwich
            if(attempts == remainingStudents){
                break;
            }
        }

        return remainingStudents;
    }
};

int main() {

    Solution obj;

    // Test 1
    vector<int> students1 = {1,1,0,0};
    vector<int> sandwiches1 = {0,1,0,1};

    cout << "Test 1: "
         << obj.countStudents(students1, sandwiches1)
         << endl;

    // Test 2
    vector<int> students2 = {1,1,1,0,0,1};
    vector<int> sandwiches2 = {1,0,0,0,1,1};

    cout << "Test 2: "
         << obj.countStudents(students2, sandwiches2)
         << endl;

    return 0;
}