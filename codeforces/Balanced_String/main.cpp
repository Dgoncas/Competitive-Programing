#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		string res(n,'?');

		bool exit=false;
		for(int i=0;i<k;i++){
			for(int j=i;j<n;j+=k){
				if(res[i] == '?'){
					res[i]=s[j];
				}else{
					if(s[j] != '?' && res[i]!=s[j]){exit=true;}
				}
			}
		}

		if(exit){cout<<"NO"<<endl;continue;}
		
		int ones=0,zeros=0;
		for(int i=0;i<k;i++){
			if(res[i]=='1') ones++;
			if(res[i]=='0') zeros++;
		}

		if(ones>k/2 || zeros>k/2) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;

	}

	return 0;

}