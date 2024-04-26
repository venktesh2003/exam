#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void bubble_sort(vector<int> &v)
{
    int n = v.size();
#pragma omp parallel for shared(v, n)
    for (int i = 0; i < n; i++)
    {
#pragma omp parallel for shared(v, n)
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bubble_sort(v);
    cout << "\n Sorted array is: " << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
}
