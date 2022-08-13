#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s1,s2,s3,s4;
    for(int i=1;i<=n+1;i++) s1+='.',s2+='.',s3+='.',s4+='.';
    for(int i=1;i<=2*n+3;i++){
        s1+='@';
        if(i!=1){
            s2+='.',s3+='.',s4+='.';
        }
        else s2+='@',s3+='@',s4+='@';
    }
    for(int i=1;i<=n+1;i++) s1+='.',s2+='.',s3+='.',s4+='.';
    for(int i=1;i<=2*n+3;i++){
        s4+='@';
        if(i==1) s1+='@',s2+='@',s3+='@';
        else s1+='.',s2+='.',s3+='.';
    }
    for(int i=1;i<=n+1;i++) s1+='.',s2+='.',s3+='.',s4+='.';
    for(int i=1;i<=2*n+3;i++) {
        s4+='@';
        s1+='@';
        if(i==1) s2+='@';
        else s2+='.';
        if(i==2*n+3) s3+='@';
        else s3+='.';
    }
    for(int i=1;i<=n+1;i++) s1+='.',s2+='.',s3+='.',s4+='.';
    s1+='*',s2+='*',s3+='*',s4+='*';
    // cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;
    
    int len=0;
    for(int i=1;i<=4*n+5;i++){
        if(i==1||i==4*n+5){
            for(int j=1;j<=13*n+19;j++){
                cout<<"*";
            }
        }
        else if(i>=1&&i<=1+n){
            for(int j=1;j<=13*n+19;j++){
                if(j==1||j==13*n+19) cout<<"*";
                else cout<<".";
            }
            // cout<<endl;
        }
        else if(i<=1+n+2*n+3){
            len++;
            cout<<"*";
            for(int j=1;j<=n+1;j++) cout<<".";
            if(i==1+n+1||i==1+n+2*n+3){
                for(int j=1;j<=2*n+3;j++){
                    if(j==1||j==2*n+3) cout<<"@";
                    else cout<<".";
                }
                if(i==1+n+1) cout<<s1;
                else cout<<s4;
                // cout<<endl;
            }
            else{
                cout<<"@";
                for(int j=1;j<=len-2;j++) cout<<".";
                cout<<"@";
                for(int j=1;j<=2*n+1-len+1;j++) cout<<'.';
                cout<<'@';
                if(i<1+n+1+n+1) cout<<s2;
                else if(i==1+n+1+n+1) cout<<s1;
                else cout<<s3;
            }
        }
        else if(i>=1+n+2*n+3&&i<=4*n+5-1){
            for(int j=1;j<=13*n+19;j++){
                if(j==1||j==13*n+19) cout<<"*";
                else cout<<".";
            }
        }


        cout<<endl;
    }

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
