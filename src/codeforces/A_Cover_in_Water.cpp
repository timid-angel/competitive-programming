#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (; n > 0; n--) {
        int l;
        cin >> l;

        string s;
        cin >> s;

        int curr = 0, mx = 0, c = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '.') {
                curr += 1;
                mx = max(mx, curr);
                c += 1;
            } else {
                curr = 0;
            }
        }

        if (mx > 2) cout << 2 << endl;
        else cout << c << endl;
    }
}