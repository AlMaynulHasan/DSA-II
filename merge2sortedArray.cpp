#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int A[n1];
    for (int i=0; i<n1; i++)
    {
        cin>>A[i];
    }

    int B[n2];
    for (int j=0; j<n2; j++)
    {
        cin>>B[j];
    }
    int R[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if (A[i]<=B[j])
        {
            R[k]=A[i];
            k++;
            i++;
        }
        else
        {
            R[k]=B[j];
            k++;
            j++;
        }
        for(int x=0; x<k; x++)
            cout<<R[x]<<" ";
        cout<<endl;
    }
    while(i<n1)
    {
        R[k]=A[i];
        cout<<R[k];
        k++;
        i++;
        for(int x=0; x<k; x++)
            cout<<R[x]<<" ";
        cout<<endl;

    }
    while(j<n2)
    {
        R[k]=B[j];
        k++;
        j++;
        for(int x=0; x<k; x++)
            cout<<R[x]<<" ";
        cout<<endl;
    }
    for (int i=0; i<n1+n2; i++)
    {
        cout<<R[i]<<" ";
    }

    return 0;
}
