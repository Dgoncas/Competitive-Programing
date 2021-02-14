#include <bits/stdc++.h>

using namespace std;



map<string,string> parents;
map<string,int> ranks;

string find_set(string a){
	if(a == parents[a]){
		return a;
	}else{
		string parent = find_set(parents[a]);
		parents[a] = parent;
		return parent;
	}
}

void join_set(string a, string b){
	string set_a = find_set(a);
	string set_b = find_set(b);
	if(set_a != set_b){
		if(ranks[set_b] > ranks[set_a])
			swap(set_a,set_b);
		ranks[set_a] += ranks[set_b];
		ranks[set_b] = 0;
		parents[set_b] = set_a;
	}
}



int main(){

	int n;
	cin>>n;
	while(n--){
		int friendships;
		cin>>friendships;

		while(friendships--){
			string a(21,' '),b(21,' ');
			scanf("%s %s\n",&a[0],&b[0]);

			if(parents.find(a) == parents.end()){
				parents[a] = a;
				ranks[a] = 1;
			}

			if(parents.find(b) == parents.end()){
				parents[b] = b;
				ranks[b] = 1;
			}

			join_set(a,b);
			cout<<ranks[find_set(a)]<<endl;

		}

		parents.clear();
		ranks.clear();
	}

}