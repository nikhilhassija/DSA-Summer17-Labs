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

void postorder(node *);

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

		postorder(&root);

		cout << endl;
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


void postorder(node * root)
{
	if(root -> lc)
		postorder(root -> lc);

	if(root -> rc)
		postorder(root -> rc);

	cout << root -> val << " ";
}