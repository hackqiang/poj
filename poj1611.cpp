#include<iostream>
using namespace std;

#define MAX_N 30001
#define MAX_M 501


int s[MAX_N];

int getf(int i)
{
	if (s[i] == i)
		return i;
	else {
		return getf(s[i]);
	}
}

int merge(int i, int j)
{
	int a = getf(i);
	int b = getf(j);
	if (a != b) {
		if (a<b)
			s[b] = a;
		else
			s[a] = b;
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	int n, m, g, i, j, k, f;
	while (1) {
		cin >> n >> m;
		//cout << n << m<< endl;
		if (n == 0 && m == 0)
        {
            break;
        }
        else        
		{
			for (i = 0; i < n; i++)
				s[i] = i;


			for (i = 0; i < m; i++)
			{
				cin >> g;
				int gg[MAX_N];
				for (j = 0; j < g; j++)
				{
					cin >> gg[j];
				}

				for (j = 0; j < g; j++)
					for (k = j + 1; k < g; k++)
					{
						merge(gg[j], gg[k]);
					}
			}
			int Max = 0;
			for (i = 0; i < n; i++)
			{
                //cout<<s[i]<<" ";
				if (getf(s[i]) == s[0]) {
					Max++;
				}
			}
			cout << Max << endl;
		}
	}
	return 0;
}