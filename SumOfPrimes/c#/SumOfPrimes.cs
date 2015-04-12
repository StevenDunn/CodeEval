using System;

class SumOfPrimes {
    public static void Main(string[] args) {
        int primeSum = 2;
        int num = 3;
        int primeCount = 1;
        while (primeCount < 1000) {
            if (isPrime(num)) {
                primeSum += num;
                primeCount++;
            }
            num += 2;
        }
        Console.WriteLine(primeSum);
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
}