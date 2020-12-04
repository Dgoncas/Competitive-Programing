#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	while(n--){

		int n2;
		cin>>n2;

		int a;

		int first=-1,last=-1;

		bool unordered=false;
		bool allUnordered=true;

		int temp=-1;
		int segments=1;

		for(int i=1;i<=n2;i++){
			cin>>a;

			if(a-i==0){allUnordered=false;}
			if(a-i!=0) unordered=true;	

			if(first!=-1){
				if((temp==0 && a-i!=0) || (temp != 0 && a-i == 0)){
					segments++;
				}	
			}

			if(first==-1){first=a;}
			if(i==n2){last=a;}

			temp = a-i;

		}

		if(unordered){
			if(allUnordered || (segments==2 && (first==1 || last == n2)) || (segments==3 && first==1 && last==n2)){
				cout<<1<<endl;
			}else{
				cout<<2<<endl;
			}
		}else{
			cout<<0<<endl;
		}

	}

}