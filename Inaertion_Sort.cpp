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
    void insertstart(int);
    void insertmiddle(int, int);
    void insertend(int);
    void deletefirst();
    void deleteatend();
    void deletemiddle(int);
    void bubble();
    void selection();
    void insertionsort();
    void display();
};
void Array ::insertstart(int elt)
{
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = elt;
    n = n + 1;
}
void Array ::insertend(int elt)
{
    arr[n] = elt;
    n = n + 1;
}
void Array ::insertmiddle(int elt, int pos)
{
    for (int i = n - 1; i >= (pos - 1); i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = elt;
    n = n + 1;
}
void Array ::deletefirst()
{
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}
void Array ::deleteatend()
{
    n--;
}
void Array ::deletemiddle(int position)
{
    if (position < 1 || position > n)
    {
        return;
    }
    for (int i = position - 1; i < n - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}
void Array ::bubble()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
void Array ::selection()
{
    for(int i =0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        if(i!=minIndex)
        {
            int temp = arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}
void Array ::insertionsort()
{
    for(int j=1;j<n;j++)
    {
        int i =j-1;
        int elt = arr[j];
        while(i>=0 && elt<arr[i])
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=elt;
    }
}
void Array ::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    Array array1;

    while (1)
    {
        cout << "choose 1 for insert at start" << endl;
        cout << "choose 2 for insert at end" << endl;
        cout << "choose 3 for insert at middle" << endl;
        cout << "choose 4 for deleting at start" << endl;
        cout << "choose 5 for deleting at end" << endl;
        cout << "choose 6 for deleting at middle" << endl;
        cout << "choose 7 for display" << endl;
        cout << "choose 8 for Bubble sorting" << endl;
        cout << "choose 9 for Selection sorting" << endl;
        cout << "choose 10 for Insertion sorting" << endl;
        cout << "choose any other value for exiting" << endl;
        int n1;
        cin >> n1;
        if (n1 == 1)
        {
            int elt;
            cin >> elt;
            array1.insertstart(elt);
        }
        else if (n1 == 2)
        {
            int elt;
            cin >> elt;
            array1.insertend(elt);
            // array1.display();
        }
        else if (n1 == 3)
        {
            int elt;
            cin >> elt;
            int pos;
            cin >> pos;
            array1.insertmiddle(elt, pos);
        }
        else if (n1 == 4)
        {
            array1.deletefirst();
        }
        else if (n1 == 5)
        {
            array1.deleteatend();
        }
        else if (n1 == 6)
        {
            int position;
            cin >> position;
            array1.deletemiddle(position);
        }
        else if (n1 == 7)
        {
            array1.display();
        }
        else if (n1 == 8)
        {
            array1.bubble();
        }
        else if (n1 == 9)
        {
            array1.selection();
        }
        else if (n1 == 10)
        {
            array1.insertionsort();
        }
        else
        {
            exit(0);
            cout << "exit"
                << " ";
        }
    }
    return 0;
}