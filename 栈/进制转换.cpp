#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	bool is_negative = false;
	int n;
	cin >> n;
	if (n < 0) {
		is_negative = true;
		n = abs(n);
	}
	stack<int>stk;
	do{
		stk.push(n % 8);
		n /= 8;
	} while (n);
	if (is_negative)cout << "-";
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}