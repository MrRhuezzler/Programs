#include<iostream>
#define N 5
using namespace std;

void merge(int a[N][2], int l, int mid, int r)
{
    int n1=mid-l+1, n2=r-mid;
    int left[n1][2];
    int right[n2][2];

    for(int i=0;i<n1;++i)
    {
        left[i][0]=a[l+i][0];
        left[i][1]=a[l+i][1];
    }

    for(int j=0;j<n2;++j)
    {
        right[j][0]=a[mid+j+1][0];
        right[j][1]=a[mid+j+1][1];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(left[i][0]<=right[j][0])
        {
            a[k][0]=left[i][0];
            a[k][1]=left[i][1];
            ++i;
        }
        else
        {
            a[k][0]=right[j][0];
            a[k][1]=right[j][1];
            ++j;
        }
        ++k;
    }

    while(i<n1)
    {
        a[k][0]=left[i][0];
        a[k][1]=left[i][1];
        ++i;
        ++k;
    }

    while(j<n2)
    {
        a[k][0]=right[j][0];
        a[k][1]=right[j][1];
        ++j;
        ++k;
    }
}

void mergeSort(int a[N][2], int l, int r)
{
    if(l<r)
    {
        int mid=(r+l)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}


int main()
{

    // N -> Macro defined
    int a[N][2];
    a[0][0]=2;
    a[0][1]=3;
    a[1][0]=3;
    a[1][1]=4;
    a[2][0]=5;
    a[2][1]=2;
    a[3][0]=7;
    a[3][1]=1;
    a[4][0]=6;
    a[4][1]=5;

    // Sort the coordinates based on x-coordinates
    // O(n log n)
    mergeSort(a, 0, 4);

    int rank;
    int rankArray[N];

    // After sorting the 0th coordinate has a rank of 0, always since sorting has been done.
    rankArray[0]=0;

    for(int i=1;i<N;++i)
    {
        rank=0;
        for(int j=0;j<i;++j)
        {
            // O(n)
            // Check for other points with their y-coordinates
            if(a[i][1]>a[j][1])
            {
                ++rank;
            }
        }
        rankArray[i]=rank;
    }

    // Printing the ranks
    for(int i=0;i<N;++i)
    {
        cout << "Rank of " <<  "(" << a[i][0] << ", " << a[i][1] << ")" << " : " << rankArray[i] << endl;
    }

    // Time Complexity: O(n) + O(n log n) = O(n log n)
    return 0;
}