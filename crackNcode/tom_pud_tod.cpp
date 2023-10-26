#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

const ll INF = 1e9 + 7;

void solve(){
    
    int n; cin >> n;

    stack<int> s;
    int cnt = 0, r = 0;
    while(n--){
        int x; cin >> x;
        r++;
        if(s.size() && s.top() == x){
            cnt++;
            s.pop();
            r-=2;
        }else {
            s.push(x);
        }

        if(r >= 3){
            int k = 3;
            stack<int> t(s);
            unordered_set<int> us;
            while(k--) us.insert(t.top()) , t.pop();

            if(us.size() == 3) {
                cnt++;
                s = t;
                r -= 3;
            }
        }
        
    }

    
    if(r){
        cout << "No\n" << cnt << '\n' << r << '\n';
    }else{
        cout << "Yes\n" << cnt << '\n';
    }
    return ;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // freopen("input.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
