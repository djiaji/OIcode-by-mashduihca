// #pragma GCC optimize(3)
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 1919810;
int n,m,q,mx,fa[N],rk[N];
bool ans[N];
struct edge {
	int from,to,val;
}e[N];
struct query {
	int from,to,val,id;
	bool operator<(const query& q) {
		return val < q.val;
	}
};
vector<pair<int,int>> g[N];
vector<vector<query>> v[N];
stack<pair<int&,int>> s;
inline int find(int x) {
	while(x != fa[x]) x = fa[x];
	return x;
}
inline bool merge(int x,int y) {
	int fx = find(x) , fy = find(y);
	if(fx != fy) {
		if(rk[fx] < rk[fy]) swap(fx,fy);
		s.emplace(fa[fy],fa[fy]);
		s.emplace(rk[fx],rk[fx]);
		fa[fy] = fx;
		if(rk[fx] == rk[fy]) ++rk[fx];
		return true;
	}
	return false;
}
inline void rollback() {
	for(int i=1;i<=2;++i)
		s.top().first = s.top().second , s.pop();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(ans,1,sizeof(ans));
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		fa[i] = i , rk[i] = 1;
	for(int i=1;i<=m;++i) {
		int x,y,z;
		cin >> x >> y >> z;
		g[z].emplace_back(x,y);
		e[i] = {x,y,z};
		mx = max(mx,z);
	}
	cin >> q;
	for(int i=1;i<=q;++i) {
		int k;
		cin >> k;
		vector<query> res;
		for(int j=1;j<=k;++j) {
			int x;
			cin >> x;
			res.emplace_back(e[x].from,e[x].to,e[x].val,i);
		}
		sort(res.begin(),res.end());
		query last = {0,0,0,0};
		vector<query> tmp;
		for(const query& p : res) {
			if(p.val == last.val) tmp.push_back(p);
			else {
				if(!tmp.empty())
					v[last.val].push_back(tmp);
				tmp.clear();
				tmp.push_back(p);
			}
			last = p;
		}
		v[tmp.back().val].push_back(tmp);
	}
	for(int i=1;i<=mx;++i) {
		for(const vector<query>& x : v[i]) {
			int cnt = 0;
			bool fg = 1;
			for(const query& p : x) {
				fg = merge(p.from,p.to);
				cnt += fg;
				if(!fg) break;
			}
			if(!fg) ans[x.back().id] = 0;
			for(int i=1;i<=cnt;++i)
				rollback();
		}
		for(const pair<int,int>& p : g[i])
			merge(p.first,p.second);
	}
	for(int i=1;i<=q;++i)
		if(ans[i]) puts("YES");
		else puts("NO");
	return 0;
}
