#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 1e14
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n;
string s;
const int maxn=110;
int e_cost[maxn],c_cost[maxn][maxn],a_cost[maxn];
int cost[maxn];
int dp[maxn][maxn];

void sol(){
    cin>>s;
    for(int i=0;i<=100;i++) e_cost[i]=a_cost[i]=cost[i]=inf;
    for(int i=0;i<26;i++) 
        for(int j=0;j<26;j++) 
            // if(i==j) c_cost[i][j]=0;
            c_cost[i][j]=inf;

    cin>>n;
    while(n--){
        string ss; cin>>ss;
        if(ss[0]=='a'){
            char c;int x;
            cin>>c>>x;
            a_cost[c-'a']=min(a_cost[c-'a'],x);
        }
        else if(ss[0]=='e'){
            char c;int x;
            cin>>c>>x;
            e_cost[c-'a']=min(e_cost[c-'a'],x);
        }
        else{
            char c1,c2; int x; cin>>c1>>c2>>x;
            c_cost[c1-'a'][c2-'a']=min(c_cost[c1-'a'][c2-'a'],x);
        }
    }


    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                c_cost[i][j]=min(c_cost[i][k]+c_cost[k][j],c_cost[i][j]);
            }
        }
    }

    for(int i=0;i<26;i++){
        // cost[i]=min(e_cost[i],a_cost[i]);
        for(int j=0;j<26;j++){
            cost[i]=min(cost[i],min(e_cost[i],a_cost[i]));
            cost[i]=min(cost[i],c_cost[i][j]+min(a_cost[j],e_cost[j]));
            cost[i]=min(cost[i],c_cost[j][i]+a_cost[j]);
            for(int k=0;k<26;k++){
                cost[i]=min(cost[i],c_cost[i][j]+a_cost[k]+c_cost[k][j]);
            }
        }
    }

    int len=s.length();
    s=' '+s;
    for(int i=len;i>=1;i--){
        for(int j=i+1;j<=len;j++){
            dp[i][j]=inf;
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            dp[i][j]=min(dp[i][j],dp[i+1][j]+cost[s[i]-'a']);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+cost[s[j]-'a']);
            dp[i][j]=min(dp[i][j],dp[i+1][j-1]+min(c_cost[s[j]-'a'][s[i]-'a'],c_cost[s[i]-'a'][s[j]-'a']));
            for(int k=0;k<26;k++)
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]+c_cost[s[i]-'a'][k]+c_cost[s[j]-'a'][k]);
            // cout<<s[i]<<s[j]<<endl;
            // cout<<dp[i][j]<<endl;
        
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }

    if(dp[1][len]==inf) cout<<"-1"<<endl;
    else cout<<dp[1][len]<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
/*
plan A for both
寒假    备 蓝桥 天梯 csp pat，六级，托福首考
大二下  备 蓝桥 天梯 csp pat，六级，托福首考
暑假    托福刷分 GRE首考备战 科研项目 数学建模
大三上  托福 GRE刷分 冲平均成绩 大创
寒假    ！夏令营查漏补缺 大创
大三下  !夏令营
暑假
大四上
大四下

寒假    备 蓝桥 天梯 csp pat，六级
大二下  考 蓝桥 天梯 csp pat，六级，大创
暑假    科研项目 数学建模
大三上  大创 刷6级 刷平均成绩 
寒假    ！夏令营查漏补缺 大创结果
大三下  !夏令营
暑假
大四上
大四下

plan B for dom
寒假    备 蓝桥 天梯 csp pat，六级
大二下  考 蓝桥 天梯 csp pat，六级，大创
暑假    ACM训练 科研项目 数学建模
大三上  大创 刷6级 刷平均成绩 ACM结果
寒假    ！夏令营查漏补缺 大创结果
大三下  !夏令营
暑假
大四上
大四下


保研：
大创加分 x
其他加分 x
年级第一

科研论文
含金量奖项 - ACM摸 xx

------
出国：
托福
GRE
科研

1. 问学姐历来保研 简历？
2。留学一定留在当地，短期不考虑回国，当地薪资情况
3. 


*/