/*
已知：珍珠有(c1, c2, ..., cn)共n个品级，对应不同的价格(p1, p2, ..., pn)。购买品级为ci的珍珠需缴纳且只缴纳一次额外费用，具体值为10*pi。现购买一批珍珠，购买数量为(a1, a2, ..., an)，ai代表购买品级为ci的珍珠的数量。整个数量结构可以变动，规则为：可购买需要品级的珍珠或同等数量更高品级的珍珠，但不能购买更低等级的珍珠

求：购买珍珠的最少花费


输入：第1行为case数；第2行为case 1的品级数；第2行至第n行为case1的各品级的ai，pi；第n+1行为case2的品级数……

输出：最少花费
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int case_n;
int class_n;
int a[110];
int p[110];
long e[110];
long dp(){
	int ee;  
	e[0] = (a[0]+10)*p[0];
	for(int i = 1; i < class_n; i++){
		e[i] = LONG_MAX;
		for(int j = -1; j < i; j++){
			ee = 0;  
			for(int k = j+1; k <= i; k++){
				ee += a[k];
			}
			if(j == -1)
				ee = (ee+10)*p[i];
			else
				ee = e[j]+(ee+10)*p[i];
			e[i] = (ee < e[i]) ? ee : e[i];
		}
	}
	return e[class_n-1];
}

int main(){
	scanf("%d", &case_n);
	for(int i = 0; i < case_n; i++){
		scanf("%d", &class_n);
		for(int j = 0; j < class_n; j++){
			scanf("%d%d", &a[j], &p[j]);
		}
		printf("%ld\n", dp());
	}
	return 0;
}