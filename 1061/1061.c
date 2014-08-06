#include<stdio.h>

// (m-n)*step % L == y-x

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

//扩展欧几里德算法: 已知a, b 求解一组p，q 使得 p*a + q*b == gcd(a, b) 
void exgcd(long long a, long long b, long long *p, long long *q)
{
    if(b == 0)
    {
        *p = 1;
        *q = 0;
    }
	else
	{
		exgcd(b, a%b, p, q);
		long long t = *p;
		*p = *q;
		*q = t - a/b*(*q);
	}
}


int main()
{
	long long x, y, m, n, L, a, b, k1, k2, t, r;
	int step = 0;
	while(scanf("%lld %lld %lld %lld %lld",&x, &y, &m, &n, &L)!=EOF)
	{
		a = m - n;
		b = y - x;
		if(a<0)
		{
			a = -a;
			b = -b;
		}
		n = y - x;
		r = gcd(a, L);
		if(b%r)
		{
			printf("Impossible\n");
			continue;
		}
		exgcd(a,L,&k1,&k2);
		
		k1 = k1*b/r;
		k2 = k2*b/r;
		L = L/r;
		if(k1 == 0)
			k1 = L;
		else if(k1 > 0)
			k1 = k1%L;
		else
			k1 = k1%L + L;
		printf("%lld\n",k1);
	}
	return 0;
}