#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
#define ll long long
#define int long long

using namespace std;

void sol(){]
    int n; cin>>n;
    vector<int> nums(n);
    int k;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    int i=0,j=-1;
    int ans=0;
    int cnt=0;
    map<int,int> mp;
    while(j<(int)nums.size()-1){
        j++;
        if(mp[nums[j]]>=1){
            
            cnt-=(mp[nums[j]]*(mp[nums[j]]-1))/2;
            cout<<j<<' '<<cnt<<' '<<mp[nums[j]]<<endl;;
            mp[nums[j]]++;
            cnt+=(mp[nums[j]]*(mp[nums[j]]-1))/2;
            cout<<j<<' '<<cnt<<' '<<mp[nums[j]]<<endl;;
        }
        else mp[nums[j]]++;
        // cout<<j<<' '<<cnt<<endl;
        ans+=ans;
        while(cnt>=k){
            ans++;
            if(mp[nums[i]]>=2) cnt-=(mp[nums[i]]*(mp[nums[i]]-1))/2;
            mp[nums[i]]--;
            i++;  
        }
    }
    return ans;

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
