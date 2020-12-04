#include <bits/stdc++.h>

using namespace std;

bool intersection(int l1,int u1,long long l2,long long u2,long long *li, long long *ui){
	
	*li=max((long long)l1,l2);
	*ui=min((long long)u1,u2);
	if(*li>*ui){return false;}
	return true;
}

int main(){

	int t; cin>>t;

	while(t--){

		int n,temp,time=0;
		cin>>n>>temp;

		long long lb=temp,ub=temp;
		bool able=true;

		while(n--){
			int a,b,c;
			cin>>a>>b>>c;

			int dif=a-time;

			lb-=dif;
			ub+=dif;

			if(!intersection(b,c,lb,ub,&lb,&ub)){
				able=false;
			}

			time=a;

		}

		if(able) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}