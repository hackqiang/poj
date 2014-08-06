#include <iostream>  
using namespace std;  
#define max(a,b) a>b?a:b  
#define MAXV 50010  
#define inf -10010  
  
int lt[MAXV],rt[MAXV],a[MAXV],rtm[MAXV];  
  
int main(){  
	int t,n,i,temp;  
	scanf("%d",&t);  
	while(t--){  
		scanf("%d",&n);  
		for(i=1;i<=n;i++)  
			scanf("%d",&a[i]);  
  
		temp=inf;lt[1]=a[1];rt[n]=a[n];  
		for(i=2;i<=n;i++){  
			lt[i]=max(a[i],lt[i-1]+a[i]);         
		}  
		for(i=n-1;i>=1;i--){  
			rt[i]=max(a[i],rt[i+1]+a[i]);  
		}  
  
		rtm[n]=rt[n];  
		for(i=n-1;i>=1;i--)  
			rtm[i]=max(rtm[i+1],rt[i]);  
  
		int ma=inf;  
		for(i=2;i<=n;i++){  
			ma=max(ma,lt[i-1]+rtm[i]);  
		}  
		printf("%d\n",ma);  
  
	}  
	return 0;  
}  