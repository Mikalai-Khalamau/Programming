#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Tree_Node {
    int min_val;
    int zero_count;
};

//сливаем 2 узла когда нужно выбирая меньший по значению и складвыем колво нулей на отрезках
Tree_Node merge(const Tree_Node& a, const Tree_Node& b) {
    if (a.min_val == b.min_val) {
        return {a.min_val, a.zero_count + b.zero_count};
    } else if (a.min_val < b.min_val) {
        return a;
    } else {
        return b;
    }
}

//строим дерево размера 2*сайз -1 где храним значения как обычно и также количество нулей на отрезочке
void make_a_tree(vector<Tree_Node>& tree, const vector<int>& a, int size) {
    for (int i = 0; i < size; ++i) {
        int val = (i < (int)a.size() ? a[i] : INT_MAX);
        if (val==0) {
            tree[size - 1 + i] = {val,  1 };
        }
        else {
            tree[size - 1 + i] = {val,  0 };
        }
    }
    for (int i = size - 2; i >= 0; --i) {
        tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
    }
}



//заменяем индексовый элемент на нью поднимаясь вверх также учитывая нули
void replace(vector<Tree_Node>& tree, int index, int new_val, int size) {
    int pos = size - 1 + index;
    tree[pos] = {new_val, new_val == 0 ? 1 : 0};
    while (pos > 0) {
        pos = (pos - 1) / 2;
        tree[pos] = merge(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
}

//запросик
Tree_Node query(const vector<Tree_Node>& tree, int l_find, int r_find, int i, int l, int r) {
    if (r_find < l || l_find > r) return {INT_MAX, 0};
    if (l_find <= l && r <= r_find) return tree[i];
    int mid = (l + r) / 2;
    Tree_Node left = query(tree, l_find, r_find, 2 * i + 1, l, mid);
    Tree_Node right = query(tree, l_find, r_find, 2 * i + 2, mid + 1, r);
    return merge(left, right);
}


int zeros_on_otrezok(const vector<Tree_Node>& tree, int k, int size) {
    int i = 0, l = 0, r = size - 1;
    if (tree[0].zero_count < k) return -1;

    while (l != r) {
        int mid = (l + r) / 2;
        int left_count = tree[2 * i + 1].zero_count;
        if (k <= left_count) {
            i = 2 * i + 1;
            r = mid;
        } else {
            k -= left_count;
            i = 2 * i + 2;
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int size = 1;
    while (size < n) size *= 2;
    vector<Tree_Node> tree(2 * size - 1);

    make_a_tree(tree, a, size);

    int m;
    cin >> m;
    while (m--) {
        string str;
        cin >> str;

        if (str == "u") {
            int idx, val;
            cin >> idx >> val;
            replace(tree, idx - 1, val, size);
        } else if (str == "s") {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;

            int prefix_zeros = 0;
            if (l > 0) {
                Tree_Node left_prefix = query(tree, 0, l - 1, 0, 0, size - 1);
                if (left_prefix.min_val == 0) {
                    prefix_zeros = left_prefix.zero_count;
                }
            }

            int total_k = k + prefix_zeros;
            int res = zeros_on_otrezok(tree, total_k, size);
            if (res == -1 || res > r) {
                cout << -1 << " ";
            } else {
                cout << res + 1 << " ";
            }
        }
    }

    return 0;
}
