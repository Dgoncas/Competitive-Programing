#include <bits/stdc++.h>

using namespace std;

set<int> component;
void dfs(bool* visited,vector<int> *nodes,int node){
	if(visited[node]) return;
	visited[node]=true;
	component.insert(node);
	for(auto nei:nodes[node])
		dfs(visited,nodes,nei);
}

int main(){
	int n,m,a,b;
	cin>>n>>m;

	vector<int> nodes[n];
	bool visited[n];
	for(int i=0;i<n;i++)
		visited[i]=false;

	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(visited,nodes,i);
			bool sum=true;
			for(auto n:component){
				if(nodes[n].size()!=2)
					sum=false;
			}
			if(sum) ans++;
			component.clear();
		}

	}

	cout<<ans<<endl;
}
