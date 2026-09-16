/*
Approach:
- Each email is treated as a node.
- Emails belonging to the same account are connected using DSU.
- After merging, group emails by their parent.
- Add the account name to each merged group.

Time Complexity: O(N * alpha(N)) approximately
Space Complexity: O(N)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class DSU {
    vector<int> p, r;

public:
    DSU(int n) {
        p.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (r[a] < r[b])
            swap(a, b);

        p[b] = a;

        if (r[a] == r[b])
            r[a]++;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        unordered_map<string, int> id;
        vector<string> em;
        int n = 0;

        for (auto &x : a) {
            for (int i = 1; i < x.size(); i++) {
                if (!id.count(x[i])) {
                    id[x[i]] = n++;
                    em.push_back(x[i]);
                }
            }
        }

        DSU d(n);

        for (auto &x : a) {
            int f = id[x[1]];

            for (int i = 2; i < x.size(); i++)
                d.unite(f, id[x[i]]);
        }

        map<int, vector<string>> g;

        for (auto &e : em)
            g[d.find(id[e])].push_back(e);

        vector<vector<string>> ans;

        for (auto &[root, v] : g) {
            sort(v.begin(), v.end());

            vector<string> cur;
            cur.push_back(a[0][0]);

            // Find account name using any email in this group
            string name;
            for (auto &x : a) {
                for (int i = 1; i < x.size(); i++) {
                    if (d.find(id[x[i]]) == root) {
                        name = x[0];
                        break;
                    }
                }
                if (!name.empty())
                    break;
            }

            cur[0] = name;
            cur.insert(cur.end(), v.begin(), v.end());
            ans.push_back(cur);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<vector<string>> a1 = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    vector<vector<string>> a2 = {
        {"Gabe", "gabe@mail.com", "g@mail.com"},
        {"Gabe", "g@mail.com", "g2@mail.com"}
    };

    auto r1 = s.accountsMerge(a1);
    auto r2 = s.accountsMerge(a2);

    for (auto &x : r1) {
        for (auto &e : x) cout << e << " ";
        cout << '\n';
    }

    cout << '\n';

    for (auto &x : r2) {
        for (auto &e : x) cout << e << " ";
        cout << '\n';
    }

    return 0;
}