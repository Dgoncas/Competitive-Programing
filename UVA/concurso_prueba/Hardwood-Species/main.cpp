#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){



	int n;
	cin>>n;

	string tree;
	getline(cin,tree);
	getline(cin,tree);

	while(n--){

		map<string,lli> trees;
		lli total = 0;

		while(getline(cin,tree) && !tree.empty()){
			trees[tree] += 1;
			total += 1;
		}

		for(auto iter = trees.begin(); iter != trees.end(); iter++){
			float s = (iter -> second +0.0)/total*100;
			string n = iter -> first;
			cout<<n;
			printf(" %.4f\n",s);
		}
		if(n!=0)
			cout<<endl;

	}

	return 0;
}
