#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    ordered_set s;
    while (t--) {
        char operation;
        int x;
        cin >> operation >> x;
        if (operation == 'I') {
            s.insert(x);
        }
        else if (operation == 'D') {
            s.erase(x);
        }
        else if (operation == 'K') {
            if (x > (int) s.size()) {
                cout << "invalid\n";
            }
            else {
                cout << *s.find_by_order(x - 1) << "\n";
            }
        }
        else if (operation == 'C') {
            cout << s.order_of_key(x) << "\n";
        }
    }

    return 0;
}
