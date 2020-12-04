#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	while(n--){

		string line;
		cin>>line;

		int size=line.length();

		int ans=0;
		for(int x=0;x<10;x++){
			for(int y=0;y<10;y++){

				
				int xt=x,yt=y;

				int tempAns=0;
				for(int i=0;i<size;i++){
					if((int) line[i] - 48 == xt){
						tempAns++;
						swap(xt,yt);
					}

				} 

				if(xt != yt && tempAns % 2 ==1) tempAns--;
				ans=max(ans,tempAns);

			}
		}

		cout<<size-ans<<endl;

	}

	return 0;

}