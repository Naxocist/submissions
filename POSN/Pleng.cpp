#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template <typename S, typename T> S amax(S &a, const T &b) { if (b > a) a = b; return a; }
template <typename S, typename T> S amin(S &a, const T &b) { if (b < a) a = b; return a; }

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int)(x).size()
#define ln '\n'
using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;
const int mod = 2560;

void f(ll &x) { x %= mod, x += mod, x %= mod; }
void runcase() {
  int n;
  cin >> n;
  vector<ll> qsx(n + 1), qsy(n + 1), x(n + 1), y(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    f(x[i]);
    qsx[i] = qsx[i - 1] + x[i];
    f(qsx[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
    f(y[i]);
    qsy[i] = qsy[i - 1] + y[i];
    f(qsy[i]);
  }

  ll res = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    res += 1LL * x[i] * y[i] * (n - 1), f(res);
    res -= y[i] * qsx[i - 1], f(res);
    res -= x[i] * qsy[i - 1], f(res);
    cnt += i - 1;
    f(cnt);
  }
  cout << cnt << ln << res;
  return;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC;
  while (TC--)
    runcase();
  return 0;
}
