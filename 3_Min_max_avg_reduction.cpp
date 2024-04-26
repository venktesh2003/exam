#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

int sum_reduction(vector<int> &arr)
{
    int sum = 0;

#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    return sum;
}

int min_reduction(vector<int> &arr)
{
    int min_value = INT_MAX;

#pragma omp parallel for reduction(min : min_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (min_value > arr[i])
        {
            min_value = arr[i];
        }
    }

    return min_value;
}

int max_reduction(vector<int> &arr)
{
    int max_value = INT_MIN;

#pragma omp parallel for reduction(max : max_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }

    return max_value;
}

int avg_reduction(vector<int> &arr)
{
    int max_value = INT_MIN;

    int sum = 0;
    int n = arr.size();
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    return (sum / n);
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in an array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nSun of array is: " << sum_reduction(arr) << endl;
    cout << "\nAverage of array is: " << avg_reduction(arr) << endl;
    cout << "\nMin value of array is: " << min_reduction(arr) << endl;
    cout << "\nMax value of array is: " << max_reduction(arr) << endl;
}