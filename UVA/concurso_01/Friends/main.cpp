#include <bits/stdc++.h>

using namespace std;

map<int,int> parents;
map<int,int> ranks;

int find_set(int a){
	if(a == parents[a]){
		return a;
	}else{
		int parent = find_set(parents[a]);
		parents[a] = parent;
		return parent;
	}
}

void join_set(int a, int b){

	int set_a = find_set(a);
	int set_b = find_set(b);

	if(set_a != set_b){
		if(ranks[set_b] > ranks[set_a])
			swap(set_a,set_b);
		ranks[set_a] += ranks[set_b];
		ranks[set_b] = 0;
		parents[set_b] = set_a;
	}

}

int main(){

	int c;
	cin>>c;

	while(c--){
		int n,m;
		cin>>n>>m;

		for(int i=1;i<=n;i++){
			parents[i] = i;
			ranks[i] = 1;
		}

		int a,b;
		int ans = 1;
		while(m--){
			cin>>a>>b;
			join_set(a,b);
			ans = max(ans,ranks[find_set(a)]);
		}

		cout<<ans<<endl;

		parents.clear();
		ranks.clear();

	}

}
