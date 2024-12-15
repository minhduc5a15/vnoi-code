#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    multiset<int> s;
    int type;
    while (true) {
        cin >> type;
        if (type == 0) break;
        else if (type == 1) {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (type == 2) {
            int x;
            cin >> x;
            s.erase(x);
        }
        else if (type == 3) {
            if (s.empty()) cout << "empty\n";
            else cout << *s.begin() << '\n';
        }
        else if (type == 4) {
            if (s.empty()) cout << "empty\n";
            else cout << *(--s.end()) << '\n';
        }
        else if (type == 5) {
            int x;
            cin >> x;
            if (s.empty()) {
                cout << "empty\n";
            }
            else {
                auto it = s.upper_bound(x);
                if (it == s.end()) {
                    cout << "no\n";
                }
                else {
                    cout << *it << '\n';
                }
            }
        }
        else if (type == 6) {
            int x;
            cin >> x;
            if (s.empty()) {
                cout << "empty\n";
            }
            else {
                auto it = s.lower_bound(x);
                if (it == s.end()) cout << "no\n";
                else cout << *it << '\n';
            }
        }
        else if (type == 7) {
            int x;
            cin >> x;
            if (s.empty()) {
                cout << "empty\n";
            }
            else {
                auto it = s.lower_bound(x);
                if (it == s.begin()) cout << "no\n";
                else cout << *(--it) << '\n';
            }
        }
        else if (type == 8) {
            int x;
            cin >> x;
            if (s.empty()) {
                cout << "empty\n";
            }
            else {
                auto it = s.upper_bound(x);
                if (it == s.begin()) cout << "no\n";
                else cout << *(--it) << '\n';
            }
        }
    }
    return 0;
}
