#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
bool inPath[100000];

vector<int> path;
vector<int> cycle;

void DFS(vector<int> *nodes,bool *inPath,bool *visited,int node){

	if(visited[node]){return;}
	visited[node]=true;

	inPath[node]=true;
	path.push_back(node);

	for(auto nei:nodes[node]){

		if(inPath[nei]){
			cycle.insert(cycle.begin(),nei+1);
			for(int i=path.size()-1;path[i]!=nei;i--){
				cycle.insert(cycle.begin(),path[i]+1);
			}
			cycle.insert(cycle.begin(),nei+1);
			cout<<cycle.size()<<endl;
			for(auto n:cycle) cout<<n<<" ";
			cout<<endl;
			exit(0);
		}

		DFS(nodes,inPath,visited,nei);

	}

	path.erase(path.end()-1);
	inPath[node]=false;

}

int main(){

	int n,m;
	cin>>n>>m;

	vector<int> nodes[n];

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
	}

	for(int i=0;i<n;i++){
		inPath[i]=0;
		visited[i]=0;
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			DFS(nodes,inPath,visited,i);
		}
	}

	cout<<"IMPOSSIBLE"<<endl;
	
	return 0;
}