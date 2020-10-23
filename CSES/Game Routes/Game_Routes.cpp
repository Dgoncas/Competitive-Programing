#include <bits/stdc++.h>

#define MOD (long long) 1e9+7

using namespace std;


vector<int> nodes[(int)1e5];
vector<int> sorted;

int states[(int)1e5];
long long ways[(int)1e5];

void topSort(int node){
	if(states[node]!=0) return;
	states[node]=1;
	for(int nei:nodes[node]){
		topSort(nei);
	}
	states[node]=2;
	sorted.push_back(node);
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
	}

	topSort(0);
	reverse(sorted.begin(),sorted.end());

	for(int i=0;i<n;i++) ways[i]=0;

	ways[0]=1;
	for(int node:sorted){
		for(int nei:nodes[node]){
			ways[nei]+=ways[node];
			ways[nei]%=MOD;
		}
	}

	cout<<ways[n-1];
}