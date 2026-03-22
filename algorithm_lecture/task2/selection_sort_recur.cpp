#include <iostream>
#include <vector>

using namespace std;

void print_arr(const vector<int>& A) {
    for (int i : A) cout << i << " ";
    cout << "\n";
}

void recursiveSelectionSort(vector<int>& A, int n, int s) {
    if (s >= n - 1) return;

    int idx = s;
    for (int j = s + 1; j < n; ++j) {
        if (A[j] < A[idx]) {
            idx = j;
        }
    }
    swap(A[s], A[idx]);

    cout << "Step " << s + 1 << ": ";
    print_arr(A);

    recursiveSelectionSort(A, n, s + 1);
}

int main() {
    vector<int> A = {30, 20, 40, 10, 5, 10, 30, 15};
    cout << "초기 상태: "; print_arr(A);
    
    recursiveSelectionSort(A, A.size(), 0);
    
    cout << "최종 결과: "; print_arr(A);
    cout << "알고리즘 2분반 2022110482 정이현" << endl;

    return 0;
}