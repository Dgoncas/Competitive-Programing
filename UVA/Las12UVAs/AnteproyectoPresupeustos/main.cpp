#include <bits/stdc++.h>
#define lli long long int

using namespace std;

lli gastos(int *sueldos, int nsueldos, int umbral){

	lli suma = 0;

	for(int i = 0; i<nsueldos; i++){
		if(sueldos[i]<umbral){
			suma += (lli) sueldos[i];
		}
		else{
			suma += ((lli) umbral)*(nsueldos-i);
			break;
		}
	}

	return suma;

}

int main(){

	int reservas, nsueldos;
	while(cin>>reservas){
		cin>>nsueldos;

		int sueldos[nsueldos];
		for(int i=0; i<nsueldos; i++)
			cin>>sueldos[i];

		sort(sueldos,sueldos+nsueldos);


		int min=0, max = sueldos[nsueldos-1], medio;
		while(min<=max){

			medio = (min+max)/2;
			lli g = gastos(sueldos,nsueldos,medio);

			if(g < reservas){
				min = medio+1;
			}else if(g > reservas){
				max = medio-1;
			}else{
				min = max = medio;
				break;
			}

		}

		if(min == max+1){
			medio = (reservas-gastos(sueldos,nsueldos,min)) > 0 ? min:max;
		}

		lli gast_prev = gastos(sueldos,nsueldos,medio);
		while(gast_prev == gastos(sueldos,nsueldos,medio-1))
			medio--;

		cout<<medio<<endl;

	}

}