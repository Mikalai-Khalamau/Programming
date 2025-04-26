#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Tree_Node {
    int max_val;
    int add_later;
};

Tree_Node merge(const Tree_Node& a, const Tree_Node& b) {
    return {max(a.max_val, b.max_val),0};
}

void make_a_tree(vector<Tree_Node>& tree, const vector<int>& a, int size) {
    for (int i = 0; i < size; ++i) {
        int val = (i < (int)a.size() ? a[i] : INT_MIN);
        tree[size - 1 + i] = {val,0};
    }
    for (int i = size - 2; i >= 0; --i) {
        tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
    }
}
void push( vector<Tree_Node>& tree,int i,int l,int r)    {
if (tree[i].add_later !=0 && l!=r) {

    int add_val = tree[i].add_later;

    tree[2 * i + 1].max_val += add_val;
    tree[2 * i + 1].add_later += add_val;

    tree[2 * i + 2].max_val += add_val;
    tree[2 * i + 2].add_later += add_val;

    tree[i].add_later = 0;

}

  }
void query_interval( vector<Tree_Node>& tree, int l_repl, int r_repl, int add,int i,int l,int r) {
push(tree,i,l,r);

if (l_repl > r || r_repl <l) { return ;}

    // полный отрезок
    if (l_repl <= l && r <= r_repl) {
        tree[i].max_val += add;
        if (l != r) {
            tree[i].add_later += add;
        }
        return;
    }

    // частичное пересечение
    int mid = (l + r) / 2;
    query_interval(tree, l_repl, r_repl, add, 2 * i + 1, l, mid);
    query_interval(tree, l_repl, r_repl, add, 2 * i + 2, mid + 1, r);

    tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);



}

Tree_Node query_max( vector<Tree_Node>& tree, int l_find, int r_find, int i, int l, int r) {
    push(tree, i, l, r);
    if (r_find < l || l_find > r) {
        return {INT_MIN, 0};
    }
    if (l_find <= l && r <= r_find) {
        return tree[i];
    }
    int mid = (l + r) / 2;
    Tree_Node left = query_max(tree, l_find, r_find, 2 * i + 1, l, mid);
    Tree_Node right = query_max(tree, l_find, r_find, 2 * i + 2, mid + 1, r);

    if (left.max_val == right.max_val) {
        return {left.max_val};
    } else if (left.max_val > right.max_val) {
        return left;
    } else {
        return right;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n ;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int size = 1;
    while (size < n) size *= 2;
    vector<Tree_Node> tree(2 * size - 1);

    make_a_tree(tree, a, size);
cin>>m;
    while (m--) {
        string s;
        cin>>s;
        if (s=="m")
          {
int l,r;
cin>>l>>r;
l--;
r--;
//выводим максимальное значение на [l,r]
            Tree_Node res = query_max(tree, l, r, 0, 0, size - 1);
            cout<<res.max_val<<" ";
          }
          else
            {
int l,r,add;
cin>>l>>r>>add;
l--;r--;
query_interval(tree, l, r , add,0, 0, size-1);
            }
    }

    return 0;
}