#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream inp("./MATMA.INP");
    ofstream out("./MATMA.OUT");
    string s;
    inp >> s;
    map<char, int> mp;
    bool check = false;
    int sum = 0;
    for (char c: s) {
        if (c == '0') check = true;
        sum += c - '0';
        ++mp[c];
    }
    if (!check or sum % 3) out << -1;
    else {
        for (char c = '9'; c >= '0'; --c) {
            for (int i = 0; i < mp[c]; ++i) out << c;
        }
    }
    return 0;
}
