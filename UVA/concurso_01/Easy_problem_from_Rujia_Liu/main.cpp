#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,q,k,v,r;

	while(cin>>n>>q){

		map<int,vector<int>> ocurrences;

		for(int i=0;i<n;i++){
			cin>>r;
			ocurrences[r].push_back(i+1);
		}

		while(q--){
			cin>>k>>v;
			k--;
			if(k<ocurrences[v].size())
				cout<<ocurrences[v][k]<<endl;
			else
				cout<<'0'<<endl;
		}
	}

}
