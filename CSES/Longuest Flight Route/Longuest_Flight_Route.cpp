#include <bits/stdc++.h>

using namespace std;

vector<int> nodes[(int) 1e5];
int dist[(int) 1e5];
int from[(int)1e5];
bool visited[(int) 1e5];

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		nodes[a].push_back(b);
	}

	//DJISKTRA
	for(int i=0;i<n;i++){dist[i]=-1;visited[i]=false;}
	dist[0]=0;

	priority_queue<pair<int,int>> q;
	q.push({0,0});
	
	while(!q.empty()){
		int a=q.top().second;q.pop();
		if(visited[a]) continue;
		visited[a]=true;

		for(auto b:nodes[a]){
			if(dist[a]+1>dist[b]){
				from[b]=a;
				dist[b]=dist[a]+1;
			}
			q.push({dist[b],b});
		}

	}

	if(dist[n-1]==-1){cout<<"IMPOSSIBLE";exit(0);}

	vector<int> sol;

	from[0]=-1;
	int i=n-1;
	while(i!=-1){
		sol.push_back(i);
		i=from[i];
	}

	reverse(sol.begin(),sol.end());

	cout<<sol.size()<<endl;
	for(auto n:sol) cout<<n+1<<" ";
	cout<<endl;

	return 0;
}