#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;

void sol()
{
    int n,t = 0;
    std::cin>>n;
    std::priority_queue<int> que;
    std::map<int,int> mp;
    mp[0] = 1;
    for(int i = 1 ; i < n ; i++)
    {
        int x;
        std::cin>>x;
        mp[x]++;
    }
    std::vector<int> num;
    for(auto map : mp)num.push_back(map.second);//从大到小排序"群体"
    std::sort(num.begin(),num.end());
    for(auto val : num)//第一步
    {
        if(val - 1 - t > 0)que.push(val - 1 - t);
        t++;
    }
    int res = 0;
    while(true)
    {
        if(que.empty()||que.top() - res <= 0)break;//第二步
        que.push(que.top()-1);
        que.pop();
        res++;
    }
    std::cout<<res+t<<'\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) sol();
    

    return 0;
}
