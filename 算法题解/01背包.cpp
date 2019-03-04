#include <iostream>
using namespace std;

struct A
{
    int val;
    int weight;
};

int main()
{
    int sum, maxVal;
    int i, j, n;
    cin >> sum >> n;
    A *arr = new A[n+1];
    int *b = new int[sum+1];
    for (i = 1; i <= n; i ++)
    {
        cin >> arr[i].val;
        cin >> arr[i].weight;
    }
    for (i = 1; i <= sum; i ++)
    	b[i] = 0;
    for (i = 1; i <= n; i ++)
    {
        for (j = sum-arr[i].val; j >= 1; j --)
        {
        	if (b[j+arr[i].val] < b[j]+arr[i].weight)
        		b[j+arr[i].val] = b[j]+arr[i].weight;
        }
    }
    maxVal = 0;
    for (i = 1; i <= sum; i ++)
    {
        if (b[i] > maxVal)
            maxVal = b[i];
    }
    free(arr);
    free(b);
    cout << maxVal << endl;
}
