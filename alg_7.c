//Tomasz Szymanek
//Generowanie wszystkich permutacji 
//przez minimalną liczbę transpozycji
#include <stdio.h>
#include <stdlib.h>

int count, *P, n;

void swap(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}

int B(int m, int i){
	if((m%2==0) && (m>2)){
		if(i<(m-1))
			return i;
		else
			return m-2;
	}
	else
		return m-1;
}

void PERM(int m){
	int i;
	if (m==1){
		count++;
		printf("%d:\t", count);
		for(i=1;i<=n;i++)
			printf("%d ", P[i]);
		printf("\n");
	}
	else{
		for(i=1;i<=m;i++){
			PERM(m-1);
			if(i<m)
				swap(&P[B(m,i)], &P[m]);
		}
	}
}

int main(){
	int i;
	scanf("%d", &n);
	P=malloc((n+1) * sizeof(int));
	for(i=1;i<=n;i++)
		P[i]=i;
	count=0;
	PERM(n);
	return 0;
}
