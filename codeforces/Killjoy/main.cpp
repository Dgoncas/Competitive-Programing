#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		long long sum=0,j;
		int n; 
		cin>>n>>j;

		bool all_inf=true;
		bool someone_inf=false;

		int r;
		for(int i=0;i<n;i++){
			cin>>r;
			sum+=r;
			if(r==j) someone_inf=true;
			if(r!=j) all_inf=false;
		}

		if(all_inf){cout<<0<<endl;continue;}
		if(someone_inf){cout<<1<<endl;continue;}
		if(sum%n==0 && sum/n==j){cout<<1<<endl;continue;}

		cout<<2<<endl;

	}

	return 0;

}