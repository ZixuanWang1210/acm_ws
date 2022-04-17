#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,c; 
    int b;
    cin>>a>>b>>c;
    double luo=0;
    if(b==0){
        luo=2.455*a;
    }
    else{
        luo=1.26*a;
    }

    if(luo<1){
        cout<<fixed<<setprecision(2)<<luo<< ' ';
        cout<<"^_^";
    }
    else{
        cout<<fixed<<setprecision(2)<<luo<< ' ';
        cout<<"T_T";
    }


    return 0;
}