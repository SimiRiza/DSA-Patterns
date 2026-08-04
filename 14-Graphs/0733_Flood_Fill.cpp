/*
 * Problem:
 * LeetCode 733 - Flood Fill
 *
 * Approach:
 * 1. Store the original color of the starting pixel.
 * 2. If the original color is the same as the new color,
 *    return the image to avoid infinite recursion.
 * 3. Perform DFS from the starting pixel.
 * 4. Recolor the current pixel and recursively visit all
 *    four adjacent pixels having the original color.
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m) (recursion stack in the worst case)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void change_neighbor(int orig_color, int i, int j,
                         int color, vector<vector<int>>& image) {

        image[i][j] = color;

        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = drow[k] + i;
            int nc = dcol[k] + j;

            if (nr >= 0 && nr < image.size() &&
                nc >= 0 && nc < image[0].size()) {

                if (image[nr][nc] == orig_color)
                    change_neighbor(orig_color, nr, nc, color, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int orig_color = image[sr][sc];

        if (orig_color == color)
            return image;

        change_neighbor(orig_color, sr, sc, color, image);

        return image;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> ans = obj.floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";
    for (const auto& row : ans) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}