#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string A;
		cin >> A;

		int n = A.size();

		int c = 0;
		int a = 0;
		for(int i=0; i<n; i++)
		{
			if(A[i] == '(')
				c++;
			else
			{
				a += 2*(c != 0);
				c -= (c != 0);
			}
		}		

		cout << a << endl;	
	}

	return (0-0);	
}