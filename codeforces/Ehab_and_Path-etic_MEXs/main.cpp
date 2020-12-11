#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;
	cin>>n;
	vector<int> nodes[n];
	vector<pair<int,int>> edges;
	while(cin>>a){
		cin>>b;
		a--;b--;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
		edges.push_back({a,b});
	}
	pair<long unsigned int,int> mx={0,0};
	for(int node=0;node<n;node++)
		if(nodes[node].size()>mx.first)
			mx={nodes[node].size(),node};
	int curr=0,curr2=mx.first;
	for(auto edge:edges){
		if(edge.first==mx.second || edge.second==mx.second){
			cout<<curr<<endl;
			curr++;
		}else{
			cout<<curr2<<endl;
			curr2++;
		}
	}
}