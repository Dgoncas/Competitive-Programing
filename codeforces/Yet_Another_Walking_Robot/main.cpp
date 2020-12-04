#include <bits/stdc++.h>

using namespace std;

void process_move(char c,int *x,int *y){
	if(c=='U'){
		*y=*y+1;
	}else if(c=='D'){
		*y=*y-1;
	}else if(c=='R'){
		*x=*x+1;
	}else if(c=='L'){
		*x=*x-1;
	}
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n,x=0,y=0;char c;
		cin>>n;

		map<pair<int,int>,int> visited;

		visited[{0,0}]=1;

		pair<int,int> shorten={0,0};

		for(int i=2;i<=n+1;i++){
			cin>>c;

			process_move(c,&x,&y);

			auto search=visited.find({x,y});
			if(search!=visited.end()){
				int len=shorten.second-shorten.first+1;
				if(shorten.second==0 || i-(*search).second<len){
					shorten={(*search).second,i-1};
				}
			}

			visited[{x,y}]=i;
			
		}

		if(shorten.second==0) cout<<-1<<endl;
		else cout<<shorten.first<<" "<<shorten.second<<endl;

	}

	return 0;
}