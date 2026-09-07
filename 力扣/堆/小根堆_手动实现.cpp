////#include<iostream>
////#include<algorithm>
////#include<vector>
////using namespace std;
////int main() {
////	int n, ans = 0;
////	cin >> n;
////	for (int i = 0; i < n; i++) {
////		int num, cnt_d = 0, cnt_s = 0;
////		cin >> num;
////		while (num > 0) {
////			if (num & 1) {
////				cnt_d++;
////			}
////			else {
////				cnt_s++;
////			}
////			num >>= 1;
////		}
////		if (cnt_d == cnt_s) {
////			ans++;
////		}
////	}
////	cout << ans << endl;
////	return 0;
////}
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main() {
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		int n, k;
//		cin >> n >> k;
//		string s;
//		cin >> s;
//		long long total = 2 * n, goal_r = 0, goal_b = 0;
//		vector<bool>lep(total, false);
//		for (long long i = 0; i < total; i++) {
//			long long next = (i + 1) % total;
//			if (s[i] == '1') {
//				if (s[next] == '1') {
//					lep[i] = true;
//				}
//			}
//		}
//
//		for (int i = 0; i < total; i++) {
//			if (lep[i]) {
//				if (i % 2) {
//					goal_r++;
//				}
//				else {
//					goal_b++;
//				}
//			}
//		}
//		cout << goal_r << ' ' << goal_b << endl << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdexcept>
using namespace std;

class MinHeap {
private:
	vector<int>heap;
	int pa(int i) {
		return i / 2;
	}
	int le(int i) {
		return i * 2;
	}
	int ri(int i) {
		return i * 2 + 1;
	}

	void heapify_up(int i) {
		while (i > 0 && heap[i] < heap[pa(i)]) {
			swap(heap[i], heap[pa(i)]);
			i = pa(i);
		}
	}

	void heapify_down(int i) {
		int minest = i;
		int left = le(i);
		int right = ri(i);
		if (left < heap.size() && heap[left] < heap[minest]) {
			minest = left;
		}
		if (right < heap.size() && heap[right] < heap[minest]) {
			minest = right;
		}
		if (minest != i) {
			swap(heap[i], heap[minest]);
			heapify_down(minest);
		}
	}

public:
	void push(int val) {
		heap.push_back(val);
		heapify_up(heap.size() - 1);
	}

	int top() {
		if (heap.empty()) {
			throw out_of_range("heap is empty");
		}
		return heap[0];
	}

	void pop() {
		if (heap.empty()) {
			throw out_of_range("heap is empty");
		}
		heap[0] = heap.back();
		heap.pop_back();
		heapify_down(0);
	}

	bool empty() {
		return heap.empty();
	}
};

int main() {
	MinHeap minheap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		minheap.push(x);
	}
	while (!minheap.empty()) {
		cout << minheap.top() << ' ';
		minheap.pop();
	}
	return 0;
}