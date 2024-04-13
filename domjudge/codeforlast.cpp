#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll countInversions(vector<int>& array, int left, int mid, int right, int a, int b) {
    int i = left, j = mid + 1;
    ll count = 0;
    vector<int> temp;

    while ((i <= mid) && (j <= right)) {
        if (array[i] < array[j] * a + b) {
            count += right - j + 1;
            i++;
        } else {
            j++;
        }
    }

    i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(array[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(array[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        array[left + k] = temp[k];
    }

    return count;
}

ll countInversionsPairs(vector<int>& array, int left, int right, int a, int b) {
    ll count = 0;

    if (right > left) {
        int mid = (left + right) / 2;
        count += countInversionsPairs(array, left, mid, a, b);
        count += countInversionsPairs(array, mid + 1, right, a, b);
        count += countInversions(array, left, mid, right, a, b);
    }

    return count;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> array(n);

        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        ll count = countInversionsPairs(array, 0, n - 1, a, b);
        cout << count << endl;
    }

    return 0;
}