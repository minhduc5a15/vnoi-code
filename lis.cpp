#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> lis;
    while (n--) {
        int x;
        cin >> x;
        if (lis.empty() || lis.back() < x) {
            lis.push_back(x);
        }
        *lower_bound(lis.begin(), lis.end(), x) = x;
    }
    cout << lis.size();
    return 0;
}
