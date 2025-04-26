#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Tree_Node {
    int max_val;
};

Tree_Node merge(const Tree_Node& a, const Tree_Node& b) {
    return {max(a.max_val, b.max_val)};
}

void make_a_tree(vector<Tree_Node>& tree, const vector<int>& a, int size) {
    for (int i = 0; i < size; ++i) {
        int val = (i < (int)a.size() ? a[i] : INT_MIN);
        tree[size - 1 + i] = {val};
    }
    for (int i = size - 2; i >= 0; --i) {
        tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

void replace(vector<Tree_Node>& tree, int index, int new_val, int size) {
    int pos = size - 1 + index;
    tree[pos] = {new_val};
    while (pos > 0) {
        pos = (pos - 1) / 2;
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
}

// рекурсивно ищем минимальный индекс >= i, где значение ≥ x

int query(const vector<Tree_Node>& tree, int i, int x, int v, int l, int r) {
    if (r < i || tree[v].max_val < x) return -1;

    if (l == r) {
        return l;
    }

    int m = (l + r) / 2;
    int left = query(tree, i, x, 2 * v + 1, l, m);
    if (left != -1) return left;
    return query(tree, i, x, 2 * v + 2, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int size = 1;
    while (size < n) size *= 2;
    vector<Tree_Node> tree(2 * size - 1);

    make_a_tree(tree, a, size);

    while (m--) {
        int t, i, x;
        cin >> t >> i >> x;

        if (t == 0) {
            replace(tree, i - 1, x, size);
        } else if (t == 1) {
            int res = query(tree, i - 1, x, 0, 0, size - 1);
            if (res == -1 || res >= n) cout << -1 << "\n";
            else cout << res + 1 << "\n";
        }
    }

    return 0;
}
