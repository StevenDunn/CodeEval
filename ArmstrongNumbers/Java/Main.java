// Armstrong Numbers solution in Java for CodeEval.com by Steven A. Dunn

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main
{
  public static void main(String[] args)
  {
    try
    {
      BufferedReader br = new BufferedReader(new FileReader(args[0]));
      String line;

      while( (line = br.readLine()) != null)
      {
        int num = Integer.parseInt(line);
        if(isArmstrongNumber(num))
          System.out.println("True");
        else
          System.out.println("False");
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static boolean isArmstrongNumber(int number)
  {
    int numDigits = 0;
    int part = 0;
 
    int n = number;
    while (n > 0)
    {
      part = (n % 10);
      numDigits++;
      n = (n / 10);
    }
 
    n = number;
    double sum = 0;
    while (n > 0)
    {
      part = (n % 10);
      sum += Math.pow((double)part, (double)numDigits);
      n = (n/10);
    }
    if ((int)sum == number) 
      return true;
    return false;
  }
}

