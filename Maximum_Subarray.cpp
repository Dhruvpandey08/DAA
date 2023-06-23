#include <iostream>
#include <limits>
using namespace std;

class Array
{
private:
    int arr[100];
    int n;

public:
    Array()
    {
        n = 0;
    }
    int max(int, int);
    int max(int, int, int);
    int cross_sum(int, int, int, int&, int&);
    int subarray(int, int, int&, int&);
    int getN();
    void inputArray();
};
int Array::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int Array::max(int a, int b, int c)
{
    return max(max(a, b), c);
}
int Array::cross_sum(int low, int mid, int high, int& startIndex, int& endIndex)
{
    int leftsum = INT8_MIN;
    int sum = 0;
    int maxleft = mid;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (leftsum < sum)
        {
            leftsum = sum;
            maxleft = i;
        }
    }
    int rightsum = INT8_MIN;
    sum = 0;
    int maxright = mid + 1;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (rightsum < sum)
        {
            rightsum = sum;
            maxright = i;
        }
    }
    startIndex = maxleft;
    endIndex = maxright;
    return leftsum + rightsum;
}

int Array::subarray(int low, int high, int& startIndex, int& endIndex)
{
    if (low == high)
    {
        startIndex = low;
        endIndex = high;
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;
    int leftSum = subarray(low, mid, leftStart, leftEnd);
    int rightSum = subarray(mid + 1, high, rightStart, rightEnd);
    int crossSum = cross_sum(low, mid, high, crossStart, crossEnd);
    

    if (leftSum >= rightSum && leftSum >= crossSum)
    {
        startIndex = leftStart;
        endIndex = leftEnd;
        return leftSum;
    }
    else if (rightSum >= leftSum && rightSum >= crossSum)
    {
        startIndex = rightStart;
        endIndex = rightEnd;
        return rightSum;
    }
    else
    {
        startIndex = crossStart;
        endIndex = crossEnd;
        return crossSum;
    }
}
int Array::getN()
{
    return n;
}
void Array::inputArray()
{
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "Enter the elements in array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    Array array1;
    array1.inputArray();
    int count = array1.getN();
    int startIndex, endIndex;
    int maxSum = array1.subarray(0, count - 1, startIndex, endIndex);
    cout << "Maximum subarray sum: " << maxSum << endl;
    cout << "Starting index: " << startIndex << endl;
    cout << "Ending index: " << endIndex << endl;

    return 0;
}