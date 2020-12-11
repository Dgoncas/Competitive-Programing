#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		vector<pair<int,int>> points;

		int a,b;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			points.push_back({a,b});
		}


		bool valid=false;
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second)<=k){
					count++;
				}
			}
			if(count==n) valid=true;
		}

		if(valid) cout<<1<<endl;
		else cout<<-1<<endl;

	}
}