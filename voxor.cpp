#include <iostream>
#include <vector>
using namespace std;
const int LENGTH = 30;

struct Node {
    Node *child[2];
    int size;
    Node() {
        child[0] = child[1] = nullptr;
        size = 0;
    }
};

int size(Node *x) {
    return x ? x->size : 0;
}

Node *root;
bool flip[LENGTH + 1];

void insert(Node *x, int v, int pos) {
    int bit = v >> pos & 1;
    if (!x->child[bit]) x->child[bit] = new Node();
    if (pos > 0) {
        insert(x->child[bit], v, pos - 1);
    }
    else {
        ++x->child[bit]->size;
    }
    x->size = size(x->child[0]) + size(x->child[1]);
}

void xorWith(int v) {
    for (int i = LENGTH; i >= 0; --i) {
        if (v >> i & 1) flip[i] ^= 1;
    }
}

int findKth(Node *x, int kth, int pos) {
    if (pos < 0) return 0;
    int smaller = size(x->child[flip[pos]]);
    if (kth <= smaller) return findKth(x->child[flip[pos]], kth, pos - 1);
    return findKth(x->child[!flip[pos]], kth - smaller, pos - 1) + (1 << pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    root = new Node();
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        insert(root, x, LENGTH);
    }
    while (q--) {
        char cmd[5];
        int x;
        cin >> cmd >> x;
        if (cmd[0] == 'X') {
            xorWith(x);
        }
        else {
            cout << findKth(root, n - x + 1, LENGTH) << '\n';
        }
    }
    return 0;
}
