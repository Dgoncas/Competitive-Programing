#include <bits/stdc++.h>

#define MOD (long long) 1e9+7
#define INF LONG_MAX/10;

using namespace std;


vector<pair<int,int>> nodes[(int)1e5];
vector<int> sorted;

int states[(int)1e5];
long long ways[(int)1e5];

long long minPrice[(int)1e5];

void topSort(int node){
	if(states[node]!=0) return;
	states[node]=1;
	for(auto nei:nodes[node]){
		topSort(nei.first);
	}
	states[node]=2;
	sorted.push_back(node);
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		nodes[a].push_back({b,c});
	}

	topSort(0);
	reverse(sorted.begin(),sorted.end());

	for(int i=0;i<n;i++){
		minPrice[i]=INF;
	}

	minPrice[0]=0;

	ways[0]=1;
	for(auto node:sorted){
		for(auto nei:nodes[node]){
			minPrice[nei.first]=min(minPrice[nei.first],minPrice[node]+nei.second);
		}
	}

	cout<<minPrice[n-1]<<" ";

	return 0;
}