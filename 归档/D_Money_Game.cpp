#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include<bits/stdc++.h>
using namespace std;
#define bl setiosflags(ios::fixed) << setprecision
#define mod 1000000007
#define endl "\n"
mt19937_64 rnd(2022);
//#define x first
//#define y second
// #define int ll
typedef long long ll;
typedef pair<int, int> pii;
const int N=1000010;
int son[N][26], cnt[N], idx;
unordered_map<int,int> m;

int has(int x,int y){
	return x+y*1000;
    
}

void insert(string str)
{
    int p = 0,u;
    for (int i = 0; i<str.size(); i ++ )
    {
        u = str[i] - 'a'+1;
        for(int i=1;i<=26;i++){
        	if(i==u) continue;
        	if(son[p][i])
        		m[has(u,i)]+=cnt[son[p][i]];
        }
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        cnt[p] ++ ;
    }
    u=0;
    for(int i=1;i<=26;i++){
        	if(i==u) continue;
        	if(son[p][i])
        		m[has(u,i)]+=cnt[son[p][i]];
        }
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		insert(s);
	}

	while(q--){
		ll res=0;
		string s;cin>>s;
		for(int i=0;i<26;i++){
			for(int j=i+1;j<26;j++){
				int a=s[i]-'a'+1,b=s[j]-'a'+1;
				if(a==b) continue;
				if(m[has(a,b)]){
					res+=m[has(a,b)];
				}
			}
		}
		for(int i=1;i<=26;i++)
			res+=m[has(0,i)];
		cout<<res<<endl;
	}



	return 0;
}
