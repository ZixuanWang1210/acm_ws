#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> C;

void div(vector<int> &a, int b){
    int len=0,i=0,r=0;
    for(int i=a.size()-1; i>=0; i--){
        r = r*10+a[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(),C.end());
    // cout<<"OK"<<endl;
    while(C.back()==0) C.pop_back();
    // cout << C.size() << endl;
    if(C.size()==0) cout << 0;
    else 
        for(int i=C.size()-1; i>=0; i--)
            cout << C[i];
        
    cout << '.';
    // cout << "----" << endl;
    C.clear();
    while(r && len<k){
        len ++;
        r = r*10;
        C.push_back(r/b);
        r %= b;
    }
    for(int i=0; i<C.size(); i++) cout << C[i];
    while(len<k){
        len ++;
        cout << 0;
    }
}

int main()
{
    cin >> n >> k;
    int sum=0;
    for(int i=1;i <=n; i++){
        int x; cin >> x;
         sum += x;
    }
    if(sum==0){
        cout << "0.";
        for(int i=0; i<k; i++) cout << 0;
        return 0;
    }
    // cout << sum << endl;
    vector<int> a;
    while(sum){
        a.push_back(sum%10);
        sum /= 10;
    }

    div(a, n);

    return 0;
}