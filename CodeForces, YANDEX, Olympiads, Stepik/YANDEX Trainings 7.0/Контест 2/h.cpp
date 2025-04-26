#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long value;
    long long add_lazy;
};

void make_tree(vector<Node>& tree, const vector<long long>& arr, long long v, long long tl, long long tr) {
    if (tl == tr) {
        tree[v].value = arr[tl];
    } else {
        long long tm = (tl + tr) / 2;
        make_tree(tree, arr, 2 * v, tl, tm);
        make_tree(tree, arr, 2 * v + 1, tm + 1, tr);
    }
}

void push(vector<Node>& tree, long long v, long long tl, long long tr) {
    if (tree[v].add_lazy != 0) {
        if (tl != tr) {
            tree[2 * v].add_lazy += tree[v].add_lazy;
            tree[2 * v + 1].add_lazy += tree[v].add_lazy;
        }
        tree[v].value += tree[v].add_lazy;
        tree[v].add_lazy = 0;
    }
}

void add_count(vector<Node>& tree, long long v, long long tl, long long tr, long long l, long long r, long long add) {
    push(tree, v, tl, tr);

    if (r < tl || tr < l) return;

    if (l <= tl && tr <= r) {
        tree[v].add_lazy += add;
        push(tree, v, tl, tr);
    } else {
        long long tm = (tl + tr) / 2;
        add_count(tree, 2 * v, tl, tm, l, r, add);
        add_count(tree, 2 * v + 1, tm + 1, tr, l, r, add);
    }
}

long long get_element(vector<Node>& tree, long long v, long long tl, long long tr, long long pos) {
    push(tree, v, tl, tr);

    if (tl == tr) {
        return tree[v].value;
    }
    long long tm = (tl + tr) / 2;
    if (pos <= tm) {
        return get_element(tree, 2 * v, tl, tm, pos);
    } else {
        return get_element(tree, 2 * v + 1, tm + 1, tr, pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long& x : arr) cin >> x;


    long long size = 1;
    while (size < n) size *= 2;
    vector<Node> tree(size * 4);

    make_tree(tree, arr, 1, 0, n - 1);

    long long m;
    cin >> m;
    vector<long long> results;

    while (m--) {
        char type;
        cin >> type;
        if (type == 'g') {
            long long i;
            cin >> i;
            --i;
            results.push_back(get_element(tree, 1, 0, n - 1, i));
        } else if (type == 'a') {
            long long l, r, add;
            cin >> l >> r >> add;
            --l; --r;
            add_count(tree, 1, 0, n - 1, l, r, add);
        }
    }

    for (long long val : results) {
        cout << val << '\n';
    }
    return 0;
}