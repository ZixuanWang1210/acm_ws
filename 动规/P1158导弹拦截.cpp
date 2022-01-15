#include <bits/stdc++.h> 
using namespace std;
inline int dist(int x1,int y1,int x2,int y2){return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}

int a_x, a_y, b_x, b_y, n, cost;
priority_queue<int>pqa, pqb;
typedef struct missile{
    int x, y;
};missile a[100010];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int dis1, dis2;
    cin>>a_x>>a_y>>b_x>>b_y;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        dis1 = dist(a[i].x, a[i].y, a_x, a_y);
        dis2 = dist(a[i].x, a[i].y, b_x, b_y);
        if(dis1 <= dis2){
            pqa.push(dis1);
        }
        else{
            pqb.push(dis2);
        }
    }

    //cost = pqa.top() + pqb.top();
    cout << pqa.top() + pqb.top();
    return 0;
}
