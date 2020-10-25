#include <bits/stdc++.h>

#define INF LONG_MAX/2
#define MOD ((long long)1e9+7)

using namespace std;

vector<pair<int,int>> nodes[(int)1e5];

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		nodes[a].push_back({b,c});
	}

	long long dist[n];
	priority_queue<pair<int,int>> q;
	bool visited[n];

	int numMinPriceRoutes[n];
	int minF[n];
	int maxF[n];


	for(int i=0;i<n;i++){
		dist[i]=INF;
		visited[i]=0;

		numMinPriceRoutes[i]=0;
		minF[i]=INF;
		maxF[i]=0;
	}

	dist[0]=0;
	numMinPriceRoutes[0]=1;
	minF[0]=0;
	maxF[0]=0;

	q.push({0,0});
	while(!q.empty()){
		int a=q.top().second;q.pop();
		if(visited[a]) continue;
		visited[a]=true;

		for(auto nei:nodes[a]){
			int b=nei.first; int d=nei.second;

			if(dist[a]+d < dist[b]){
				dist[b]=dist[a]+d;

				numMinPriceRoutes[b]=numMinPriceRoutes[a];
				minF[b]=minF[a]+1;
				maxF[b]=maxF[a]+1;
			}else if(dist[a]+d == dist[b]){
				numMinPriceRoutes[b]+=numMinPriceRoutes[a];
				numMinPriceRoutes[b]%=MOD;
				minF[b]=min(minF[a]+1,minF[b]);
				maxF[b]=max(maxF[a]+1,maxF[b]);
			}

			q.push({-dist[b],b});
		}
	}

	cout<<dist[n-1]<<" ";
	cout<<numMinPriceRoutes[n-1]<<" ";
	cout<<minF[n-1]<<" ";
	cout<<maxF[n-1]<<endl;

	return 0;
}