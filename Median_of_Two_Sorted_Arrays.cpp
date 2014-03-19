class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int m1 = (m - 1) / 2;
		int m2 = m / 2;
		int n1 = (n - 1) / 2;
		int n2 = n / 2;

		if (m == 0) {
			return double(B[n1] + B[n2]) / 2;
		}
		if (n == 0) {
			return double(A[m1] + A[m2]) / 2;
		}
		if ((m == 1) && (n == 1)) {
			return double(A[0] + B[0]) / 2;
		}
		if (m == 1) {
			vector<int> temp;
			temp.push_back(A[0]);
			if (n % 2 == 0){
				temp.push_back(B[n1]);
				temp.push_back(B[n2]);
			}
			else {
				temp.push_back(B[n / 2 - 1]);
				temp.push_back(B[n / 2]);
				temp.push_back(B[n / 2 + 1]);
			}
			return median(temp);
		}
		if (n == 1) {
			vector<int> temp;
			temp.push_back(B[0]);
			if (m % 2 == 0){
				temp.push_back(A[m1]);
				temp.push_back(A[m2]);
			}
			else {
				temp.push_back(A[m / 2 - 1]);
				temp.push_back(A[m / 2]);
				temp.push_back(A[m / 2 + 1]);
			}
			return median(temp);
		}

		int key[] = { A[m1], A[m2], B[n1], B[n2] };
		sort(key, key + 4);
		if ((B[n1] == key[0]) && (B[n2] == key[3])) {
			return double((A[m1] + A[m2])) / 2;
		}
		else if ((A[m1] == key[0]) && (A[m2] == key[3])) {
			return double((B[n1] + B[n2])) / 2;
		}
		else {
			int reduced = min(n / 2, m / 2);
			if ((B[n1] == key[0]) && (A[m2] == key[3])) {
				return findMedianSortedArrays(A, m - reduced, &B[reduced], n - reduced);
			}
			else if ((A[m1] == key[0]) && (B[n2] == key[3])) {
				return findMedianSortedArrays(&A[reduced], m - reduced, B, n - reduced);
			}
		}

	}

private:
	double median(vector<int> &x){
		vector<int>::size_type sz = x.size();
		sort(x.begin(), x.end());
		return double(x[(sz - 1) / 2] + x[sz / 2]) / 2;
	}
};