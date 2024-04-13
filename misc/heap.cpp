#include <bits/stdc++.h>
using namespace std;

void Bottom_Up_Heapify(vector<int> heap, int i)
{
    int p = (i - 1) / 2;
    while (p >= 0)
    {
        if (heap[i] < heap[p])
        {
            swap(heap[i], heap[p]);
            i = p;
            p = (i - 1) / 2;
        }
        else
            p = -1;
    }
}

void Insert(vector<int> heap, int x, int *n)
{
    heap[*n] = x;
    *n = *n + 1;
    Bottom_Up_Heapify(heap, *n - 1);
}

void TopDownHeapify(vector<int> heap, int n, int i)
{
    int c;
    while (2 * i + 2 < n)
    {
        if (heap[2 * i + 1] < heap[2 * i + 2])
            c = 2 * i + 1;
        else
            c = 2 * i + 2;

        if (heap[i] > heap[c])
        {
            swap(heap[i], heap[c]);
            i = c;
        }
        else
            i = n;
    }

    c = 2 * i + 1;
    if (c < n && heap[i] < heap[c])
        swap(heap[i], heap[c]);
}

int Delete(vector<int> heap, int *n) // delete the root
{
    int root = heap[0];
    swap(heap[0], heap[*n - 1]);
    *n = *n - 1;
    TopDownHeapify(heap, *n, 0);
    return root;
}

void DecreaseKey(vector<int> heap, int i, int X)
{
    heap[i] = X;
    Bottom_Up_Heapify(heap, i);
}

void IncreaseKey(vector<int> heap, int i, int X)
{
    heap[i] = X;
    int n = heap.size();
    TopDownHeapify(heap, n, i);
}

void BuildHeap(vector<int> heap, int n) // order nlogn
{
    for (int i = 0; i < n; i++)
        Bottom_Up_Heapify(heap, i);
}

void BuildHeap2(vector<int> heap, int n) // order n
{
    int i = n / 2;
    while (i > -1)
        TopDownHeapify(heap, n, i--);
}

// HeapSort algo
vector<int> BuildHeap_heapsort(vector<int> heap, int n)
{
    int m = n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = Delete(heap, &m);
    return ans;
}

int Level(int i)
{
    int l = 0;
    while (i > 0)
    {
        i = (i - 1) / 2;
        ++l;
    }
    return l;
}

int LeastCommonAncestor1(int i, int j) // order logn
{
    while (i != j)
    {
        if (i > j)
            i = (i - 1) / 2;
        else
            j = (j - 1) / 2;
    }
    return i;
}

int ShortestPath(int i, int j)
{
    int count = 0;
    while (i != j)
    {
        if (i < j)
            i = (i - 1) / 2;
        else
            j = (j - 1) / 2;
        count++;
    }
    return count;
}

int main()
{

    return 0;
}