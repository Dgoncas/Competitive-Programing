#include <bits/stdc++.h>

#define ll long long
#define fo(i,in,en) for(i=in;i<=en;i++)

#define INF INT_MAX/10

typedef struct edge{
	int a,b,w;
} edge;

edge make_edge(int a, int b, int c){
	edge e;
	e.a=a;
	e.b=b;
	e.w=c;
	return e;
}

using namespace std;

int main(){

	freopen("input.txt","r",stdin);

	int i,j,k;
	int n,m;

	cin>>n>>m;

	edge edges[n];
	int d[n];

	fo(i,0,n-1) d[i]=INF;
	d[0]=0;

	fo(i,0,n-1){
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		edges[i]=make_edge(a,b,c);
	}

	fo(i,0,n-1){
		if(d[i] == INF){
			d[i]=0;

			int to[n];
			int cycle=-1;

			fo(j,0,n){
				fo(k,0,m-1){
					int a,b,w;
					a=edges[k].a;
					b=edges[k].b;
					w=edges[k].w;
					if(d[b]>d[a]+w){
						d[b]=d[a]+w;
						to[a]=b;
						if(j==n) cycle=a;
					}
				}
			}


			if(cycle!=-1){
				cout<<"YES"<<endl;
				cout<<cycle+1<<" ";
				int in=cycle;
				cycle=to[cycle];
				while(cycle!=in){
					cout<<cycle+1<<" ";
					cycle=to[cycle];
				}
				cout<<in+1<<endl;
				exit(0);
			}

		}
	}

	cout<<"NO"<<endl;

	return 0;
}
