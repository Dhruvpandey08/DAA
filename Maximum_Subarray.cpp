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
    int cross_sum(int, int, int, int&, int&);
    int subarray(int, int, int&, int&);
    int getN();
    void inputArray();
};
int Array::cross_sum(int low, int mid, int high, int& sindex, int& eindex)
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
    sindex = maxleft;
    eindex = maxright;
    return leftsum + rightsum;
}

int Array::subarray(int low, int high, int& sindex, int& eindex)
{
    if (low == high)
    {
        sindex = low;
        eindex = high;
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;
    int ans1 = subarray(low, mid, leftStart, leftEnd);
    int ans2 = subarray(mid + 1, high, rightStart, rightEnd);
    int ans3 = cross_sum(low, mid, high, crossStart, crossEnd);
    

    if (ans1 > ans2 && ans1 > ans3)
    {
        sindex = leftStart;
        eindex = leftEnd;
        return ans1;
    }
    else if (ans1 > ans2 && ans1 < ans3)
    {
        sindex = crossStart;
        eindex = crossEnd;
        return ans3;
    }
    else
    {
        sindex = rightStart;
        eindex = rightEnd;
        return ans2;
    }
}
int Array::getN()
{
    return n;
}
void Array::inputArray()
{
    cin >> n;
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
    int sindex, eindex;
    int ans = array1.subarray(0, count - 1, sindex, eindex);
    cout << "Maximum subarray sum: " << ans << endl;
    cout << "Starting index: " << sindex << endl;
    cout << "Ending index: " << eindex << endl;

    return 0;
}