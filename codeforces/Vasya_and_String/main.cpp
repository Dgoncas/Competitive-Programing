#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k;
	string s;

	cin>>n>>k>>s;

	char most='b';
	int ans=0;

	for(int i=0;i<2;i++){

		int k_count=0,size=0;
		int l=0;

		for(int r=0;r<s.length();r++){
			if(s[r]!=most) k_count++;

			while(k_count>k){
				if(s[l]!=most) k_count--;
				l++;
				size--;
			}
			size++;
			ans=max(size,ans);
		}

		most='a';

	}

	cout<<ans<<endl;


	return 0;

}