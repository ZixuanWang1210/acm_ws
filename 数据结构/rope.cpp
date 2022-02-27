#include<cstdio>
#include<iostream>
#include<ext/rope>
#include<algorithm>
using namespace std;
using namespace __gnu_cxx;
const int maxn=1e3+10;
int n,now,len;
rope <char> a,b,tmp;
string ss,rss;
char s[10];
int main()
{
	cin>>n;
	int x;
	while(n--)
	{
		scanf("%s",s);
		switch(s[0])
		{
		case 'M':cin>>now;break;
		case 'P':now--;break;
		case 'N':now++;break;
		case 'G':printf("%c\n",a[now]);break;
		case 'I':
		{
			cin>>x;len=a.length();
			cin>>ss;
            rss=ss;
            reverse(rss.begin(),rss.end());
            char s[maxn],rs[maxn];
            // s=ss.data(),rs=rss.data();
            ss.copy(s,len,0),rss.copy(rs,len,0);
			a.insert(now,s);
			b.insert(len-now,rs);
			break;
		}
		case 'D':
		{
			cin>>x;len=a.length();
			a.erase(now,x);
			b.erase(len-now-x,x);
			break;
		}
		case 'R':
		{
			cin>>x;len=a.length();
			tmp=a.substr(now,x);
			a=a.substr(0,now)+b.substr(len-now-x,x)+a.substr(now+x,len-now-x);
			b=b.substr(0,len-now-x)+tmp+b.substr(len-now,now);
			break;
		}
		}
	}
	return 0;
}