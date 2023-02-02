#include <functional>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 1919810;
int n,a[N],p[N],q[N];
vector<int> r[N];
void mian() {
	cin >> n;
	multiset<int,greater<int>> s;
	for(int i=1;i<=n;++i)
		s.insert(i) , s.insert(i) , r[i].clear() , p[i] = q[i] = 0;
	for(int i=1;i<=n;++i) {//puts("QwQ");
		cin >> a[i];
	} 
	for(int i=1;i<=n;++i) {
		if(!s.count(a[i])) {
			puts("No");
			return ;
		}
		s.erase(s.find(a[i]));
		r[a[i]].push_back(i);
	}
//	for(auto x : s) cout << x << ' ';
	if(r[n].empty()||r[1].size() == 2) {
		puts("No");
		return ;
	}
	for(int i=1;i<=n;++i) {
		if(r[i].size() == 1) {
			p[r[i].back()] = q[r[i].back()] = i;
		}
	}
	for(int i=1;i<=n;++i) {
		if(r[i].size() == 2) {
			p[r[i].front()] = q[r[i].back()] = i;
		}
	}
	s.clear(); 
	for(int i=1;i<=n;++i) s.insert(i) , s.insert(i);
//	for(int i=1;i<=n;++i) cout << p[i] << ' ' << q[i] << ' ';
//	puts("---------------------------------------------------");
	for(int i=1;i<=n;++i) {
		if(p[i]) s.erase(s.find(p[i]));
		if(q[i]) s.erase(s.find(q[i]));
	}
//	for(auto x : s) cout << x << ' ';puts("<_");
	for(int i=n;i>=1;--i) {
		if(r[i].size() == 2) {
			int x = r[i].front() , y = r[i].back();
			auto l = [&](int x) -> bool { //cout << s.size() << "||";
				if(!p[x] || !q[x]) {
					if(!p[x]) {
						auto it = s.lower_bound(q[x]); 
						if(it == s.end()) return false;
						p[x] = *it;
						s.erase(it);
					}
					else {
						auto it = s.lower_bound(p[x]);  // cout << p[x] << ' ' << s.count()  << ' ';
						if(it == s.end()) return false;
						q[x] = *it;
						s.erase(it);
					}
				} 
				return true;
			};
			if(!l(x) || !l(y)) {
				puts("No");
				return ;
			}
		}
	}
//	for(int i=1;i<=n;++i) {
//		
//		if(!p[i]) {
//			auto it = s.lower_bound(q[i]);
//			if(it == s.end()) {
//				puts("No");
//				return ;
//			}
//			p[i] = *it;
//		}
//		if(!q[i]) {
//			auto it = s.lower_bound(p[i]);
//			if(it == s.end()) {
//				puts("No");
//				return ;
//			}
//			q[i] = *it;
//		}
//	}//cout << n << "<----\n";
	puts("Yes");
	for(int i=1;i<=n;++i) cout << p[i] << ' ';
	cout << '\n';
	for(int i=1;i<=n;++i) cout << q[i] << ' ';
	cout << '\n';
}
int main() {
	int t;
	cin >> t;
	while(t--) mian();
	return 0;
}
