#include <iostream>
#include <limits.h>
using namespace std;

class RodCut
{

private:
        int p[100];
        int n;
        int m;
public:
        void input_array();
        int cut_rod(int);
        int getN();
};

void RodCut::input_array()
{
   
    std::cout << "Enter the total length of the rod: " << std::endl;
    std::cin >> m;
    std::cout << "Enter the price of rod cuts one by one: " << std::endl;

    for (int i=0;i<m;i++)
    {
        std::cin >> p[i];
    }

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;
}

int RodCut::getN()
{
    return n;
}

int RodCut::cut_rod(int n)
{
    int q = INT_MIN;
    
    if (n==0)
    {
        return 0;
    }

    for (int i=1;i<n;i++)
    {
        int price = (p[i]+cut_rod(n-i-1));

        if (price > q)
        {
            q = price;
        }
    }
    return q;
}

int main()
{
    RodCut obj;
    obj.input_array();
    int maxcost = obj.cut_rod(obj.getN());
    std::cout << "Maximum cost : " << maxcost << std::endl;

    return 0;
    
}