#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream inp("./CAU2.INP");
    ofstream out("./CAU2.OUT");
    int n;
    inp >> n;
    vector<int> mp(1000001, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        inp >> x;
        ++mp[x];
    }
    out << *max_element(mp.begin(), mp.end());
    return 0;
}
