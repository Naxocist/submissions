#include <bits/stdc++.h>
using namespace std;
void f(int n,int l,int r){ if(n == 0) return;int a=1^2^3^l^r;f(n-1, l, a);printf("%d %d\n", l, r);f(n-1,a,r);}
int main(){int n;scanf("%d",&n);printf("%.0lf\n",pow(2, n)-1);f(n,1,3);}