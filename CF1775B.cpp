#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n;
void mian() {
	multiset<int> s;
	cin >> n;
	vector<vector<int>> v;
	for(int i=1;i<=n;++i) {
		int k;
		cin >> k;
		vector<int> tmp;
		for(int j=1;j<=k;++j) {
			int x;
			cin >> x;
			tmp.push_back(x);
			s.insert(x);
		}
		v.push_back(tmp);
	}
	int sz = s.size();
	for(int i=0;i<v.size();++i) {
		
	}
}
int main() {
	int t;
	cin >> t;
	while(t--)
		mian();
	return 0;
}
