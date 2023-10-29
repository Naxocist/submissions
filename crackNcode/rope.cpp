#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
#define INF 1e9
struct S {
	stack<int> t, mx, mn;
	S() { mx.push(-INF); mn.push(INF); }

	void push(int x) {
		t.push(x);
		mx.push(std::max(mx.top(), x)); 
		mn.push(std::min(mn.top(), x));
	}

	void pop() {
		if(t.empty()) return ;
		t.pop(); mx.pop(); mn.pop();
	}
	int top() { return t.top(); }
	int max() { return mx.top(); }
	int min() { return mn.top(); }
	bool empty() { return t.empty(); }
};

struct Q {
	S l, r;

	void push(int x) {
		r.push(x);
	}

	void move() {
		while(!r.empty()) l.push(r.top()), r.pop();
	}

	int front() {
		if(l.empty()) move();
		if(!l.empty()) return l.top();
	}

	void pop() {
		if(l.empty()) move();
		if(!l.empty()) l.pop();
	}

	int max() {return std::max(l.max(), r.max());}
	int min() {return std::min(l.min(), r.min());}
	bool empty() { return l.empty() && r.empty();}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, p; cin >> n >> p;
	ll x, y, z; cin >> x >> y >> z;
	Q q;
	vector<ll> cnt(5e5+3, 0), a(n+1), b(n+1), qs(n+1);
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i) cin >> b[i];

	ll l, r, res = 0;
	l = r = 1;
	for(; r<=n; ++r) {
		q.push(a[r]);
		cnt[b[r]] ++;
		qs[r] = qs[r-1] + a[r];

		while(qs[r] - qs[l-1] > x) q.pop(), cnt[b[l]] --, l++;

		if(y != -1) {
			while(q.max() - q.min() > y) 
				q.pop(), cnt[b[l]] --, l++;
		}

		if(z != -1) {
			while(cnt[b[r]] > z) {
				q.pop(), cnt[b[l]] --, l++;
			}
		}
		res += r - l + 1;
	}

	cout << res;
	return 0;
}