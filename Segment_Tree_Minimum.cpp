#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 1e18
#define endl "\n"

/*---------------------------------------------------------------------------------------------------------------------------*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*--------------------------------------------------------------------------------------------------------------------------*/

class SegTree {
public:
	vector<int> tree;
	int n;
	SegTree (int N, vector<int>&arr) {
		n = N;
		tree.resize(4 * n + 1, 0);
		build(0, n - 1, 0, arr);
	}

	int query (int x, int y) {
		return query (x, y, 0, n - 1, 0);
	}

	void update (int ind, int val) {
		update (ind, val, 0, n - 1, 0);
	}

private:
	void build(int l, int r, int i, vector<int>&arr) {
		if (l == r) {
			tree[i] = arr[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, i * 2 + 1, arr);
		build(mid + 1, r, i * 2 + 2, arr);
		tree[i] = min(tree[i * 2 + 1], tree[i * 2 + 2]);
	}

	int query (int x, int y, int l, int r, int i) {
		if (r < x || l > y) return 1e18;
		if (l >= x && r <= y) return tree[i];

		int mid = (l + r) >> 1;
		return min(query (x, y, l, mid, i * 2 + 1), query (x, y, mid + 1, r, i * 2 + 2));

	}

	void update (int ind, int val, int l, int r, int i) {

		if (l == r) {
			tree[i] = val;
			return;
		}

		int mid = (l + r) >> 1;
		if (mid >= ind) update (ind, val, l, mid, i * 2 + 1);
		else update (ind, val, mid + 1, r, i * 2 + 2);

		tree[i] = min(tree[i * 2 + 1] , tree[i * 2 + 2]);
	}
};


void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	SegTree sgt(n, v);

	while (q--) {
		char type;
		cin >> type;
		if (type == 'q') {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << sgt.query(l, r) << endl;
		} else {
			int ind, val;
			cin >> ind >> val;
			sgt.update(ind - 1, val);
		}

	}


}


int32_t main()
{

	fastio();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}