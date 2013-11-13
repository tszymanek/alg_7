//Tomasz Szymanek
//Generowanie wszystkich permutacji 
//przez minimalną liczbę transpozycji
#include <stdio.h>
#include <stdlib.h>

int count, *P, n;

int silnia(int n)
{
  return (n == 1 || n == 0) ? 1 : silnia(n - 1) * n;
}

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
	int i, Mi;
	int *I;
	I=malloc((m+1) * sizeof(int));
	for(i=1;i<=m;i++)
		I[i]=1;
	Mi=1;
	while(count<silnia(m)){
		if(I[Mi]==Mi){
			if(I[Mi]==1 && Mi==1){
				count++;
				printf("%d:\t", count);
				for(i=1;i<=n;i++)
					printf("%d ", P[i]);
				printf("\n");
			}
			for(i=1;i<=Mi;i++)
				I[i]=1;
			Mi++;
		}
		if(I[Mi]<Mi){ i=I[Mi];
			swap(&P[ B(Mi, i) ], &P[Mi]);
			I[Mi]++;
			Mi=1;
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
