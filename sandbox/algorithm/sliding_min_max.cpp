#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
struct S {
	stack<int> t, mx, mn;
	S() {
		mx.push(-INF); mn.push(INF);
	}

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
Q q;
void f() {
	cout << q.max() << ' ' << q.min() << '\n';
}
int main() {
	
	for(int i=1; i<=10; ++i) q.push(i);

	f();
	q.pop();
	q.pop();
	q.push(111);
	f();
	
	return 0;
}