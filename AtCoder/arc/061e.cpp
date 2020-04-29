#include <bits/stdc++.h>
using namespace std;

template <class A, class B>
string to_string(pair<A, B> p);

template <class A, class B, class C>
string to_string(tuple<A, B, C> p);

template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <class A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <class A, class B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <class A, class B, class C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <class Head, class... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using Int = unsigned int;
using llong = long long;
using Llong = unsigned long long;
using ldouble = long double;
using intV = vector<int>;
using intVV = vector<vector<int>>;
using llongV = vector<long long>;
using llongVV = vector<vector<long long>>;

template<class T = int>
using asc_pque = priority_queue<T, vector<T>, greater<T>>;
template<class T = int>
using desc_pque = priority_queue<T, vector<T>, less<T>>;

const llong MOD = 1000000007;
const int IINF = 1000000000;
const llong LINF = 100000000000000000LL;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define FOR(i, n) for (llong i = 0LL; i < llong(n); i++)
#define FORS(i, a, b) for (llong i = llong(a); i < llong(b); i++)
#define bisect_right(vec, a) upper_bound(vec.begin(), vec.end(), a) - vec.begin()
#define bisect_left(vec, a) lower_bound(vec.begin(), vec.end(), a) - vec.begin()
#define GET(i, p) get<i>(p)

using node = pair<int, int>;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    map<node, vector<pair<node, int>>> edges;
    map<node, int> minDist;
    FOR(i, M) {
        int fr, to, color;
        cin >> fr >> to >> color;
        edges[make_pair(fr, color)].emplace_back(make_pair(to, color), 0);
        edges[make_pair(to, color)].emplace_back(make_pair(fr, color), 0);

        edges[make_pair(fr, color)].emplace_back(make_pair(fr, -1), 0);
        edges[make_pair(to, color)].emplace_back(make_pair(to, -1), 0);
        edges[make_pair(fr, -1)].emplace_back(make_pair(fr, color), 1);
        edges[make_pair(to, -1)].emplace_back(make_pair(to, color), 1);

        minDist[make_pair(fr, color)] = IINF;
        minDist[make_pair(to, color)] = IINF;
        minDist[make_pair(fr, -1)] = IINF;
        minDist[make_pair(to, -1)] = IINF;
    }

    asc_pque<pair<int, node>> que;
    que.emplace(0, make_pair(1, -1));
    minDist[make_pair(1, -1)] = 0;

    int ans = IINF;

    while (!que.empty()) {
        int dist;
        node now;
        tie(dist, now) = que.top();
        que.pop();

        for(auto e : edges[now]) {
            node to;
            int d;
            tie(to, d) = e;
            if (minDist[to] > dist + d) {
                minDist[to] = dist + d;
                if(to.first == N) chmin(ans, minDist[to]);
                que.emplace(dist + d, to);
            }
        }
    }

    ans = (ans == IINF) ? -1 : ans;
    cout << ans << endl;

    return 0;
}