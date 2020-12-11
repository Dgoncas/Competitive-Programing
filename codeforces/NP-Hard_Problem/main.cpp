#include <bits/stdc++.h>

using namespace std;

bool dfs(int* colors,vector<int>* nodes,int node,int color){
	if(colors[node]!=-1){
		if(colors[node]!=color){
			return false;
		}
		return true;
	}
	colors[node]=color;
	bool possible=true;
	for(auto nei:nodes[node])
		possible= dfs(colors,nodes,nei, color==1? 0:1) && possible;
	return possible;
}

int main(){

	int n,m,a,b;
	cin>>n>>m;

	vector<int> nodes[n];
	int color[n];
	for(int i=0;i<n;i++)
		color[i]=-1;

	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	for(int i=0;i<n;i++){
		if(color[i]==-1){
			if(!dfs(color,nodes,i,0)){
				cout<<-1<<endl;
				return 0;
			}
		}
	}

	set<int> s1,s2;
	for(int i=0;i<n;i++){
		if(color[i]==1)
			s1.insert(i);
		else
			s2.insert(i);
	}

	cout<<s1.size()<<endl;
	for(auto node:s1)
		cout<<node+1<<" ";
	cout<<endl<<s2.size()<<endl;
	for(auto node:s2)
		cout<<node+1<<" ";
	cout<<endl;
	
}