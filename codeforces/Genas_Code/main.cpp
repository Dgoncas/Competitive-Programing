#include <bits/stdc++.h>

using namespace std;

bool check(string number){
	for(int i=number.length()-1;i>0;i--){
		if(number[i] != '0')
			return false;
	}
	return number[0]=='1';
}

int main(){
	int n,zero_count=0;
	string r,sol="-1";
	cin>>n;

	while(cin>>r){
		if(r=="0"){cout<<0<<endl;exit(0);}
		if(!check(r)){
			sol=r;
		}
		else{
			zero_count += r.length()-1;
		}

	}

	cout<< (sol =="-1"? "1":sol);
	for(int i=0;i<zero_count;i++)
		cout<<'0';
	cout<<endl;
}