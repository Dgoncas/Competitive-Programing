#include <bits/stdc++.h>

using namespace std;


int main(){


	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		char table[n][n];
		for(int y=0;y<n;y++)
			for(int x=0;x<n;x++)
				cin>>table[y][x];


		for(int x=0;x<n;x++){
			for(int y=((x+2)%3);y<n;y+=3){
				if(table[y][x]!='.'){
					table[y][x]= table[y][x]=='X'? 'O':'X';
				}
			}
		}
		
		for(int y=0;y<n;y++){
			for(int x=0;x<n;x++)
				cout<<table[y][x];
			cout<<endl;
		}



	}
}