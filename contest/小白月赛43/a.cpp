#include<bits/stdc++.h>
#define maxn 10000001
using namespace std;
int n;
int bz=0;
int t[maxn];
int pd[1001];
void suan(int m)
{
	bz=0;
	for(int i=1;i*i<=m;i++)
	{
		if(m%i==0)
		{
			t[++bz]=i;
			if(m/i!=i)
				t[++bz]=m/i;
		}
	}
	sort(t+1,t+bz+1);
	if(t[bz]%t[(bz+1)/2]==0)
		pd[m]=pd[m-1]+1;
	else
		pd[m]=pd[m];
	return ;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=1000;i++)
		suan(i);
	while(n--)
	{
		int qwe;
		cin>>qwe;
			cout<<pd[qwe]<<"\n";
	}
	return 0;
}
