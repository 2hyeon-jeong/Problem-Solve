#include <iostream>
#include <vector>

using namespace std;

void print_arr(const vector<int>& A) {
    for (int i : A) cout << i << " ";
    cout << "\n";
}

void iterativeSelectionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[idx]) {
                idx = j;
            }
        }
        swap(A[i], A[idx]);
        
        cout << "Step " << i + 1 << ": ";
        print_arr(A);
    }
}

int main() {
    vector<int> A = {30, 20, 40, 10, 5, 10, 30, 15};
    cout << "초기 상태: "; print_arr(A);
    
    iterativeSelectionSort(A);
    
    cout << "최종 결과: "; print_arr(A);
    cout << "알고리즘 2분반 2022110482 정이현" << endl;
    return 0;
}