#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7;
vector<vector<int>> mat_mul_100(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> res(100, vector<int>(100, 0));
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
            {
                res[i][j] += (mat1[i][k] * mat2[k][j]) % mod;
                res[i][j] %= mod;
            }

    return res;
}
vector<vector<int>> mat_power(vector<vector<int>> &mat, int n)
{
    vector<vector<int>> res(100, vector<int>(100, 0));
    for (int i = 0; i < 100; i++)
        res[i][i] = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            res = mat_mul_100(res, mat);
        }
        mat = mat_mul_100(mat, mat);
        n = n >> 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    if (n < 100)
    {
        cout << n << endl;
        return;
    }
    vector<vector<int>> mat(100, vector<int>(100, 0));
    mat[0][99] = mat[0][98] = 1;
    for (int i = 1; i < 100; i++)
        mat[i][i - 1] = 1;

    vector<vector<int>> fin = mat_power(mat, n - 99);
    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        ans += ((99 - i) * fin[0][i]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
signed main()
{
    // freopen("fibo_test8.in", "r", stdin);
    // freopen("fibo_soltest8.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Sieve();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}