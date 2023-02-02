#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 1919810;
struct edgem {
	int to,val;
	bool operator<(const edgem& e) const {
		return val > e.val;
	}
};
struct node {
	int l,r;
}tree[N];
vector<edgem> v[N];
bool vis[N];
int n,q,s,r1,r2,cnt;
long long dis[N];
namespace IN {
	void build(int p,int l,int r) {
		if(l == r) {
			v[l].emplace_back(p,0);
			v[p].emplace_back(l,0);
			return ;
		}
		int mid = (l + r) >> 1;
		tree[p].l = ++cnt;
		v[p].emplace_back(cnt,0);
		build(cnt,l,mid);
		tree[p].r = ++cnt;
		v[p].emplace_back(cnt,0);
		build(cnt,mid+1,r);
	}
	void update(int x,int w,int p,int L,int R,int l,int r) {
		if(L <= l && r <= R) {
			v[x].emplace_back(p,w);
			return ;
		}
		int mid = (l + r) >> 1;
		if(L <= mid) update(x,w,tree[p].l,L,R,l,mid);
		if(R > mid) update(x,w,tree[p].r,L,R,mid+1,r);
	}
}
namespace OUT {
	void build(int p,int l,int r) {
		if(l == r) {
			v[p].emplace_back(l,0);
			v[l].emplace_back(p,0);
			return ;
		}
		int mid = (l + r) >> 1;
		tree[p].l = ++cnt;
		v[cnt].emplace_back(p,0);
		build(cnt,l,mid);
		tree[p].r = ++cnt;
		v[cnt].emplace_back(p,0);
		build(cnt,mid+1,r);
	}
	void update(int x,int w,int p,int L,int R,int l,int r) {
		if(L <= l && r <= R) {
			v[p].emplace_back(x,w);
			return ;
		}
		int mid = (l + r) >> 1;
		if(L <= mid) update(x,w,tree[p].l,L,R,l,mid);
		if(R > mid) update(x,w,tree[p].r,L,R,mid+1,r);
	}
}
int main() {
	memset(dis,0x3f,sizeof(dis));
	cin >> n >> q >> s;
	cnt = n;
	IN::build(r1=++cnt,1,n);
	OUT::build(r2=++cnt,1,n);
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int x,y,z;
			cin >> x >> y >> z;
			v[x].emplace_back(y,z);
		}
		else if(op == 2) {
			int x,l,r,w;
			cin >> x >> l >> r >> w;
			IN::update(x,w,r1,l,r,1,n);
		}
		else {
			int x,l,r,w;
			cin >> x >> l >> r >> w;
			OUT::update(x,w,r2,l,r,1,n);
		}
	}
	priority_queue<edgem> q;
	q.emplace(s,0);
	dis[s] = 0;
	while(!q.empty()) {
		int p = q.top().to;
		q.pop();
		if(vis[p]) continue;
		for(const edgem& x : v[p]) {
			if(dis[x.to] > dis[p] + x.val) {
				dis[x.to] = dis[p] + x.val;
				q.emplace(x.to,dis[x.to]);
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(dis[i] < 1e9 * 1e5 + 1) cout << dis[i] << ' ';
		else cout << -1 << ' ';
	return 0;
}
