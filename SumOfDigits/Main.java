// Sum of Digits solution in Java for CodeEval.com by Steven A. Dunn

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
        System.out.println(getSum(line));
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
  
  static int getSum(String line)
  {
    int number = Integer.parseInt(line);
    int part = 0;
    int sum = 0;

    while(number > 0)
    {
      part = (number % 10);
      sum += part;
      number = (number / 10);
    }
    return sum;
  }
}
