#include <map>
#include <set>
#include <cctype>
#include <cstdio>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 114514;
int n,m,q,ans,a[N];
multiset<int> s[N];
namespace IO {
	inline unsigned int read() {
		unsigned int x = 0;
		char ch = getchar();
		while(!isdigit(ch)) ch = getchar();
		while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48) , ch = getchar();
		return x;
	}
}
namespace BIT {
	int tree[N];
	inline int lowbit(int x) {
		return x & -x;
	}
	inline void update(int x) {
		for(; x <= n; x += lowbit(x))
			++tree[x];
	}
	inline int query(int x) {
		int ans = 0;
		for(; x; x -= lowbit(x))
			ans += tree[x];
		return ans;
	}
	inline int query(int l, int r) {
		return query(r) - query(l-1);
	}
}
namespace ST {
	int tree[N<<2];
	void build(int p = 1, int l = 1, int r = n) {
		if(l == r) {
			if(s[l].empty()) tree[p] = INT_MAX;
			else tree[p] = *s[l].begin();
			return ;
		}
		int mid = (l + r) >> 1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		tree[p] = min(tree[p<<1],tree[p<<1|1]);
	}
	void update(int L, int R, int p = 1, int l = 1, int r = n) {
		if(l == r) {
			for(auto it = s[l].begin(); it != s[l].end();) {
				if(*it <= R) it = s[l].erase(it);
				else break;
				++ans;
			}
			if(s[l].empty()) tree[p] = INT_MAX;
			else tree[p] = *s[l].begin();
			return ;
		}
		int mid = (l + r) >> 1;
		if(L <= mid && tree[p<<1] <= R) update(L,R,p<<1,l,mid);
		if(R > mid && tree[p<<1|1] <= R) update(L,R,p<<1|1,mid+1,r); 
		tree[p] = min(tree[p<<1],tree[p<<1|1]);
	}
}
int main() {
	n = IO::read() , m = IO::read();
	for(int i=1;i<=n;++i)
		a[i] = IO::read();
	for(int i=1;i<=m;++i) {
		int l = IO::read() , r = IO::read();
		s[l].insert(r);
	}
	ST::build();
	q = IO::read();
	for(int i=1;i<=q;++i) {
		int x;
		cin >> x;
		x = (x + ans - 1) % n + 1;
		--a[x];
		if(!a[x]) {
			BIT::update(x);
			int l = 1, r = x - 1, L = x, R = x;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(BIT::query(mid,x) == x - mid + 1) r = mid - 1 , L = mid;
				else l = mid + 1;
			}
			l = x + 1, r = n;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(BIT::query(x,mid) == mid - x + 1) l = mid + 1 , R = mid;
				else r = mid - 1;
			}
			ST::update(L,R);
		}
		printf("%d\n",ans);
	}
	return 0;
}
