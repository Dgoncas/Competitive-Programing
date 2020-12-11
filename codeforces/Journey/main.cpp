#include <bits/stdc++.h>

using namespace std;

double distances=0.0;

int dis = 0;
long double prob=1.0;

void dfs(int node,vector<int> *nodes,int p){
	if(nodes[node].size()==1 && nodes[node][0]==p){distances+=(long double)dis*prob;return;}
	long double temp=prob;
	prob=prob*((long double)1.0/(nodes[node].size() - (p==-1? 0:1)));
	dis++;
	for(auto n:nodes[node]){
		if(n!=p)
			dfs(n,nodes,node);
	}
	dis--;
	prob=temp;

}


int main(){

	int n;
	cin>>n;

	vector<int> nodes[n];

	int a,b;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	dfs(0,nodes,-1);

	printf("%.20lf\n",distances);

	return 0;

}