#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;



int main(){
        long long int testcases;
        cin >> testcases;
        for (long long int cas = 0; cas < testcases; cas++) 
        {
            long long int n; cin >> n;            
            long long int array[n];
            for (long long int i = 0 ; i < n; i++) cin >> array[i];

            vector <long long int> sums(n, 0);    
            unordered_map  <long long int,long long int> dict;    
            long long int ans = 0;

            for (long long int i = 0 ; i < n ; i++){
                if (i != 0) sums[i] = sums[i - 1];    
                sums[i] += dict[array[i]];
                dict[array[i]] += (i + 1);
                ans += sums[i];
            }
            cout << ans << endl;
        }
}