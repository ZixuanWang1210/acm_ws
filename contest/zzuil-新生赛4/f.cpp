#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int n;
int a[110][30];
string s[110];
struct Node
{
    int x;
    string s1, s2;
    bool operator<(const Node b){
        return this->x < b.x;
    }
};
vector<Node> v;


bool check(int x, int y){
    for(int i = 0; i <= 'z' - 'a'; i++){
        if(a[x][i] == 1 && a[y][i] == 1) 
            return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int k = 0; k < n; k++){
        // string s[k];
        cin >> s[k];
        for(int i = 0; i < s[k].length(); i++){
            a[k][s[k][i]-'a'] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(check(i, j)){
                int ans = s[i].length() * s[j].length();
                v.push_back({ans, s[i], s[j]});
            }
        }
    }

    sort(v.begin(), v.end());

   
    int l = v.size() - 1;
    cout << v[l].x << " " << v[l].s1 << " " << v[l].s2;

    return 0;
}
