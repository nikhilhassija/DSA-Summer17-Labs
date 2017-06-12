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

const int MAX_N = 1e6 + 5;

int A[MAX_N];

void postorder(int, int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i=0; i<n; i++)
			cin >> A[i];

		postorder(0, n-1);

		cout << endl;
	}


	return (0-0);	
}

void postorder(int l, int r)
{
	if(l > r)
		return;

	if(l == r)
	{
		cout << A[l] << " ";
		return ;
	}

	for(int i=l; i<=r; i++)
	{
		if(A[l] < A[i])
		{
			postorder(l+1, i-1);
			postorder(i, r);
			cout << A[l] << " ";

			return ;
		}
	}

	postorder(l+1, r);
	cout << A[l] << " ";
}