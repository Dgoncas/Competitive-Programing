#include <bits/stdc++.h>

using namespace std;

int getSum(int64_t n){
	int res=0;
	while(n!=0){
		res+=n%10;
		n=n/10;
	}
	return res;
}

int getDigits(int64_t n){
	int res=0;
	while(n!=0){
		res++;
		n=n/10;
	}
	return res;
}

int64_t bigPow(int n){

	if(n==0){return 1;}
	int64_t res=10;
	for(int i=1;i<n;i++){
		res*=10;
	}
	return res;
}

int main(){

	int t; cin>>t;

	while(t--){

		int64_t n,n2;
		int s,sum,size;
		cin>>n>>s;
		size=getDigits(n);

		if(getSum(n)<=s){cout<<0<<endl;continue;}

		for(int i=0;i<size;i++){

			n2=n;
			n2+=(int64_t) bigPow(i+1);
			int64_t rest= (int64_t) (n2%((int64_t) bigPow(i+1)));
			n2-=rest;

			if(getSum(n2)<=s){break;}
		}

		cout<<(int64_t) (n2-n)<<endl;

	}
}