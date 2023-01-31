#include <iostream>
using namespace std;
const int N = 114;
int a[N];
void mian() {
	int n,k;
	cin >> k >> n;
	a[0] = 1;
	int delta = 0;
	a[k+1] = n + 1;
	for(int i=1;i<=k;++i)
		a[i] = a[i-1] + delta++;
	int m = k;
	while(a[k] >= a[k+1]) {
		a[k] = a[k+1] - 1;
		--k;
	}
	for(int i=1;i<=m;++i)
		cout << a[i] << " \n"[i==m];
}
int main() {
	int t;
	cin >> t;
	while(t--)
		mian();
	return 0;
}
