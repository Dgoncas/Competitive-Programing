#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n,m;
		cin>>n>>m;
		int matrix[n][m];
		for(int y=0;y<n;y++)
			for(int x=0;x<m;x++)
				cin>>matrix[y][x];

		int nodes=(n+m-1)/2;
		map<int,int> steps[nodes+1];

		for(int y=0;y<n;y++){
			for(int x=0;x<m;x++){

				int d1=x+y;
				int d2=(m-1-x)+(n-1-y);
				if(d1>d2)
					steps[d2][matrix[y][x]]++;
				else if(d2>d1)
					steps[d1][matrix[y][x]]++;

			}
		}

		int ans=0;

		for(auto step:steps)
			ans+=min(step[0],step[1]);

		cout<<ans<<endl;
	}

	return 0;
}