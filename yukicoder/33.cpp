#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using Int = unsigned int;
using llong = long long;
using Llong = unsigned long long;
using ldouble = long double;
using intV = vector<int>;
using llongV = vector<long long>;
using llongVV = vector<vector<long long>>;
using Graph = vector<vector<long long>>;
using costGraph = vector<vector<pair<long long, long long>>>;

struct Edge {
    long long from;
    long long to;
    long long cost;
};

template<typename T>
using asc = less<T>();
template<typename T>
using desc = greater<T>();

const llong MOD = 1e9 + 7;
const llong INF = 1e17;

#define FOR(i, n) for (llong i = 0; i < n; i++)
#define FORS(i, a, b) for (llong i = a; i < b; i++)
#define FORR(i, n) for (llong i = n; i > 0; i++)
#define sup(vec, a) upper_bound(vec.begin(), vec.end(), a) - vec.begin()
#define inf(vec, a) lower_bound(vec.begin(), vec.end(), a) - vec.begin()

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong N, D, T;
    cin >> N >> D >> T;

    map<llong, llongV> amebaGrp;
    FOR(i, N) {
        llong x;
        cin >> x;
        llong mod = x % D;
        if(mod < 0) mod += D;
        amebaGrp[mod].push_back(x);
    }

    llong ans = N;
    for(auto [mod, grp] : amebaGrp) {
        if(grp.size() == 0) continue;

        ans += 2 * T;
        sort(grp.begin(), grp.end());
        FORS(i, 1, grp.size()) {
            ans += min(2 * T, (grp[i] - grp[i - 1]) / D - 1);
        }
    }

    cout << ans << endl;

    return 0;
}