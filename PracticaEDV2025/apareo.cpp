#include <iostream>
using namespace std;

void apareo(int v1[], int v2[], int v3[], int N, int M);
int main(){
    int v1[10];
    int v2[5];
    int v3[15];
    int N, M;
    apareo(v1,v2, v3,  N, M);
    return 0;
}

void apareo(int v1[], int v2[], int v3[], int N, int M){
    int i=0;
    int j=0;
    int k=0;
    while(i<N && j<M){
        if(v1[i]<v2[j]){
            v3[k] = v1[i];
            i++;
        }
		else{
			v3[k]=v2[j];
			j++;		
		}
		k++;
	}
	while(i<N){
		v3[k]=v1[i];
		i++;
		k++;
	}
	while(j<M){
		v3[k]=v2[j];
		j++;
		k++;
	}

}