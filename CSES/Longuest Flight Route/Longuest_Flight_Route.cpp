#include <bits/stdc++.h>

using namespace std;

vector<int> nodes[(int)1e5];

int state[(int)1e5];
int maxDist[(int)1e5];
int from[(int)1e5];

vector<int> sorted;
vector<int> sol;


void topSort(int node){

	if(state[node]!=0) return;
	state[node]=1;
	for(auto nei:nodes[node]){
		topSort(nei);
	}
	state[node]=2;
	sorted.push_back(node);
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){state[i]=0;maxDist[i]=-1;}

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
	}

	topSort(0);
	if(state[n-1]==0){cout<<"IMPOSSIBLE"<<endl;return 0;}
	reverse(sorted.begin(),sorted.end());

	maxDist[0]=0;
	from[0]=-1;
	for(int n:sorted){
		for(int nei:nodes[n]){
			if(maxDist[n]+1>maxDist[nei]){
				maxDist[nei]=maxDist[n]+1;
				from[nei]=n;
			}
		}
	}

	cout<<maxDist[n-1]+1<<endl;

	int p=n-1;
	while(p!=-1){
		sol.push_back(p);
		p=from[p];
	}

	reverse(sol.begin(),sol.end());
	for(int n:sol) cout<<n+1<<" ";
	cout<<endl;
	
	return 0;
}