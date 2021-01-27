#include <bits/stdc++.h>

using namespace std;

int main(){
	long t;cin>>t;
	long long sum,rest,a,b;
	while(t--){
		cin>>sum>>rest;
		if(rest>sum || (sum+rest)%2!=0){
			cout<<"impossible"<<endl;
		}else{
			a = (sum+rest)/2;
			b = sum-a;
			cout<<a<<" "<<b<<endl;
		}
	}
}
