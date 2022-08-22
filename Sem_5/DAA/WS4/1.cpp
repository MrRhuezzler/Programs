// Find maximum and minimum of a set of elements using divide and conquer.

#include <iostream>
#include <algorithm>
#include <vector>

std::pair<int,int> minMax(int *arr, int n)
{
    if (n == 1)
        return std::make_pair(arr[0], arr[0]);
    if (n == 2)
        return std::make_pair(std::min(arr[0], arr[1]), std::max(arr[0], arr[1]));
    int mid = n / 2;
    std::pair<int,int> left = minMax(arr, mid);
    std::pair<int,int> right = minMax(arr + mid, n - mid);
    return std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
}

int main()
{

    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::pair<int,int> ans = minMax(arr, n);
    std::cout << ans.first << " " << ans.second << std::endl;
    delete[] arr;

    return 0;
}