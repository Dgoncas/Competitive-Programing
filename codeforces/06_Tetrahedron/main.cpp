#include <bits/stdc++.h>
#define MOD (int)1000000007

using namespace std;

int main(){

	long long n;
	cin>>n;

	long long dp[4];
	dp[0]=1;
	dp[1]=0;
	dp[2]=0;
	dp[3]=0;

	for(long long i=0;i<n;i++){
		long long sum=0;
		for(int j=0;j<4;j++){
			sum+=dp[j];
			sum=sum%MOD;
		}

		for(int j=0;j<4;j++){
			dp[j]=sum-dp[j];
			if(dp[j]<0) dp[j]+=MOD;
		}
	}

	cout<<dp[0]<<endl;

	return 0;

}