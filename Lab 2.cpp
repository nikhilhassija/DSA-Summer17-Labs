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

const int inf = 1e9 + 5;

void diff(int *, int *, int, int);

int main()
{
	fastio();

	int x, y;
	cin >> x >> y;

	int A[x+1], B[y+1];
	for(int i=0; i<x; i++)
		cin >> A[i];
	A[x] = inf;

	for(int i=0; i<y; i++)
		cin >> B[i];
	B[y] = inf;

	diff(A, B, x, y);
	diff(B, A, y, x);

	return (0-0);	
}

void diff(int * A, int * B, int x, int y)
{
	int j = 0;
	for(int i=0; i<x; i++)
	{
		while(A[i] > B[j])
			j++;

		if(A[i] < B[j])
			cout << A[i] << " ";
	}

	cout << endl;
}