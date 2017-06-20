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

const int MAX_N = 1e5;

vector < vector <int> > T;
int A[MAX_N];

void build(int, int, int);
int query(int, int, int, int, int, int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		T.clear();
		T.resize(4 * n);

		for(int i=0; i<n; i++)
			cin >> A[i];

		build(1, 0, n-1);

		int ans = 0;
		for(int i=0; i<n; i++)
			ans += query(1, 0, n-1, 0, i, A[i]);

		cout << ans << endl;
	}

	return (0-0);	
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		T[node].pb(A[l]);
		return;
	}

	int m = (l + r) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	build(lc, l, m);
	build(rc, m+1, r);

	T[node].insert(T[node].end(), 
		T[lc].begin(), T[lc].end());

	T[node].insert(T[node].end(), 
		T[rc].begin(), T[rc].end());

	sort(T[node].begin(), T[node].end());
}

int query(int node, int tl, int tr, int ql, int qr, int x)
{
	if(tr < ql or qr < tl)
		return 0;

	if(ql <= tl and tr <= qr)
	{
		return T[node].end() 
		- upper_bound(T[node].begin(), T[node].end(), x); 
	}

	int tm = (tl + tr) / 2;
	int lc = 2 * node;
	int rc = lc + 1;

	int la = query(lc, tl, tm, ql, qr, x);
	int ra = query(rc, tm+1, tr, ql, qr, x);

	return (la + ra);
}