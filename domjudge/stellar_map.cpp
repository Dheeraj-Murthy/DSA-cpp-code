#include<iostream>
#include<map>
using namespace std;


int main()
{
    int testcases = 1;
    // long long int testcases; cin >> testcases;
    while (testcases--)
    {
        long long int ans = 0;
        map<long long int, long long int> x_axis, y_axis, d1, d2;
        long long int number_points; cin >> number_points;
        while(number_points--)
        {
            long long int x, y; cin >> x >> y;
            ans += x_axis[x]++ + y_axis[y]++ + d1[x-y]++ + d2[x+y]++;
        }
        cout << ans*2 << endl;

    }
}