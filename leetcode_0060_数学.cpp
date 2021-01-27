class Solution {
public:
	string getPermutation(int n, int k) {
		string rt = "";
		list<int> l;
		for (int i = 1; i <= 9; i++) {
			l.push_back(i);
		}
		int fact[9] = { 0 };
		setFact(fact);
		// reminder and quotient
		int r = k - 1;
		int q = 0;
		for (int i = 0; i < n - 1; i++) {
			q = r / fact[n - i - 2];
			r = r % fact[n - i - 2];
			rt.push_back('0' + getListElement(l,q));
			eraseListElement(l,q);
			if (r == 0) {
				break;
			}
		}
		while (!l.empty() && l.front() <= n) {
			rt.push_back('0' + l.front());
			l.pop_front();
		}
		return rt;
	}
	void setFact(int* fact) {
		for (int i = 0; i<9; i++) {
			fact[i] = getFact(i + 1);
		}
	}
	int getFact(int n) {
		int rt = 1;
		for (int i = 2; i<n + 1; i++) {
			rt = rt*i;
		}
		return rt;
	}
	int getListElement(list<int>& l, int index) {
		list<int>::iterator iter = l.begin();
		for (int i = 0; i < index; i++) {
			iter++;
		}
		return (*iter);
	}
	void eraseListElement(list<int>& l, int index) {
		list<int>::iterator iter = l.begin();
		for (int i = 0; i < index; i++) {
			iter++;
		}
		l.erase(iter);
	}
};