#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,x,y;
	cin>>n>>m;

	vector<pair<int,int>> ans;

	if(n>m){
		x=0;y=m;
		while(y>=0){
			if(!(x==0 && y==0))
				ans.push_back({x,y});
			x++;
			y--;
		}
	}else{
		x=n;y=0;
		while(x>=0){
			if(!(x==0 && y==0))
				ans.push_back({x,y});
			x--;
			y++;
		}
	}

	cout<<ans.size()<<endl;
	for(auto p:ans)
		cout<<p.first<<" "<<p.second<<endl;

	return 0;
}