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
	int n, m;
	cin >> n >> m;

	stack <pii> S;

	while(m--)
	{
		string T;
		cin >> T;

		if(T == "getmin")
		{
			if(S.empty())
				cout << -1 << endl;
			else
				cout << S.top().second << endl;
		}

		if(T == "push")
		{
			int x;
			cin >> x;

			pii p;

			if(S.empty())
				p = {0, 1e9};
			else
				p = S.top();

			S.push({x, min(x, p.second)});
		
			cout << x << endl;
		}

		if(T == "pop")
		{
			if(S.empty())
				cout << -1 << endl;
			else
			{
				cout << S.top().first << endl;
				S.pop();
			}
		}

		if(T == "isempty")
		{
			cout << S.empty() << endl;
		}

		if(T == "top")
		{
			if(S.empty())
				cout << -1 << endl;
			else
				cout << S.top().first << endl;
		}
	}	

	return (0-0);	
}
