#include<stdio.h>
#include<math.h>

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a>b)
		{
			int temp = a;
			a = b;
			b=temp;
		}

		int n = ceil(a/((1.0+sqrt(5.0))/2.0));
		int ta = (int)(((1.0+sqrt(5.0))/2.0)*n);
		int tb = (int)(((3.0+sqrt(5.0))/2.0)*n);
		if(ta==a&&tb==b)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}