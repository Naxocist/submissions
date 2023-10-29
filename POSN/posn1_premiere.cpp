#include <bits/stdc++.h>
using namespace std;

struct team {
    int num, score;
    bool operator < (const team &x) {
        if(score != x.score) return score > x.score;

        return num < x.num;
    }
};

int main() {
    int n, m; scanf("%d%d", &n, &m);

    team ar[m+1];
    for(int i=1; i<=m; ++i) ar[i].num = i, ar[i].score = 0;

    while(n--) {
        int t1, t2, s1, s2; 
        scanf("%d%d%d%d", &t1, &t2, &s1, &s2);
        if(s1 > s2) {
            ar[t1].score += 3;
        }else if(s2 > s1) {
            ar[t2].score += 3;
        }else {
            ar[t1].score ++;
            ar[t2].score ++;
        }
    }

    sort(ar+1, ar+m+1);
    for(int i=1; i<=m; ++i) {
        printf("%d %d\n", ar[i].num, ar[i].score);
    }

    return 0;
}

/*
3 3
1 3 3 0
2 3 1 2
2 1 1 1
*/