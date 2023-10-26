#include <bits/stdc++.h>
#define endll '\n'
using namespace std;
 
 
int main() {
    
    int n; cin >> n;

    deque<pair<int, int> > dq;
    
    char c;

    while(n--){
        int x, y;
        scanf(" %c", &c);
        if(c == 'A'){
            scanf("%d,%d", &x, &y);
            dq.push_back({x, y});

        }else if(c == 'B'){
            scanf("%d,%d", &x, &y);
            dq.push_front({x, y});

        }else if(c == 'C'){
            if(!dq.empty()) dq.pop_front();

        }else if(c == 'D'){
            if(!dq.empty()) dq.pop_back();

        }else if(c == 'E'){
            sort(dq.begin(), dq.end());

        }else if(c == 'F'){
            sort(dq.begin(), dq.end(), greater<>());

        }else{
            scanf("%d", &x);
            printf("{%d,%d}\n", dq[x-1].first, dq[x-1].second);
        }
        
    }
    

    return 0;
}
