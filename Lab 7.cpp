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
	int n, m, k;
	cin >> n >> m >> k;

	vector < vector <int> > G(n+1);
	vector <int> D(n+1, 0);
	vector <int> T(n+1, 1);

	while(m--)
	{
		int u, v;
		cin >> u >> v;

		D[u]++;
		D[v]++;

		G[u].pb(v);
		G[v].pb(u);
	}

	queue <int> Q;

	for(int i=1; i<=n; i++)
		if(D[i] < k)
		{
			Q.push(i);
			T[i] = 0;
		}

	while(not Q.empty())
	{
		auto u = Q.front();
		Q.pop();

		for(auto v: G[u])
		{
			D[v]--;

			if(T[v] and D[v] < k)
			{
				T[v] = 0;
				Q.push(v);
			}
		}
	}

	for(int i=1; i<=n; i++)
		if(T[i])
			cout << i << " ";
	cout << endl;

	for(int i=1; i<=n; i++)
	{
		if(not T[i])
			continue;

		for(auto v: G[i])
			if(T[v])
				cout << v << " ";

		cout << endl;
	}

	return (0-0);
}