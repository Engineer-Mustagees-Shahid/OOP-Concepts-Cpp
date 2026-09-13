#include<iostream>
using namespace std;

int unique_path(int m,int n)
{
 
    int appp[m][n];
    
    for (int i=0; i<m; i++)
    {
        appp[i][0]=1;
    }

    for (int j=0; j<n; j++)
    {
        appp[0][j]=1; 
    }
    
    for (int i=1; i<m; i++)
    {
        for (int j=1; j<n; j++)
        {
            appp[i][j]=appp[i-1][j]+appp[i][j-1];
        }
    }

    return appp[m-1][n-1];

}

int main()
{

    int m,n;
    cout<<"Enter grid dimensions: ";
    cin>>m>>n;

    cout<<"Unique paths: "<<unique_path(m,n)<<endl;

    return 0;
}