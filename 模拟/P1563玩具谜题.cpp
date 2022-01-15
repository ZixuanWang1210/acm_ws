#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

typedef struct node{
    int id;
    string name;
    int dir;
    bool operator < (const node &a) const {
        return id < a.id; 
    }
}node;
queue<node> pq;
typedef pair<int, int> pii;
queue<pii>q;
unordered_map<int, string>mp;
unordered_map<int, int>map_id2dir;
int n=0, m=0, now_id = 0;

int move(int id, int opt, int step){
    int g_id;
    if(opt == 1){
        g_id = id + step;
        if(g_id >= n) g_id -= n;
    }
    else if(opt == 0){
        g_id = id - step;
        if(g_id < 0) g_id += n;
    }
    return g_id;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    node preson;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> preson.dir >> preson.name;
        preson.id = i;
        pq.push(preson);
        mp[i] = preson.name;
        map_id2dir[i] = preson.dir;
    }
    for(int i = 0; i < m; i++){
        pii temp;  
        cin >> temp.first >> temp.second;
        q.push(temp);
    }
    
    int flag = 1, opt;
    while(!q.empty()){
        if(map_id2dir[now_id] == 1) opt = abs(q.front().first - 1);
        else opt = q.front().first;
        now_id = move(now_id, opt, q.front().second);
        q.pop();
    }
    cout << mp[now_id];
    return 0;
}
