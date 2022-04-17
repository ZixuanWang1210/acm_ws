#include<bits/stdc++.h>
using namespace std;

void sol(){
    int h,w,ox;
    cin>>ox>>h>>w;
    if(ox==1){
        if(h<130){
            cout<<"duo chi yu! ";
        }
        else if(h>130){
            cout<<"ni li hai! ";
        }
        else{
            cout<<"wan mei! ";
        }
        if(w<27){
            cout<<"duo chi rou!";
        }
        else if(w>27){
            cout<<"shao chi rou!";
        }
        else{
            cout<<"wan mei!";
        }
    }
    else{
        if(h<129){
            cout<<"duo chi yu! ";
        }
        else if(h>129){
            cout<<"ni li hai! ";
        }
        else{
            cout<<"wan mei! ";
        }
        if(w<25){
            cout<<"duo chi rou!";
        }
        else if(w>25){
            cout<<"shao chi rou!";
        }
        else if(w==25){
            cout<<"wan mei!";
        }
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) sol();
    
    return 0;
}