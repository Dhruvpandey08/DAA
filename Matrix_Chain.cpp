#include<iostream>
#include<limits.h>

using namespace std;

class MCM 
{

   private:
       int arr[100];
       int n;

   public:
       MCM()
       {    
           n=0;
       }

       void input_matrix();
       void matrix_chain();
       void display();
};

void MCM::input_matrix() 
{
           cout << "Enter number of matrices: ";
           cin >> n;
           n++;

           cout << "Enter dimensions: \n";
           for(int i=0;i<n;i++) 
           {
               //cout << "Enter d" << i << ": ";
               cin >> arr[i];
           }
}

void MCM::matrix_chain() 
{
           int m[n][n];
           int i, j, k, l, q;

           for (i=1; i<n; i++)
               m[i][i] = 0;

           for (l=2; l<n; l++) {
               for (i=1; i<n-l+1; i++) {
                   j = i+l-1;
                   m[i][j] = INT_MAX;

                   for (k=i; k<=j-1; k++) {
                       q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                       if (q < m[i][j]) {
                           m[i][j] = q;
                       }
                   }
               }
           }

           cout << "Minimum number of multiplications is " << m[1][n-1] << endl;
}

void MCM::display() 
{
           cout << "Dimensions are: ";
           for(int i=0; i<n; i++) 
           {
               cout << arr[i] << " ";
           }
           cout << endl;
}

int main()
{
   MCM obj;
   obj.input_matrix();
   obj.matrix_chain();
   obj.display();

   return 0;
}