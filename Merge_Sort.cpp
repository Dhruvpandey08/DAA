#include <iostream>
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
    void inputarray();
    int getN();
    void mergedarray(int,int,int);
    void merge(int,int,int);
    void mergesort(int,int);
    void display();

};
void Array :: inputarray()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
}
int Array :: getN()
{
    return n;
}
void Array :: mergedarray(int s,int m,int e)
{
    cout<<"Merged Array is: ";
    for(int i=s;i<=m;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"and ";
    for(int i = m+1;i<=e;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Array :: merge(int s,int m,int e)
{
    mergedarray(s,m,e);
    int temp[100];
    int i=s;
    int j=m+1;
    int k=0;

    while(i<=m && j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int x=0,y=s;x<k;x++,y++)
    {
        arr[y]=temp[x];
    }
}
void Array :: mergesort(int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int m = s+(e-s)/2;
    mergesort(s,m);
    mergesort(m+1,e);
    merge(s,m,e);
}
void Array :: display()
{
    cout<<"Sorted Array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Array array1;
    array1.inputarray();
    int count = array1.getN();
    array1.mergesort(0,count-1);
    array1.display();

    return 0;
}