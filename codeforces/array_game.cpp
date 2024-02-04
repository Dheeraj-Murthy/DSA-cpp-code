#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int number_of_queries; cin >> number_of_queries;
    for (long long int i = 0; i < number_of_queries; i++)
    {
        long long int arrcount; cin >> arrcount;
        vector< vector<int> > arraylis;
        for (long long int j = 0; j < arrcount; j++)
        {
            long long int arrsize; cin >> arrsize;
            vector<int> arr(arrsize);
            for (long long int k = 0; k < arrsize; k++)
                cin >> arr[k];
            sort(arr.begin(), arr.end());
            arraylis.push_back(arr);
        }
        long long int smallest_i0 = 0, smallest_i1 = 0;
        for (long long int j = 0; j < arrcount; j++)
        {
            if (arraylis[j][0] < arraylis[smallest_i0][0]) smallest_i0 = j;
            if (arraylis[j][1] < arraylis[smallest_i1][1]) smallest_i1 = j;
        }
        long long int sum = 0;
        for (long long int j = 0; j < arrcount; j++)
        {
            if (j == smallest_i1){
                sum += arraylis[smallest_i0][0];
                continue;
            }
            sum += arraylis[j][1];
        }
        cout << sum << endl;
    }
}