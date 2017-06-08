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

struct node
{
	int val;
	node * lc;
	node * rc;
	node * par;
};

void init(node *);
void insert(node *, int);
int depth(node *);

void path(node *, vector <int> &, int);
int lca(node *, int a, int b);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		node root;
		init(&root);

		cin >> root.val;

		for(int i=1; i<n; i++)
		{
			int x;
			cin >> x;

			insert(&root, x);
		}

		cout << depth(&root) << endl;

		int q;
		cin >> q;

		while(q--)
		{
			int x, y;
			cin >> x >> y;

			cout << lca(&root, x, y) << endl;
		}
	}
	return (0-0);	
}

void init(node * root)
{
	root->lc = root->rc = root->par = NULL;
	root->val = 0;
}

void insert(node * root, int x)
{
	if(x <= root->val)
	{
		if(root->lc)
		{
			insert(root->lc, x);
		}
		else
		{
			node * cur = (node *) malloc(sizeof(node));

			init(cur);

			cur->val = x;
			cur->par = root;

			root->lc = cur;

			return;
		}
	}
	else
	{
		if(root->rc)
		{
			insert(root->rc, x);
		}
		else
		{
			node * cur = (node *) malloc(sizeof(node));

			init(cur);

			cur->val = x;
			cur->par = root;

			root->rc = cur;

			return;
		}
	}
}

int depth(node * root)
{
	if(root == NULL)
		return 1e5;

	if(not root->lc and not root->rc)
		return 1;

	int ld = depth(root->lc) + 1;
	int rd = depth(root->rc) + 1;

	return min(ld, rd);
}

int lca(node * root, int a, int b)
{
	vector <int> A, B;

	path(root, A, a);
	path(root, B, b);

	int k = 0;

	while(k < A.size() and k < B.size() and A[k] == B[k])
		k++;

	return A[k-1];
}

void path(node * root, vector <int> & A, int x)
{
	node * cur = root;

	while(cur)
	{
		A.pb(cur->val);

		if(x == cur->val)
			return ;

		if(x < cur->val)
			cur = cur->lc;
		else
			cur = cur->rc;
	}
}