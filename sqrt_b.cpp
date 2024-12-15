#include <iostream>
using namespace std;
typedef long long ll;

struct node {
    node *L, *R;
    ll W, S, sm, V;
    bool F;

    explicit node(ll x) {
        L = R = nullptr;
        W = rand();
        S = 1;
        sm = x;
        V = x;
        F = false;
    }
};

ll size(node *treap) {
    return (treap == nullptr ? 0 : treap->S);
}

ll sum(node *treap) {
    return (treap == nullptr ? 0 : treap->sm);
}

void push(node *treap) {
    if (treap && treap->F) {
        treap->F = false;
        swap(treap->L, treap->R);
        if (treap->L) treap->L->F ^= 1;
        if (treap->R) treap->R->F ^= 1;
    }
}

void split(node *treap, node *&left, node *&right, ll k) {
    if (treap == nullptr) left = right = nullptr;
    else {
        push(treap);
        if (size(treap->L) < k) {
            split(treap->R, treap->R, right, k - size(treap->L) - 1);
            left = treap;
        }
        else {
            split(treap->L, left, treap->L, k);
            right = treap;
        }
        treap->S = size(treap->L) + size(treap->R) + 1;
        treap->sm = sum(treap->L) + sum(treap->R) + treap->V;
    }
}

void merge(node *&treap, node *left, node *right) {
    if (left == nullptr) treap = right;
    else if (right == nullptr) treap = left;
    else {
        push(left);
        push(right);
        if (left->W < right->W) {
            merge(left->R, left->R, right);
            treap = left;
        }
        else {
            merge(right->L, left, right->L);
            treap = right;
        }
        treap->S = size(treap->L) + size(treap->R) + 1;
        treap->sm = sum(treap->L) + sum(treap->R) + treap->V;
    }
}

ll find_sum(node *treap, ll k) {
    if (treap == nullptr || k == 0) return 0;
        push(treap);
        if (size(treap->L) < k) {
            return sum(treap->L) + treap->V + find_sum(treap->R, k - size(treap->L) - 1);
        }
        else {
            return find_sum(treap->L, k);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    node *treap = nullptr;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        merge(treap, treap, new node(x));
    }
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            node *A, *B, *C;
            split(treap, A, B, x - 1);
            split(B, B, C, y - x + 1);
            B->F ^= 1;
            merge(treap, A, B);
            merge(treap, treap, C);
        }
        else {
            ll x, y;
            cin >> x >> y;
            cout << find_sum(treap, y) - find_sum(treap, x - 1) << '\n';
        }
    }
    return 0;
}
