#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;


constexpr ll MOD = 998'244'353, DIM = 6;

vector<vector<ll>> base = {
    { 1, 4, 2, 0, 12, 12 },
    { 1, 0, 0, 0,  0,  0 },
    { 0, 1, 0, 0,  0,  0 },
    { 0, 0, 0, 1,  4,  2 },
    { 0, 0, 0, 1,  0,  0 },
    { 0, 0, 0, 0,  1,  0 },
};
vector<vector<ll>> unit = {
    { 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1 }
};
vector<vector<ll>> zero = {
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 }
};
vector<ll> fbase = {
    36, 12, 0, 11, 5, 1
};

vector<vector<ll>> matMul(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2) {
    auto res = zero;
    for (int i = 0; i < DIM; ++i)
        for (int j = 0; j < DIM; ++j)
            for (int k = 0; k < DIM; ++k)
                res[i][j] = (res[i][j] + (mat1[i][k] * mat2[k][j] % MOD)) % MOD;

    return res;
}

vector<vector<ll>> matPow(vector<vector<ll>>& num, ll n) {
    vector<vector<ll>> a = num, res = unit;
    while (n) {
        if (n & 1)
            res = matMul(res, a);
        a = matMul(a, a);
        n >>= 1;
    }

    return res;
}

ll n;
ll sol() {
    if (n < 4)
        return fbase[3 - n];

    auto getting = matPow(base, n - 3);
    vector<ll> res = { 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < DIM; ++i) {
        ll thing = 0;
        for (int j = 0; j < DIM; ++j)
            thing = (thing + (getting[i][j] * fbase[j] % MOD)) % MOD;
        res[i] = thing;
    }

    return res[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin  >> n;
    cout << sol();

    return 0;
}
