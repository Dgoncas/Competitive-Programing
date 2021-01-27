#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	char l[]={'c','b','a'};
	while(t--){

		int n,k;
		cin>>n>>k;

		for(int i=0;i<k;i++) cout<<'a';
		for(int i=k;i<n;i++) cout<<l[(i-k)%3];
		cout<<endl;

	}
}