class Solution {
public:
    int reverse(int x) {

        int reverseDigit = 0;

        while (x) {
            try {
                if (reverseDigit > INT_MAX / 10 || reverseDigit < INT_MIN / 10) {
                    throw 0;
                }
                reverseDigit = reverseDigit * 10 + x % 10;
                x = x / 10;
            } catch (int x) {
                return 0;
            }
        }
        return reverseDigit;
    }
};