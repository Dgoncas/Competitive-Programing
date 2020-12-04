#include <bits/stdc++.h>


#define MOD (long long) 1e9+7

using namespace std;

int main(){

	long long n;
	long long res=1;
	long long rest=1;

	cin>>n;

	if(n==0){cout<<0<<endl;return 0;}

	for(int i=n;i>0;i--){
		res*=i;
		if(i!=1) rest*=2;
		rest%=MOD;
		res%=MOD;
	}
	res-=rest;
	if(res<0) res+=MOD;
	cout<<res<<endl;

	return 0;
}