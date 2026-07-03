#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;


// ======================================================
// PRIORITY QUEUE (MAX HEAP)
// - Insert elements
// - Print elements in descending order
// ======================================================

// int main() {
//     priority_queue<int> pq; // max heap
//     int n;
//     cin >> n;
//     int num;

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         pq.push(num);
//     }

//     while (!pq.empty()) {
//         cout << pq.top() << " ";
//         pq.pop();
//     }
// }


// ======================================================
// DEQUE (DOUBLE ENDED QUEUE)
// - Push/Pop from both front and back
// ======================================================

// int main() {
//     deque<int> dq;

//     dq.push_back(20);    // 20
//     dq.push_front(10);   // 10 20
//     dq.push_back(30);    // 10 20 30
//     dq.push_front(5);    // 5 10 20 30

//     cout << "Front: " << dq.front() << endl;
//     cout << "Back: " << dq.back() << endl;

//     dq.pop_front();      // 10 20 30
//     dq.pop_back();       // 10 20

//     while (!dq.empty()) {
//         cout << dq.front() << " ";
//         dq.pop_front();
//     }
// }


// ======================================================
// QUEUE (FIFO)
// - Push, Front, Back, Pop
// ======================================================

// int main() {
//     queue<int> q;
//     int n;
//     cin >> n;
//     int num;

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         q.push(num);
//     }

//     cout << "Element at front: " << q.front() << endl;
//     cout << "Element at back: " << q.back() << endl;

//     while (!q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
// }


// ======================================================
// STACK (LIFO)
// - Push, Top, Pop
// ======================================================

// int main() {
//     stack<int> st;
//     int n;
//     cin >> n;
//     int num;

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         st.push(num);
//     }

//     cout << st.top() << endl;
//     st.pop();
//     cout << st.top() << endl;

//     while (!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }


// ======================================================
// UNORDERED MAP
// - Frequency Counting
// ======================================================

// int main() {
//     unordered_map<int, int> mp;
//     int n;
//     cin >> n;
//     int num;
//     vector<int> v(n);

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         v[i] = num;
//     }

//     for (int num : v) {
//         mp[num]++;
//     }

//     for (auto map_obj : mp) {
//         cout << "Number " << map_obj.first
//              << " occurred " << map_obj.second << endl;
//     }
// }


// ======================================================
// MAP
// - Store Student Marks
// - Search using count()
// ======================================================

// int main() {
//     map<string, int> mp;
//     int n;
//     cin >> n;
//     int marks;
//     string name;

//     while (n) {
//         cin >> name;
//         cin >> marks;
//         mp[name] = marks;
//         n--;
//     }

//     string findnam;
//     cin >> findnam;

//     if (mp.count(findnam))
//         cout << "Name present" << endl;
//     else
//         cout << "Not present" << endl;

//     for (auto map_obj : mp) {
//         cout << "Student " << map_obj.first
//              << " scored " << map_obj.second << endl;
//     }
// }


// ======================================================
// PAIR
// - Store Two Different Data Types Together
// ======================================================

// int main() {
//     pair<int, string> p;
//     int num;
//     string str;

//     cin >> num;
//     cin >> str;

//     p = make_pair(num, str);

//     cout << p.first << " " << p.second;
//     return 0;
// }


// ======================================================
// STL ALGORITHMS
// - sort()
// - greater<int>()
// - reverse()
// - max_element()
// - min_element()
// ======================================================

// int main() {
//     int n;
//     cin >> n;
//     int num;
//     vector<int> v;

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         v.push_back(num);
//     }

//     sort(v.begin(), v.end());

//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";
//     }

//     cout << "\nDescending Order\n";

//     sort(v.begin(), v.end(), greater<int>());

//     for (int num : v) {
//         cout << num << " ";
//     }

//     cout << "\nReverse\n";

//     reverse(v.begin(), v.end());

//     for (int num : v) {
//         cout << num << " ";
//     }

//     cout << endl;
//     cout << "Max Element: " << *max_element(v.begin(), v.end()) << endl;
//     cout << "Min Element: " << *min_element(v.begin(), v.end()) << endl;

//     return 0;
// }


// ======================================================
// REVERSE AN ARRAY
// - Using swap()
// ======================================================

// int main() {
//     int n;
//     cin >> n;
//     int num;
//     vector<int> v(n);

//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         v[i] = num;
//     }

//     for (int i = 0; i < n / 2; i++) {
//         swap(v[i], v[n - 1 - i]);
//     }

//     for (int i = 0; i < n; i++) {
//         cout << v[i] << " ";
//     }

//     return 0;
// }


// ======================================================
// FIND MAXIMUM ELEMENT IN AN ARRAY
// ======================================================

// int main() {
//     int n;
//     cin >> n;
//     int maximum = INT_MIN;
//     int num;

//     while (n) {
//         cin >> num;
//         maximum = max(maximum, num);
//         n--;
//     }

//     cout << "Maximum Element: " << maximum;

//     return 0;
// }