#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;
struct node{
    string name;
    int cnt;
    double avg;
    bool operator<(const node &t) const{
        if(cnt==t.cnt) return avg>t.avg;
        else return cnt>t.cnt;
    }
};
vector<node> v;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        string name; int sum;
        cin>>name>>sum;
        set<int> st;
        for(int j=1;j<=sum;j++){
            int t; cin>>t;
            st.insert(t);
        }
        int cnt=st.size();
        double avg=(double)cnt/sum;

        v.push_back({name,cnt,avg});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<3;i++){
        if(i+1>v.size())cout<<'-';
        else cout<<v[i].name;
        if(i!=2) cout<<" ";
    }
    return 0;
}