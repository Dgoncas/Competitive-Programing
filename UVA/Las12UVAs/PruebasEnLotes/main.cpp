#include <bits/stdc++.h>
#define SIZE (long long int) 10000

using namespace std;

char* get(char *ans, int i,int j){
	return ans+i*(SIZE-1)+j;
}

int main(){

	char *ans=(char*) malloc((SIZE+1)*(SIZE-1));

	for(int i=1; i<SIZE+1; i++){

		int g1=ceil(i/2.0);
		int g2=i-g1;

		for(int j=0; j<i; j++){
			if(i<=1){
				*(get(ans,i,j)) = 1;
			}else{
				if(j<g1){
					*(get(ans,i,j)) = 2 + *(get(ans,g1,j));
				}else{
					*(get(ans,i,j)) = 2 + *(get(ans,g2,j-g1));
				}
			}
		}

	}

	int tam,pos;
	string s;
	while(true){
		cin>>tam;
		if(tam==0)
			break;

		getline(cin,s);
		getline(cin,s);

		pos = s.find('1');
		if(pos == -1){
			cout<<1<<endl;
			continue;
		}

		cout<<(int) *(get(ans,tam,pos))<<endl;
		cout.flush();

	}

}
