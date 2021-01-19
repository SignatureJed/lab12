#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double d[],int N, double z[])
{   
    double sum=0;
    for (int i = 0; i < N; i++)
    {
        sum += d[i];
    }   
        z[0] =  sum/N;  sum = 0;
   
    double S_D;
    for (int i = 0; i < N; i++)
    {   
        sum += pow(d[i]-z[0],2);
    }   
        S_D = (sqrt(sum/N));        z[1] = S_D;     sum = 1;  
        
    double G_M=0;    
    for (int i = 0; i < N; i++)
    {
        sum *= d[i];
    }
        G_M = pow(sum,(1.0/N));     z[2] = G_M;     sum = 0;

    double H_M =0;
    for (int i = 0; i < N; i++)
    {
        sum += 1.0/d[i];
    }
        H_M = N/sum;                z[3] = H_M;
        double max = d[0];
    for (int i = 1; i < N; i++)  
    {
        if (d[i]>max)
        {
            max = d[i];
        }
    }
                                    z[4] = max;
        double min = d[0];
    for (int i = 1; i < N; i++)  
    {
        if (d[i]<min)
        {
            min = d[i];
        }
    }
        z[5] = min;
}       