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
		int n, k;
		cin >> n >> k;

		priority_queue <lli> Q;
		while(n--)
		{
			lli x;
			cin >> x;

			Q.push(x);
		}

		lli ans = 0;
		while(k-- and not Q.empty())
		{
			auto p = Q.top();
			Q.pop();

			if(p)
			{
				ans += p/2 + p%2;
				p /= 2;

				Q.push(p);
			}
			else
				break;
		}

		cout << ans << endl;
	}

	return (0-0);	
}