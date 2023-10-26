#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
vector<int>rev[100005];
int mx=0;
int dfs(int a,int p){
	int sum=0;
	if(v[a].size()==0){
		return 1;
	}
	for(int i=0;i<v[a].size();i++){
		if(v[a][i]==p)continue;
		sum+=dfs(v[a][i],a);
	}
	//cout<<a<<" "<<sum+1<<endl;
	return sum+1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=0;j<l;j++){
			int a,b;
			cin>>a>>b;
			if(b>50){
				v[a].push_back(i);
				rev[i].push_back(a);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(rev[i].size()==0){
			mx=max(dfs(i,0)-1,mx);
		}
	}
	cout<<mx;
}