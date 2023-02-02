#include <iostream>
#include <string>
using namespace std;
const int N = 1919810;
int n;
bool a[N];
void mian() {
	string s;
	cin >> n >> s;
	for(int i=1;i!=n;++i)
		a[i] = s[i-1] - '0';
	int col = -1 , val = 1;
	for(int i=1;i<n;++i) {
		if(a[i] == col) ++val;
		else col = a[i] , val = 1;
		cout << i - val + 1 << ' ';
	}
	cout << '\n';
}
int main() {
	int t;
	cin >> t;
	while(t--) mian();
	return 0;
}
