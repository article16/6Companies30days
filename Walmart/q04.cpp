class Solution
{
public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        int N = m + n - 2;
        int r = m - 1;
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};