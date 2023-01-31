#include <iostream>
#include <cmath>
using namespace std;
void mian() {
	int n,k;
	cin >> n >> k;
	int x[] = {1,-n};
	for(int i=1;i<=n;++i)
		cout << abs(x[(i&1)]++) << " \n"[i==n];
}
int main() {
	int t;
	cin >> t;
	while(t--) mian();
	return 0;
}
