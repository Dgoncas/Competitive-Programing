#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,m;
	char c;
	cin>>t;
	while(t--){
		cin>>m>>n;
		int matrix[m][n];

		for(int y=0;y<m;y++){
			int width=0;
			for(int x=0;x<n;x++){
				cin>>c;
				if(c=='*')
					width++;
				else
					width=0;
				matrix[y][x]=width;
			}
		}

		int ans=0;
		for(int y=0;y<m;y++){
			for(int x=0;x<n;x++){
				for(int h=0;h+y<m && h+x<n;h++){
					if(matrix[y+h][x+h]>=(2*h+1))
						ans++;
					else
						break;
				}
			}
		}
		cout<<ans<<endl;

	}
}