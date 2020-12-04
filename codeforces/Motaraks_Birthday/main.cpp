#include <bits/stdc++.h>
#define INF INT_MAX/2

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int numbers[n];
		for(int i=0;i<n;i++) cin>>numbers[i];

		int minimum=INF,maximum=-1;

		for(int i=1;i<n-1;i++){
			if((numbers[i]!=-1 && numbers[i-1]==-1) || (numbers[i]!=-1 && numbers[i+1]==-1)){
				minimum=min(minimum,numbers[i]);maximum=max(maximum,numbers[i]);
			}
		}

		if(numbers[0]!=-1 && numbers[1]==-1){
			minimum=min(minimum,numbers[0]);maximum=max(maximum,numbers[0]);
		}

		if(numbers[0]==-1 && numbers[1]!=-1){
			minimum=min(minimum,numbers[1]);maximum=max(maximum,numbers[1]);
		}

		if(numbers[n-2]==-1 && numbers[n-1]!=-1){
			minimum=min(minimum,numbers[n-1]);maximum=max(maximum,numbers[n-1]);
		}

		int subs=(minimum+maximum)/2;

		int ans=0;
		for(int i=0;i<n-1;i++){
			numbers[i]= numbers[i]==-1? subs:numbers[i];
			numbers[i+1]= numbers[i+1]==-1? subs:numbers[i+1];
			ans=max(ans,abs(numbers[i]-numbers[i+1]));
		}

		if(minimum == INF && maximum==-1) subs=0;
		cout<<ans<<" "<<subs<<endl;

	}


	return 0;
}