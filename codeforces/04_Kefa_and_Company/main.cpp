#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,d;
	cin>>n>>d;

	pair<int,int> friends[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		friends[i]={a,b};
	}

	sort(friends,friends+n);

	long long frienship=friends[0].second;
	long long money=friends[0].first;
	long long ans=frienship;
	int l=0,r=1;

	while(l<n){
		if(r<n && friends[r].first < money+d){
			frienship+=friends[r].second;
			r++;
		}else{
			frienship-=friends[l].second;
			l++;
			money=friends[l].first;
		}
		ans=max(ans,frienship);
	}

	cout<<ans<<endl;

	return 0;

}