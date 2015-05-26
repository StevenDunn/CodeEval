// prime palindrome soln in c# for code eval by steven a dunn

using System;

class PrimePalindrome {
    public static void Main(string[] args) {
        for (int palIdx = 1000; palIdx > 0; palIdx--) {
            if (isPrime(palIdx) && isPalindrome(palIdx))
            {
                Console.WriteLine(palIdx);
                break;
            }
        }
    }

    static bool isPrime(int n) {
        if (n % 2 == 0)
            return false;
        else {
            for (int i = 3; i < n; i += 2)
                if (n % i == 0)
                    return false;
            return true;
        }
    }

    static bool isPalindrome(int n) {
        string numStr = Convert.ToString(n);
        char[] characters = numStr.ToCharArray();
        Array.Reverse(characters);
        string reversedStr = new string(characters);
        if (reversedStr == numStr)
            return true;
        return false;
    }
}