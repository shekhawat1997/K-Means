#include <bits/stdc++.h>
using namespace std;
#define ll long long int;
double manhattan_distance(double x1, double y1, double x2, double y2)
{
    return (abs(x2 - x1) + abs(y2 - y1));
}
double general_distance(double x1, double y1, double x2, double y2)
{
    return (sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)));
}
double error_distance(double x1, double y1, double x2, double y2)
{
    return ((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}
int main()
{
    int K, x, y, points;
    //cout << "Enter Number Of Points\n";
    cin >> points;
    double A[points][2] = { 0 };
    //cout << "Enter Points\n";
    for(int i = 0; i < points; i++)
    {
       for(int j = 0; j < 2; j++)
        {
            cin >> A[i][j];
        }
    }
    //cout << "how many cluster you want to ??\n";
    cin >> K;
    //K = 3;
    double C[K][2] = { 0 };
    double old_C[K][2] = { 0 };
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> C[i][j];
            old_C[i][j] = C[i][j];
        }
    }
    printf("\n");
    double arr[points][K] = { 0 };
    int mn, index;
    int mid_arr[K], old_mid_arr[K];
    for(int i = 0; i < K; i++)
    {
        mid_arr[i] = 0;
        old_mid_arr[i] = 0;
    }
    int iteration = 0;
    while(1)
    {
        iteration++;
        //cout << "Calculation For "<< iteration << " Iteration\n";
        //printf("--------------------------------------------\n");
        printf("--------------------------------------------\n");
        cout << "Centroid For Iteration  =  " << iteration << "\n";
        for(int i = 0; i < K; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                old_C[i][j] = C[i][j];
                cout << C[i][j] << "    ";
            }
            printf("\n");
        }
        printf("--------------------------------------------\n");
        double sum = 0;
        for(int i = 0; i < points; i++)
        {
            for(int j = 0; j < K; j++)
            {
                sum += error_distance(A[i][0], A[i][1], C[j][0], C[j][1]);
                arr[i][j] = manhattan_distance(A[i][0], A[i][1], C[j][0], C[j][1]);
                cout << arr[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << "SUM   " << sum << "\n";
        //cout << "\n";
        for(int i = 0; i < K; i++)
        {
            C[i][0] = 0;
            C[i][1] = 0;
            mid_arr[i] = 0;
        }
        for(int i = 0; i < points; i++)
        {
            mn = INT_MAX;
            for(int j = 0; j < K; j++)
            {
                if(mn > arr[i][j])
                {
                    mn = arr[i][j];
                    index = j;
                }
            }
            //cout << "min " << mn << "   " << index << "\n";
            mid_arr[index]++;
            C[index][0] += A[i][0];
            C[index][1] += A[i][1];
        }
        for(int i = 0; i < K; i++)
        {
            if(mid_arr[i] > 0)
            {
                C[i][0] = C[i][0] / mid_arr[i];
                C[i][1] = C[i][1] / mid_arr[i];  
            }
            else
            {
                C[i][0] = old_C[i][0];
                C[i][1] = old_C[i][1];
            }
        }
        int count = 0;
        for(int i = 0; i < K; i++)
        {
            if(old_mid_arr[i] == mid_arr[i])
            {
                count++;
            }
        }
        if(count == K)
        {
            break;
        }
        else
        {
            for(int i = 0; i < K; i++)
            {
                old_mid_arr[i] = mid_arr[i];
            }
        }
        printf("\n");
    }
    cout << "Number of Iteration  =  " << iteration << "\n";
    return 0;
}
//k_mean.cpp
