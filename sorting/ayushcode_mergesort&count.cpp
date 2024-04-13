#include <bits/stdc++.h>

using namespace std;

long long int mergeAndCount(vector<long long int>& arr, long long int left, long long int mid, long long int right, long long int a, long long int b) {
    long long int i = left;
    long long int j = mid + 1;
    long long int count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j] * a + b) {
            count += 1;
            i++;
        } else {
            j++;
        }
    }
    return count;
}

long long int mergeSortAndCount(vector<long long int>& arr, long long int left, long long int right, long long int a, long long int b) {
    long long int count = 0;

    if (left < right) {
        long long int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, left, mid, a, b);
        count += mergeSortAndCount(arr, mid + 1, right, a, b);
        count += mergeAndCount(arr, left, mid, right, a, b);
        //inplace_merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + right + 1);
    }
    return count;
}

long long int countModifiedInversions(vector<long long int>& arr, long long int n, long long int a, long long int b) {
    return mergeSortAndCount(arr, 0, n - 1, a, b);
}

int main() {
    long long int testcases;
    cin >> testcases;

    while (testcases--) {
        long long int n, a, b;
        cin >> n >> a >> b;

        vector<long long int> arr(n);
        for (long long int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        long long int result = countModifiedInversions(arr, n, a, b);
        cout << result << endl;
    }

    return 0;
}