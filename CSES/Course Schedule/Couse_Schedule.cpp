 #include <bits/stdc++.h>

using namespace std;


vector<int> nodes[(int)1e5];
int states[(int)1e5];
vector<int> init;

vector<int> ans;

void DFS(int node){

	if(states[node]==2) return;
	if(states[node]==1){cout<<"IMPOSSIBLE"<<endl;cout.flush();exit(0);}
	states[node]=1;

	for(auto nei:nodes[node]){
		DFS(nei);
	}

	ans.push_back(node+1);
	states[node]=2;

}

int main(){

	int n,m;
	cin>>n>>m;

	bool hasEntry[n];
	for(int i=0;i<n;i++) hasEntry[i]=false;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		hasEntry[a]=true;
		nodes[b].push_back(a);
	}

	for(int i=0;i<n;i++){
		if(!hasEntry[i]){
			init.push_back(i);
		}
	}

	if(!init.size()){
		cout<<"IMPOSSIBLE"<<endl;
		exit(0);
	}

	for(int i=0;i<init.size();i++){
		DFS(init[i]);
	}

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}


	return 0;

}