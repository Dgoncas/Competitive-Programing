#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int l,k;
		cin>>l>>k;

		int n=l/k;
		int m=k/2;

		int count[m+1][27];
		for(int i=0;i<m+1;i++){ for(int j=0;j<27;j++) count[i][j]=0; }

		string s;
		cin>>s;

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				count[i][s[i+j*k]-'a']++;
				count[i][s[k-1-i+j*k]-'a']++;
			}
		}

		if(k%2==1){
			for(int i=0;i<n;i++){
				count[m][s[m+k*i]-'a']++;
			}
		}	


		int res=0;
		for(int i=0;i<m;i++){
			int ma=0;
			for(int j=0;j<27;j++){
				ma=max(ma,count[i][j]);
			}
			res+=n*2-ma;
		}


		if(k%2==1){
			int ma=0;
			for(int i=0;i<27;i++){
				ma=max(ma,count[m][i]);
			}
			res+=n-ma;
		}

		cout<<res<<endl;


	}

	return 0;

}