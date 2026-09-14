#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

ll n, q;

void build(vector<ll>& tree, vector<ll>& pos, ll id, ll l, ll r) {
    if (l == r) {
        tree[id] = pos[l - 1] * pos[l - 1];
        return;
    }

    ll mid = (l + r) / 2;
    build(tree, pos, id * 2, l, mid);
    build(tree, pos, id * 2 + 1, mid + 1, r);

    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void buildTree(vector<ll>& tree, vector<ll>& pos) {
    tree.resize(pos.size() * 4 + 1);
    build(tree, pos, 1, 1, pos.size());
}

void update(vector<ll>& tree, ll val, ll index, ll id, ll l, ll r) {
    if (l > index || r < index)
        return;

    if (l == r) {
        tree[id] = val * val;
        return;
    }

    int mid = (l + r) / 2;
    update(tree, val, index, id * 2, l, mid);
    update(tree, val, index, id * 2 + 1, mid + 1, r);

    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void updateTree(vector<ll>& tree, ll val, ll index, ll n) {
    update(tree, val, index, 1, 1, n);
}

ll getSum(vector<ll>& tree, ll id, ll l, ll r, ll x, ll y) {
    if (l > y || r < x) {
        return 0;
    }

    if (l >= x && r <= y) {
        return tree[id];
    }

    int mid = (l + r) / 2;
    return getSum(tree, id * 2, l, mid, x, y) + getSum(tree, id * 2 + 1, mid + 1, r, x, y);
}

ll getSumTree(vector<ll>& tree, ll x, ll y, ll n) {
    return getSum(tree, 1, 1, n, x, y);
}

void printpos(vector<vector<ll>>& pos) {
    for (ll i = 1; i <= n; ++i) {
        cout << "\nPOS " << i << ": ";
        for (auto sth : pos[i]) {
            cout << sth << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<vector<ll>> pos(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    vector<vector<ll>> tree(n + 1);
    for (ll i = 1; i <= n; ++i) {
        if (pos[i].size()) {
            buildTree(tree[i], pos[i]);
        }
    }

    ll query, last = 0;
    while (q--) {
        cin >> query;
        switch (query) {
            case 1: {
                // swap a[input] a[input + 1]
                ll p;
                cin >> p;
                p = (p + last - 1) % (n - 1) + 1;
                if (a[p] != a[p + 1]) {
                    auto lbp = lower_bound(pos[a[p]].begin(), pos[a[p]].end(), p);
                    ll index1 = lbp - pos[a[p]].begin();
                    lbp = lower_bound(pos[a[p + 1]].begin(), pos[a[p + 1]].end(), p + 1);
                    ll index2 = lbp - pos[a[p + 1]].begin();

                    updateTree(tree[a[p]], p + 1, index1 + 1, pos[a[p]].size());
                    updateTree(tree[a[p + 1]], p, index2 + 1, pos[a[p + 1]].size());

                    pos[a[p + 1]][index2] = p;
                    pos[a[p]][index1] = p + 1;

                    ll t = a[p];
                    a[p] = a[p + 1];
                    a[p + 1] = t;
                }
                break;
            }
            case 2: {
                ll l, r, x;
                cin >> l >> r >> x;
                l = ((l + last - 1) % n) + 1;
                r = ((r + last - 1) % n) + 1;
                x = ((x + last - 1) % n) + 1;
                if (pos[x].size() == 0) {
                    last = 0;
                    cout << "0\n";
                    break;
                }

                if (l > r) {
                    ll t = r;
                    r = l;
                    l = t;
                }

                auto lbx = lower_bound(pos[x].begin(), pos[x].end(), l);
                ll left  = lbx - pos[x].begin();
                lbx = lower_bound(pos[x].begin(), pos[x].end(), r);
                ll right = lbx - pos[x].begin();
                if (*lbx > r)
                    right--;

                last = getSumTree(tree[x], left + 1, right + 1, pos[x].size());
                cout << last << "\n";
                break;
            }
            case 3: {
                // sum i^2 of b[i]
                ll l, r, x;
                cin >> l >> r >> x;
                l = ((l + last - 1) % n) + 1;
                r = ((r + last - 1) % n) + 1;
                x = ((x + last - 1) % n) + 1;
                if (pos[x].size() == 0) {
                    last = 0;
                    cout << "0\n";
                    break;
                }

                if (l > r) {
                    ll t = r;
                    r = l;
                    l = t;
                }

                last = getSumTree(tree[x], l, r, pos[x].size());
                cout << last << "\n";
                break;
            }
        }
    }

    return 0;
}
