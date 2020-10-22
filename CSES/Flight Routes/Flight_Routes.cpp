#include <bits/stdc++.h>
#define INF LONG_MAX/20

using namespace std;


int main(){

	int n,m,k;
	cin>>n>>m>>k;

	vector<pair<int,int>> nodes[n];
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;

		nodes[a].push_back({b,c});
	}

	//DJIKSTRA
	long long distances[n][k];
	for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
			distances[i][j]=INF;
	priority_queue<pair<long long,int>> q;

	q.push({0,0});

	while(!q.empty()){
		int a=q.top().second;
		long long d=-q.top().first;
		q.pop();

		if(distances[a][k-1] < d) continue;

		for(auto nei:nodes[a]){
			int b,c;
			b=nei.first;
			c=nei.second;
			q.push({-(d+c),b});
			if(distances[b][k-1] > d+c){
				distances[b][k-1]=d+c;
				sort(distances[b],distances[b]+k);
			}
		}
	}

	for(int i=0;i<k;i++){
		cout<<distances[n-1][i]<<" ";
	}
	cout<<endl;

	return 0;

}