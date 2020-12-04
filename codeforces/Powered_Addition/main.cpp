#include <bits/stdc++.h>

using namespace std;

int main(){


	int t;
	cin>>t;	

	while(t--){
		bool first=true;
		int n,x,y;
		cin>>n;
		long long m=0;

		while(n--){
			cin>>y;
			if(!first){
				long long dif=y-x;
				if(dif<0){
					dif=-dif;
					long long sec=int(log2(dif))+1;
					m=max(sec,m);
					y=x;
				}
			}
			first=false;
			x=y;
		}

		cout<<m<<endl;
	}

	return 0;

}
