#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;
		int num[n];
		bool sum[n*(n+1)];
		for(int i=0;i<n*(n+1);i++) sum[i]=0;
		for(int i=0;i<n;i++) cin>>num[i];

		for(int i=0;i<n;i++){
			int sumtemp=num[i];
			for(int j=i+1;j<n;j++){
				sumtemp+=num[j];
				sum[sumtemp]=1;
			}
		}

		int count=0;
		for(int i=0;i<n;i++){
			if(sum[num[i]]){
				count++;
			}
		}

		cout<<count<<endl;

	}

	return 0;
}