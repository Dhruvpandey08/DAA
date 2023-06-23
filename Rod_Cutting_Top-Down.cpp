#include <iostream>
#include <limits.h>
using namespace std;

class RodCut
{

private:
        int p[100],r[100];
        int n;
        int m;
public:
        void input_array();
        int Mem_cut_rod(int);
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

    for (int i = 0; i <= m; i++)
    {
        r[i] = INT_MIN;
    }

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;
}

int RodCut::getN()
{
    return n;
}

int RodCut::Mem_cut_rod(int n)
{
    int q;
    
    if (r[n] >= 0)
    {
        return r[n];
    }

    if (n == 0)
    {
        q = 0;
    }
    else
    {
        q = INT_MIN;
        for (int i=1;i<n;i++)
        {
            int price = p[i] + Mem_cut_rod(n-i-1);

            if (price>q)
            {
                q = price;
            }
        }
        r[n] = q;
    }
    return q;
}

int main()
{
    RodCut obj;
    obj.input_array();
    int maxcost = obj.Mem_cut_rod(obj.getN());
    std::cout << "Maximum cost : " << maxcost << std::endl;

    return 0;
    
}