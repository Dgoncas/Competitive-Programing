#include <bits/stdc++.h>

#define INF LONG_LONG_MAX/2
using namespace std;

int main(){

	int participants,budget,n,weeks;
	while(cin>>participants){
		cin>>budget>>n>>weeks;
		long long sol = INF;
		long long price;
		while(n--){
			cin>>price;
			price*=participants;
			for(int i=0;i<weeks;i++){
				int w;
				cin>>w;
				if(price<=budget && w>=participants){
					sol = min(sol,price);
				}
			}
		}
		if(sol==INF)
		cout<<"stay home"<<endl;
		else
			cout<<sol<<endl;
	}

}
