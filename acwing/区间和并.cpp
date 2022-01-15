#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<pii> v;
int n;

void merge(vector<pii> &v){
    vector<pii> opt;
    int st = -1e9, ed = -1e9;
    for(auto item : v){
        if(ed < item.first){
            if(st != -1e9) opt.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else{
            ed = max(ed, item.second);
        }
    }
    if(st != -1e9) opt.push_back({st, ed});
    v = opt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());

    merge(v);

    cout << v.size();
    
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;

int n;
vector<pii> v;
vector<pii> opt;

int main(){
    cin >> n;

    int l, r;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());

    int ed = -1e9, st = -1e9;
    for(auto x : v){
        if(st == -1e9) st = x.first, ed = x.second;
        else{
            if(ed < x.first) opt.push_back({st, ed}), st = x.first, ed = x.second;
            else{
                ed = max(ed, x.second);
            }
        }
    }
    if(st != -1e9) opt.push_back({st, ed});
    v = opt;

    cout << v.size();
    
    return 0;
}
*/