#include <bits/stdc++.h>

using namespace std;



int main(){

	vector<int> numbers;

	char c;
	while(cin>>c){
		numbers.push_back((int)c - 48);
	}

	bool dp[numbers.size()][8];
	int prev[numbers.size()][8];
	memset(prev,-1,sizeof(prev));

	vector<int> sol;


	for(int i=0;i<numbers.size();i++){
		for(int j=0;j<8;j++){
			dp[i][j]=false;
		}
	}

	for(int i=0;i<numbers.size();i++){

		dp[i][numbers[i]%8]=true;

		for(int j=0;j<8;j++){
			
			if(i>0 && dp[i-1][j]){
				dp[i][j]=true;
				prev[i][j]=j;

				dp[i][(j*10+numbers[i])%8]=true;
				prev[i][(j*10+numbers[i])%8]=j;

			}
			
		}
		

		if(dp[i][0]==true){
	
			cout<<"YES"<<endl;

			int j=0;

			while (true) {
                if (prev[i][j] == -1 || prev[i][j] != j) {
                    sol.push_back(numbers[i]);
                }
 
                if (prev[i][j] == -1) break;
 
                j = prev[i][j];
                i--;
            }
            reverse(sol.begin(),sol.end());
            for(auto p:sol)
            	cout<<p;
            cout<<endl;

			return 0;
		}

	}

	cout<<"NO"<<endl;
	return 0;
}