// Sum of Primes solution in Java for CodeEval.com by Steven A. Dunn

public class Main
{
  public static void main(String[] args)
  {
    long primeSum = 2;
    int num = 3;
    int primeCount = 2;
 
    while(primeCount <= 1000)
    {
      if(isPrime(num))
      {
        primeSum += num;
        primeCount++;
      }
      num = num + 2;
    }
    System.out.println(primeSum);
  }

  static boolean isPrime(int num)
  {
    for(int i = 3; i < num; i = i + 2)
      if (num % i == 0) { return false; }
    return true;
  }
}
