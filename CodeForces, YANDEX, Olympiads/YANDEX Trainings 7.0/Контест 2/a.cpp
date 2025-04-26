#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int max_val;
    int count;
};

Node query(const vector<Node>& tree, int l_find, int r_find, int i, int l, int r) {
    if (r_find < l || l_find > r) {
        return {INT_MIN, 0};
    }
    if (l_find <= l && r <= r_find) {
        return tree[i];
    }
    int mid = (l + r) / 2;
    Node left = query(tree, l_find, r_find, 2 * i + 1, l, mid);
    Node right = query(tree, l_find, r_find, 2 * i + 2, mid + 1, r);

    if (left.max_val == right.max_val) {
        return {left.max_val, left.count + right.count};
    } else if (left.max_val > right.max_val) {
        return left;
    } else {
        return right;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    // дополняем до степени двойки
    int size = 1;
    while (size < n) size *= 2;
    a.resize(size, INT_MIN);

    vector<Node> tree(2 * size - 1);
    // заполнение листьев
    for (int i = 0; i < size; ++i) {
        tree[size - 1 + i] = {a[i], a[i] != INT_MIN ? 1 : 0};
    }
    // построение дерева
    for (int i = size - 2; i >= 0; --i) {
        Node left = tree[2 * i + 1];
        Node right = tree[2 * i + 2];
        if (left.max_val == right.max_val) {
            tree[i] = {left.max_val, left.count + right.count};
        } else if (left.max_val > right.max_val) {
            tree[i] = left;
        } else {
            tree[i] = right;
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        Node res = query(tree, l, r, 0, 0, size - 1);
        cout << res.max_val << " " << res.count << "\n";
    }

    return 0;
}
