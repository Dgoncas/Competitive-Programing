#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

#define INF INT_MAX/100



////////////////////// MAIN //////////////////////
int main(){

	freopen("input.txt","r",stdin);

	long n,m,a,b,c;
	cin>>n>>m;

	tuple<int,int,int> edges[m];
	int distance[n][n];

	//MAKE DISTANCES
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			distance[i][j]=INF;
			if(i==j) distance[i][j]=0;
		}
	}

	//READ INPUT
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		distance[a-1][b-1]=c;
		edges[i]=make_tuple(a-1,b-1,c);
	}

	//CALCULTE DISTANCES
	for(int j=0;j<n;j++){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				distance[a][b]=min(distance[a][b],distance[a][j]+distance[j][b]);
			}
		}
	}

	int res=INF;
	for(int i=0;i<m;i++){
		res=min(res,
			distance[0][get<0>(edges[i])]+get<2>(edges[i])/2+distance[get<1>(edges[i])][n-1]
			);
	}

	cout<<res<<endl;

	return 0;
}
///////////////////////////////////////////////////