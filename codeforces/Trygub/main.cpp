#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		string s;
		cin>>s;

		for(int i=0;i<n;i++){
			if(s[i]=='b'){
				for(int j=0;j<n;j++){
					if(s[j]!='b'){
						s[i]=s[j];
						s[j]='b';
						break;
					}
				}
			}
		}

		cout<<s<<endl;
	}
}