#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int tower[n+1];
		for(int i=0;i<n;i++)
			cin>>tower[i];
		tower[n]=0;

		int dp[n+2][2];
		dp[n][0] = dp[n][1] = 0;
		dp[n+1][0] = dp[n+1][1] = 0;

		for(int i=n-1;i>-1;i--){
			for(int j=0;j<2;j++){
				if(j==0){ // OUR TURN
					dp[i][j] = min(
						dp[i+1][1],
						dp[i+2][1]);
				}else{ // FRIENDS TURN
					dp[i][j] = min(
						dp[i+1][0]+tower[i],
						dp[i+2][0]+tower[i]+tower[i+1]);
				}
			}
		}
		
		cout<<dp[0][1]<<endl;

	}
}