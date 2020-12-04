#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n,a;
	cin>>n;

	long long sum=0;

	long long m=0;

	while(n--){
		cin>>a;
		sum+=a;
		m=max(m,a);
	}

	if(sum%2==0 && 2*m<=sum){cout<<"YES"<<endl;return 0;}
	cout<<"NO"<<endl;

	return 0;
}