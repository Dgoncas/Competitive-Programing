#include <bits/stdc++.h>

using namespace std;


map<char,char> parents;
map<char,int> ranks;

char find_set(char a){
	if(a == parents[a]){
		return a;
	}else{
		int parent = find_set(parents[a]);
		parents[a] = parent;
		return parent;
	}
}

void union_set(char a, char b){
	char set_a = find_set(a);
	char set_b = find_set(b);
	if(ranks[set_a]<ranks[set_b])
		swap(set_a, set_b);
	ranks[set_a] += ranks[set_b];
	ranks[set_b] = 0;
	parents[set_b] = set_a;
}


int main(){
	int n;
	scanf("%d\n",&n);

	while(n--){

		vector<pair<char,char>> edges;
		char a,b;
		while(scanf("(%c,%c)\n",&a,&b)){
			edges.push_back({a,b});
		}

		string line;
		getline(cin,line);
		getline(cin,line);

		for(int i=0; i<line.length(); i+=2){
			parents[line[i]] = line[i];
			ranks[line[i]] = 1;
		}

		for(auto e:edges){
			union_set(e.first,e.second);
		}

		int acorns = 0;
		for(auto r:ranks){
			if(r.second == 1)
				acorns ++;
		}

		set<char> trees;
		for(auto p:parents){
			trees.insert(find_set(p.second));
		}

		printf("There are %d tree(s) and %d acorn(s).\n",(int) trees.size()-acorns,acorns);

		parents.clear();
		ranks.clear();
	}

}
