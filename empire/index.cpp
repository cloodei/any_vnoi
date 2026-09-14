#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

int par[100000], sz[100000], n;

struct Point {
    int x, y, z;
};
struct Index {
    int a, b;
    int vertex;
};

bool compare(Index& a, Index& b) {
    return a.vertex < b.vertex;
}

void reset()
{
    for(int i = 0; i < n; i++) 
    {
        par[i] = i;
        sz[i ] = 1;
    }
}


int find(int x)
{
    if(x == par[x])
        return x;
    return par[x] = find(par[x]);
}

int res = 0;
void dsu(Index a)
{
    // kiem tra goc -> dung la thanh phan ok
    if(find(a.a) == find(a.b))
        return;

    int parx = find(a.a),  pary = find(a.b);
    res += a.vertex;
    // ghep do thi
    if(sz[parx] < sz[pary]) swap(parx, pary);
    par[pary] = par[parx];
    sz[pary] = sz[parx];

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    vector<Index> arr;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int minn = min(abs(a[i].x - a[j].x), min(abs(a[i].y - a[j].y), abs(a[i].z - a[j].z)));
            arr.push_back({i, j, minn});
        }
    }

    sort(arr.begin(), arr.end(), compare);

    reset();
    for (size_t i = 0; i < arr.size(); ++i) {
        dsu(arr[i]);
    }
    cout << res;

    return 0;
}
