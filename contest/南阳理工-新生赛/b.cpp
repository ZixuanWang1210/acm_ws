#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int a[4];
struct p{
    int a, b, c, d;
    int step = 0;
};

queue<p> q;

bool check(p &a){
    if(a.a == a.b == a.c == a.d) return true;
    else return false;
}

int bfs(){
    while(!q.empty()){
        
        p top = q.front();
        int temp = q.front().a + 1;
        if(temp == 4) temp = 1;
        p tt = {temp, q.front().b, q.front().c, q.front().d, q.front().step + 1};
        q.push(tt);
        if(check(tt)) return tt.step;

        temp = q.front().b + 1;
        if(temp == 4) temp = 1;
        tt = {q.front().a, temp, q.front().c, q.front().d, q.front().step + 1};
        q.push(tt);
        if(check(tt)) return tt.step;

        temp = q.front().c + 1;
        if(temp == 4) temp = 1;
        tt = {q.front().a, q.front().b, temp, q.front().d, q.front().step + 1};
        q.push(tt);
        if(check(tt)) return tt.step;

        temp = q.front().d + 1;
        if(temp == 4) temp = 1;
        tt = {q.front().a, q.front().b, q.front().c, temp, q.front().step + 1};
        q.push(tt);
        if(check(tt)) return tt.step;

        q.pop();
    }


    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    p f; cin >> f.a >> f.b >> f.c >> f.d;
    q.push(f);


    cout << bfs();
    

    return 0;
}
