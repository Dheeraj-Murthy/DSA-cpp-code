#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class sgtree
{
public:
    vector<int> nums, left, right;
    vector<char> lc, rc;
    int n;
    sgtree(string &s)
    {
        n = s.size();
        nums = vector<int>(4 * n + 5, 0);
        left = vector<int>(4 * n + 5, -1);
        right = vector<int>(4 * n + 5, -1);
        lc = vector<char>(4 * n + 5, '*');
        rc = vector<char>(4 * n + 5, '*');
        build(0, s, 0, n - 1);
    }
    void build(int idx, string &s, int ss, int se)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            lc[idx] = rc[idx] = s[ss];
            left[idx] = ss;
            right[idx] = ss;
            nums[idx] = 1;
        }
        int mid = (ss + se) >> 1;
        build(2 * idx + 1, s, ss, mid);
        build(2 * idx + 2, s, mid + 1, se);
        merge(idx, ss, mid, se);
    }
    void merge(int idx, int ss, int mid, int se)
    {
        int i = 2 * idx + 1;
        int j = 2 * idx + 2;
        int mx = 0;
        lc[idx] = lc[i];
        rc[idx] = rc[j];
        if (rc[i] == lc[j])
        {
            if (left[i] == mid)
                left[idx] = left[j];
        }
        if (lc[j] == rc[i])
        {
            if (right[j] == mid + 1)
                right[idx] = right[i];
        }
        if (rc[i] == lc[j])
            mx = left[j] - right[i] + 1;

        mx = max(mx, left[idx] - ss + 1);
        mx = max(mx, se - right[idx] + 1);
        nums[idx] = max(mx, max(nums[i], nums[j]));
    }
    int update(int idx, int ss, int se, int j, char ch)
    {
        if (ss > se)
            return 0;
        if (ss == se)
        {
            lc[idx] = rc[idx] = ch;
            left[idx] = ss;
            right[idx] = ss;
            nums[idx] = 1;
            return 1;
        }
        int mid = (ss + se) >> 1;
        if (j >= ss && j <= mid)
            update(2 * idx + 1, ss, mid, j, ch);
        else
            update(2 * idx + 2, mid + 1, se, j, ch);
        merge(idx, ss, mid, se);
        return nums[idx];
    }
};
class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int> &queryIndices)
    {
        sgtree node(s);
        vector<int> re(queryCharacters.size(), 0);
        for (int i = 0; i < queryCharacters.size(); i++)
            re[i] = node.update(0, 0, s.size() - 1, queryIndices[i],
                                queryCharacters[i]);
        return re;
    }
};
