# Problem: D. Cutting a graph - https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class DisjointSet {
    public:
        vector<int> parent;
        DisjointSet(int n) : parent(n) {
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int Find(int x) {
            int curr = x;
            while (curr != parent[curr]) {
                curr = parent[curr];
            }

            while (x != parent[x]) {
                int nx = parent[x];
                parent[x] = curr;
                x = nx;
            }

            return curr;
        }

        void Union(int x, int y) {
            int X = Find(x), Y = Find(y);
            if (X != Y) {
                parent[X] = Y;
            }
        }
};

int main() {
    int n, edges, ops;
    cin >> n >> edges >> ops;
    DisjointSet dsj(n+1);

    for (; edges > 0; edges--) {
        int a, b;
        cin >> a >> b;
    }

    vector<tuple<string, int, int>> operations;
    for (; ops > 0; ops--) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        operations.push_back({a, b, c});
    }
    
    vector<string> res;
    for (int i = size(operations) - 1; i >= 0; i--) {
        if (get<0>(operations[i]) == "ask") {
            if (dsj.Find(get<1>(operations[i])) == dsj.Find(get<2>(operations[i]))) {
                res.push_back("YES");
            } else { 
                res.push_back("NO");
            }
        } else {
            dsj.Union(get<1>(operations[i]), dsj.Find(get<2>(operations[i])));
        }
    }

    for (int i = size(res)-1; i >= 0; i--) cout << res[i] << endl;
}