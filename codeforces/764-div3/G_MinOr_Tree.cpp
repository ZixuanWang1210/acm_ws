#include<bits/stdc++.h> 
using namespace std;

const int N=2e5+10;

struct node{
	int u,v,w;
} edge[N];

int p[N];

int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}

void merge(int a,int b){
	int pa=find(a),pb=find(b);
	p[pa]=pb;
}

void sol(){
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		edge[i]={u,v,w};		
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		for(int i=1;i<=n;i++) p[i]=i;
		for(int j=1;j<=m;j++){
			if(edge[j].w&(1<<i)==0){
				merge(edge[i].u,edge[i].v);
			}
		}
		int bz=find(1);
		bool ok=true;
		for(int i=1;i<=n;i++){
			if(find(i)!=bz) ok=false;
		}
		ans+=1<<i;
		if(ok){
			cout<<ans;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	
	int t; cin>>t;
	while(t--){
		sol();
	}
}
