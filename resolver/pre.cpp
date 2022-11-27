#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

    string t,name,time1,time2,id,res,lag;
    while(cin>>t>>name>>id>>res>>t>>t>>t>>lag>>time1>>time2){
        cout<<time1<<' '<<time2<<' '<<name<<' '<<id<<' ';
        if(res=="答案正确") cout<<"Accepted";
        else if(res=="编译错误") cout<<"Compilation error";
        else cout<<"Wrong answer";
        cout<<endl;
    }

}