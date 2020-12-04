#include <bits/stdc++.h>

using namespace std;

pair<int,int> trees[(int) 1e5];

int main(){

	#define int long long

	int n,x,h,lp,sol=1;
	cin>>n;

	if(n<=2){cout<<n<<endl; return 0;}
	
	for(int i=0;i<n;i++){
		cin>>x>>h;
		trees[i]={x,h};
	}

	lp=trees[0].first;	

	for(int i=1;i<n;i++){

		lp=trees[i].first;

		if(trees[i].first-trees[i].second>lp){
			sol++;
		}else if(i==n-1 || trees[i].first+trees[i].second<trees[i+1].first){
			lp=trees[i].first+trees[i].second;
			sol++;
		}
	}

	cout<<sol<<endl;

	return 0;

}
