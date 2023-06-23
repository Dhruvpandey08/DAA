#include <iostream>
using namespace std;


class TWODARRAY
{	
	private:
		int A[100][100],res[100];
		int m;
		int n;
	public:
		void inputmatrix();
		void rowSum(int,int);
		void columnSum(int,int);
		void display_rowSum();
		void display_columnSum();
		void display_maxrow(int,int);
};

void TWODARRAY :: inputmatrix()
{
   cout << "Enter the size of row : ";
   cin >> m;
   cout << "Enter the size of column :";
   cin >> n;
   
   cout<<"\nInput the matrix: "<<endl;
   for(int i = 0; i < m; i++)
   {
   	for(int j = 0; j < n; j++)
   	{
            cin >> A[i][j];
        }
   }
   
}

void TWODARRAY :: rowSum(int m,int n)
{
    int sum;
    for(int i = 0; i < m; i++)
    {
        sum = 0;
        
        for(int j = 0; j < n; j++)
        {
            sum = sum + A[i][j];   
        }
        
        cout<<"sum of "<<"row "<<i+1<<" is: "<<sum<<endl;     
    }
}

void TWODARRAY :: columnSum(int m, int n)
{
    int sum;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        
        for(int j = 0;j < m; j++)
        {
            sum = sum + A[j][i];  
        }   
        
        cout<<"Sum of column "<<i+1<<" is: "<<sum<<endl;   
    }
}



void TWODARRAY :: display_rowSum()
{
	cout<<"\nSum of each row: \n"<<endl;
	rowSum(m, n);
}

void TWODARRAY :: display_columnSum()
{
	cout<<"\nSum of each column: \n"<<endl;
	columnSum(m ,n);
}

void TWODARRAY :: display_maxrow(int m,int n)
{
	int max = 0;
	
	for (int i=0;i<m;i++)
	{
		max = 0;
		
		for (int j=0;j<n;j++)
		{
			if (A[i][j]>max)
			{
				max = A[i][j];
			}
		}
		i++;
	}
}


int main()
{
	int m,n;
	TWODARRAY array1;
	array1.inputmatrix();
	array1.rowSum(m,n);
	array1.columnSum(m,n);
	array1.display_rowSum();
	array1.display_columnSum();
	array1.display_maxrow(m,n);
}