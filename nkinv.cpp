#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 600005;

vector<int> BIT(MAXN);

void update(int id, int val) {
    if (id <= MAXN) return BIT[id] += val, update(id + (id & -id), val);
}

long long get(int id) {
    return !id ? 0 : BIT[id] + get(id - (id & -id));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int count = 0;
    while (n--) {
        int x;
        cin >> x;
        x = MAXN - x + 1;
        count += get(x - 1);
        update(x, 1);
    }
    cout << count;
    return 0;
}
