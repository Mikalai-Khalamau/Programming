#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int MAXIMUM(vector<int> &tree, int n, int l_find, int r_find, int i, int l, int r) {
    if (l_find <= l && r_find >= r) {
        return tree[i];
    }
    else if (r_find < l || l_find > r) {
        return INT_MIN;
    }
    else {
        return max(
            MAXIMUM(tree, n, l_find, r_find, 2 * i + 1, l, (l + r) / 2),
            MAXIMUM(tree, n, l_find, r_find, 2 * i + 2, (l + r) / 2 + 1, r)
        );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int original_n = n;

    int size = 1;
    while (size < n) size *= 2;
    a.resize(size, INT_MIN);
    n = a.size();

    vector<int> tree(2 * n - 1);


    for (int i = 0; i < n; i++) {
        tree[n - 1 + i] = a[i];
    }


    for (int i = n - 2; i >= 0; i--) {
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }

    int k;
    cin >> k;
    while (k--) {
        string s;
        int l, r;
        cin >> s >> l >> r;

        if (s == "u") {
            int i = l - 1;
            int new_val = r;


            int pos = n - 1 + i;
            tree[pos] = new_val;


            pos = (pos - 1) / 2;
            while (pos >= 0) {
                int left = 2 * pos + 1;
                int right = 2 * pos + 2;

                if (left >= tree.size()) break;

                tree[pos] = max(tree[left], (right < tree.size() ? tree[right] : INT_MIN));

                if (pos == 0) break;
                pos = (pos - 1) / 2;
            }
        }

        else {
            --l; --r;
            int res = MAXIMUM(tree, n, l, r, 0, 0, n - 1);
            cout << res << " ";
        }
    }

    return 0;
}


