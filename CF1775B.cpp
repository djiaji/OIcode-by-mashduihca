#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 114514;
int n;
void mian() {
	cin >> n;
	vector<vector<int>> v;
	multiset<int> s;
	set<int> ss;
	for(int i=1;i<=n;++i) {
		int k;
		cin >> k;
		vector<int> tmp;
		for(int j=1;j<=k;++j) {
			int x;
			cin >> x;
			s.insert(x);
			ss.insert(x);
			tmp.emplace_back(x);
		}
		v.push_back(tmp);
	}
	size_t sz = ss.size();
	for(const vector<int>& x : v) {
		for(int p : x) {
			s.erase(s.find(p));
			if(!s.count(p))
				ss.erase(p);
		}
		if(ss.size() == sz) {
			puts("Yes");
			return ;
		}
		for(int p : x)
			s.insert(p) , ss.insert(p);
	}
	puts("No");
}
int main() {
	int t;
	cin >> t;
	while(t--)
		mian();
	return 0;
}
