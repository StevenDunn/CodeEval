// Prime Palindrome solution in Java for CodeEval.com by Steven A. Dunn

import java.io.*;

public class Main
{
  public static void main(String[] args)
  {
    for(int palIdx = 1000; palIdx > 9; palIdx--)
      if(isPrime(palIdx))
        if(isPalindrome(palIdx))
        {
          System.out.println(palIdx);
          break;
        }
  }
  
  static boolean isPrime(int idx)
  {
    if (idx % 2 == 0) { return false; }
    
    for(int i = 3; i < idx; i = i + 2)
      if (idx % i == 0) { return false; }

    return true;
  }

  static boolean isPalindrome(int idx)
  {
    String original = "" + idx;
    StringBuffer str = new StringBuffer(original);
    String reverse = str.reverse().toString();

    if (original.equals(reverse))
      return true;

    return false;
  }
}
