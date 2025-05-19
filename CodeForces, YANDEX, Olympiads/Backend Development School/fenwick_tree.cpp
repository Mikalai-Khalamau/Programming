#include <iostream>
#include <vector>
using namespace std;
const int max_price=200;
class SegmentTree {
private:
    vector<int> tree;
    int size;
    void update(int node, int left, int right, int index,int delta) {
        if (left == right) {
            tree[node] += delta;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid) {
            update(2*node, left, mid, index, delta);
        }
        else {
            update(2*node+1, mid+1, right, index, delta);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }


    int query(int node, int left, int right,int qleft,int qright) {
        if (qleft > right || qright < left) {
            return 0;
        }
        if (qleft <= left && right <= qright) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        return query(2*node, left, mid, qleft, qright) +
            query(2*node+1, mid+1, right, qleft, qright);
    }



public:

    SegmentTree() : size(max_price) {
        tree.resize(4 * size);
    }
void add_price(int price) {
        update(1, 0, size, price, 0);
    }
    int count_less(int price) {
        if (price<=1) return 0;
        return query(1, 1, size, 1, price-1);
    }

};

int main() {
    int n;
    cin >> n;
    SegmentTree st;
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        total += st.count_less(price);
        st.add_price(price);
    }

    cout << total << endl;

    return 0;
}