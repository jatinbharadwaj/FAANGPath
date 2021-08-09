// https://leetcode.com/problems/three-divisors/
class Solution
{
public:
    bool isThree(int n)
    {

        int isNotPrime[10003] = {0};
        for (int i = 2; i < 10003; i++)
        {
            if (!isNotPrime[i])
                for (int j = i * 2; j * j < 10003; j += i)
                {
                    isNotPrime[j] = 1;
                }
        }
        double sroot = sqrt(n);
        int insroot = sqrt(n);
        cout << sroot << isNotPrime[insroot];

        if (sroot > insroot || n == 1)
        {
            return false;
        }
        else if (isNotPrime[insroot])
        {
            return false;
        }
        return true;
    }
};

// Alternate Solution

class Solutions
{
public:
    bool isThree(int n)
    {

        int countDivisors = 0;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                countDivisors++;
            if (countDivisors > 1)
                return false;
        }

        if (countDivisors == 1)
            return true;
        else
            return false;
    }
}