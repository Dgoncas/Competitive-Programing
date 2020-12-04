#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int numbers[n+1];
		bool ocupied[n+1];

		int a;
		for(int i=0;i<n;i++){
			cin>>a;
			numbers[a-1]=i;
			ocupied[i]=false;
			ocupied[n]=true;
		}


		bool no=false;
		for(int i=0;i<n;i++){
			ocupied[numbers[i]]=true;
			if(!ocupied[numbers[i]+1]){
				if(numbers[i+1]!=numbers[i]+1){
					cout<<"NO"<<endl;
					no =true;
					break;
				}
			}
		}

		if(!no) cout<<"YES"<<endl;

	}


	return 0;

}