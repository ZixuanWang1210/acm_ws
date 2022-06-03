#include<iostream>
using namespace std;

int main(){
    char  *str[100];
    char *p[100];

    int cnt; cin>>cnt;
    for(int i=1;i<=cnt;i++){
        cin>>str[cnt];
        p[i]=str[i];
    }
    
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(*str[i]>*str[j]){
                swap(p[i],p[j]);
            }
        }
    }

    for(int i=1;i<=cnt;i++){
        cout<<*p[i]<<endl;
    }
    


    return 0;
}