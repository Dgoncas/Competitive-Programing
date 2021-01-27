#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		int monsters[3];

		for(int i=0;i<3;i++)
			cin>>monsters[i];

		sort(monsters,monsters+3);
		reverse(monsters,monsters+3);
		int ab,c;
		ab = monsters[0]+monsters[1];
		c = monsters[2];

		if(ab%7==0 and (c=ab/7))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;


	}

}