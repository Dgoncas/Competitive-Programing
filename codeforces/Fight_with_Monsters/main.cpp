#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,k;
	cin>>n>>a>>b>>k;

	int monsters[n];

	for(int i=0;i<n;i++) cin>>monsters[i];

	sort(monsters,monsters+n);

	int damage=0,index=0,turn_index=0,points=0;
	bool turn=true;

	vector<int> not_point_mosnters;

	while(index < n){ //all mosnters slayed on a loop die at same turn
		//advance turns until you can kill monsters
		while(damage<monsters[index]){
			damage+=turn? a:b;
			turn=!turn;
			turn_index++;
		}
		if(!turn) points++;
		else not_point_mosnters.push_back(ceil( (monsters[index]-(damage-b)) / ((float)a) ));
		index++; //a monster is killed
	}

	sort(not_point_mosnters.begin(),not_point_mosnters.end());
	for(auto d:not_point_mosnters){
		k-=d;
		if(k>=0) points++;
		else break;
	}


	cout<<points<<endl;

}