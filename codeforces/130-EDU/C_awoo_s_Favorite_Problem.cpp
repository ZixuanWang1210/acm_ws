#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

// void sol(){
//     int n; cin>>n;
//     string s1,s2; cin>>s1>>s2;
//     for(int i=0;i<n-1;i++){
//         if(s1[i]!=s2[i]){
//             if(s1[i]=='a'&&s1[i+1]=='b'){
//                 s1[i]='b',s1[i+1]='a';
//             }
//             else if(s1[i]=='b'&&s1[i+1]=='c'){
//                 s1[i]='c',s1[i+1]='b';
//             }
//             else if(s2[i]=='a'&&s2[i+1]=='b'){
//                 s2[i]='b',s2[i+1]='a';
//             }
//             else if(s2[i]=='b'&&s2[i+1]=='c'){
//                 s2[i]='c',s2[i+1]='b';
//             }
//             if(s1[i]!=s2[i]){
//                 cout<<"NO"<<endl;
//                 return;
//             }
//         }
//     }
//     if(s1[n-1]!=s2[n-1]) {
//         cout<<"NO"<<endl;
//         return;
//     }
//     cout<<"YES"<<endl;

// }

void sol(){
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    s1=' '+s1;
    s2=' '+s2;
    int cnta1=0,cnta2=0,cntc1=0,cntc2=0;
    vector<int> a(n+1),c(n+1);
    vector<int> a1(n+1),c1(n+1);
    for(int i=1;i<=n;i++){
        if(s1[i]=='a') a[i]++,cnta1++;
        else if(s1[i]=='c') c[i]++,cntc1++;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+a[i];
        c[i]=c[i-1]+c[i];
    }

    for(int i=1;i<=n;i++){
        if(s2[i]=='a') a1[i]++,cnta2++;
        else if(s2[i]=='c') c1[i]++,cntc2++;
    }
    for(int i=1;i<=n;i++){
        a1[i]=a1[i-1]+a1[i];
        c1[i]=c1[i-1]+c1[i];
    }

    if(cnta1!=cnta2||cntc1!=cntc2){
        cout<<"NO"<<endl;
        return;
    }
    if(n==1&&s1[1]!=s2[1]){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i]<a1[i]||c[i]>c1[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

// void sol(){
//     int n; cin>>n;
//     string s1,s2; cin>>s1>>s2;
//     int cnt1a=0,cnt1b=0,cnt2a=0,cnt2b=0;
//     for(int i=0;i<n;i++){
//         if(s1[i]=='a'&&s1[i+1]=='b') cnt1a++,i++;
//         else if(s1[i]=='b'&&s1[i+1]=='c') cnt1b++,i++;
//     }
//     for(int i=0;i<n;i++){
//         if(s2[i]=='b'&&s2[i+1]=='a') cnt2a++,i++;
//         else if(s2[i]=='c'&&s2[i+1]=='b') cnt2b++,i++;
//     }

//     if(cnt1a||cnt2a){
//         if(cnt1a!=cnt2a){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     if(cnt1b||cnt2b){
//         if(cnt1b!=cnt2b){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     cout<<"YES"<<endl;


// }

// void sol(){
//     int n; cin>>n;
//     string s1,s2; cin>>s1>>s2;
//     string s11,s22;
//     for(int i=0;i<n;i++){
//         if(s1[i]!=s2[i]){
//             s11=s11+s1[i];
//             s22=s22+s2[i];
//         }
//     }

//     for(int i=0;i<s11.length();i+=2){
//         if(s11[i]=='a'&&s11[i+1]=='b'){
//             swap(s11[i],s11[i+1]);
//         }
//         else if(s11[i]=='b'&&s11[i+1]=='c'){
//             swap(s11[i],s11[i+1]);
//         }
//     }
//     if(s11==s22){
//         cout<<"YES"<<endl;
//     }
//     else cout<<"NO"<<endl;
// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
