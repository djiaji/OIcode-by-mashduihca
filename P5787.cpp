#include <algorithm>
#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
#include <stack>
using namespace std;
const int N = 114514;
bool ans[N];
int n,m,k,fa[N<<1],rk[N<<1];
stack<pair<int&,int>> s;
vector<pair<int,int>> v[N<<2];
int find(int x) {
	while(x != fa[x])
		x = fa[x];
	return x;
}
bool merge(int x, int y) {
	int fx = find(x) , fy = find(y);
	if(fx == fy) return false;
	if(rk[fx] < rk[fy]) swap(fx,fy);
	s.emplace(fa[fy],fa[fy]);
	s.emplace(rk[fx],rk[fx]);
	fa[fy] = fx;
	if(rk[fx] == rk[fy]) ++rk[fx];
	return true;
}
void rollback() {
	for(int i=1;i<=2;++i)
		s.top().first = s.top().second , s.pop();
}
void insert(int x, int y, int L, int R, int l = 1, int r = n, int p = 1) {
	if(L <= l && r <= R) {
		v[p].emplace_back(x,y);
		return ;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) insert(x,y,L,R,l,mid,p<<1);
	if(R > mid) insert(x,y,L,R,mid+1,r,p<<1|1);
}
void solve(int l = 1, int r = n, int p = 1) {
	int cnt = 0;
	for(const pair<int,int>& x : v[p]) {
		if(find(x.first) == find(x.second)) {
			for(int i=l;i<=r;++i) ans[i] = 0;
			for(int i=1;i<=cnt;++i) rollback();
			return ;
		}
		cnt += merge(x.first,x.second+n);
		cnt += merge(x.second,x.first+n);
	}
	if(l == r) {
		for(int i=1;i<=cnt;++i) rollback();
		return ;
	}
	int mid = (l + r) >> 1;
	solve(l,mid,p<<1);
	solve(mid+1,r,p<<1|1);
	for(int i=1;i<=cnt;++i) rollback();
}
int main() {
	memset(ans,1,sizeof(ans));
	cin >> n >> m >> k;
	iota(fa+1,fa+n+n+1,1);
	fill(rk+1,rk+n+n+1,1);
	for(int i=1;i<=m;++i) {
		int x,y,l,r;
		cin >> x >> y >> l >> r;
		insert(x,y,l+1,r);
	}
	solve();
	for(int i=1;i<=k;++i)
		if(ans[i]) puts("Yes");
		else puts("No");
	return 0;
}
