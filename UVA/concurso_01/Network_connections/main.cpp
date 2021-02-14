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
	if(ranks[set_b] > ranks[set_a])
		swap(set_a,set_b);
	ranks[set_a] += ranks[set_b];
	ranks[set_b] = 0;
	parents[set_b] = set_a;
}

int main(){

	int m;
	cin>>m;

	while(m--){
		int n;
		scanf("%d\n",&n);
		
		for(int i=1; i<=n; i++){
			parents[i] = i;
			ranks[i] = 1;
		}

		int succesfull = 0, unsuccesfull = 0;

		string line;
		while(getline(cin,line) && line!=""){
			stringstream linestream;
			linestream<<line;

			char c;
			int a,b;
			linestream>>c>>a>>b;

			if(c == 'c'){
				join_set(a,b);
			}else{
				if(find_set(a) == find_set(b))
					succesfull ++;
				else
					unsuccesfull ++;
			}
		}

		printf("%d,%d\n",succesfull,unsuccesfull);
		if(m!=0)
			cout<<endl;

		parents.clear();
		ranks.clear();

	}

	return 0;
}
