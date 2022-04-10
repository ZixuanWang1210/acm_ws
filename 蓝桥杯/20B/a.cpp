#include<bits/stdc++.h>
using namespace std;

string to_string(int x){
	string res;
	while(x){
		int t=x%10;
		char tt=t+'0';
		res=tt+res;
		x/=10;
	}
	return res;
}

string rev(string s){
	string res;
	for(int i=0;i<s.length();i++){
		res=s[i]+res;
	}
	return res;
}


int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};


int main(){
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	
	int yy,mm,dd;
	int t; cin>>t;
	yy=t/10000;
	t-=10000*yy;
	mm=t/100;
	t-=100*mm;
	dd=t;
	
	while(1){
		int op=yy;
		int m,d;
		m=op%10;
		op/=10;
		m*=10;
		m+=op%10;
		op/=10;
		d=op%10;
		op/=10;
		d*=10;
		d+=op;
		if(m>12){
			yy++;
			continue;
		}
		if(dd>day[m]){
			yy++;
			continue;
		}
		if((m==mm&&d>dd)||m>mm){
			cout<<yy;
			if(m<10) cout<<0<<m;
			else cout<<m;
			if(d<10) cout<<0<<d;
			else cout<<d; 
			cout<<endl;
			break;
		}
		else yy++;	
	}
	
	while(1){
		int op=yy;
		op/=100;
		int x=op;
		int m=op%10;
		m*=10;
		op/=10;
		m+=op;
		int d=m;

		if(m>12){
			yy+=100;
			continue;
		}
		if(dd>day[m]){
			yy+=100;
			continue;
		}

			cout<<x<<x;
			if(m<10) cout<<0<<m;
			else cout<<m;
			if(d<10) cout<<0<<d;
			else cout<<d; 
			cout<<endl;
			break;
		

		cout<<fixed<<setprecision
		
	}
	
				

	
	return 0;
} 
