/*
 * Problem:
 * LeetCode 841 - Keys and Rooms
 *
 * Approach:
 * 1. Treat each room as a node in a graph.
 * 2. Start a Breadth-First Search (BFS) from room 0.
 * 3. Whenever a key to an unvisited room is found,
 *    mark the room as visited and add it to the queue.
 * 4. After BFS completes, check whether every room
 *    has been visited.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> visited(rooms.size());

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            for (auto roomno : rooms[q.front()]) {
                if (!visited[roomno]) {
                    visited[roomno] = 1;
                    q.push(roomno);
                }
            }

            q.pop();
        }

        for (int visit : visited) {
            if (!visit)
                return false;
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> rooms = {
        {1},
        {2},
        {3},
        {}
    };

    if (obj.canVisitAllRooms(rooms))
        cout << "All rooms can be visited." << endl;
    else
        cout << "All rooms cannot be visited." << endl;

    return 0;
}