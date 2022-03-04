#include<iostream>
#include<algorithm>
using namespace std;

void sol() {
    
   int x1,y1,x2,y2,x3,y3;
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
 
   int y = max({y1,y2,y3});
   if(y==y1 && y==y2){
     cout<<abs(x2-x1)<<endl;
     return;
   }
   if(y==y1 && y==y3){
    cout<<abs(x1-x3)<<endl;
    return;
   }
   if(y==y2 && y==y3){
    cout<<abs(x2-x3)<<endl;
    return;
   }
   cout<<0<<endl;
 
    
}

int main(){
    int _; cin>>_;
    while(_--){
        sol();
    }
    return 0;
}