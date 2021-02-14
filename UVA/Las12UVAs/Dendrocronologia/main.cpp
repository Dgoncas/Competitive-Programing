#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){

	int n;
	while(cin>>n){

		int a,b,c;
		lli r;
		b = n;

		int rsize = (int) ceil(n/2.0);
		vector<lli> rings(rsize,(lli) 0);

		for(int y=0; y<n; y++){

			a = c = (n-abs(b))/2;

			int j=0;
			for(int i = 0;i<a;i++){
				cin>>r;
				j++;
				rings[i] += r;
			}

			for(int i=0;i<abs(b);i++){
				cin>>r;
				j++;
				rings[a] += r;
			}

			for(int i=c-1;i>-1;i--){
				cin>>r;
				j++;
				rings[i] += r;
			}

			b-=2;
			if(b==-1)
				b=-3;
			if(b==0)
				b=-2;
		}
		
		for(int i=rsize-1;i>-1;i--){
			cout<<rings[i];
			if(i!=0)
				cout<<" ";
		}
		cout<<endl;

	}

	return 0;

}
