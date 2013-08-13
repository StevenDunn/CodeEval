// Fibonacci Series solution in Java for CodeEval.com by Steven A. Dunn

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
        System.out.println(fib(Integer.parseInt(line)));
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static int fib(int num)
  {
    int buf1 = 1;
    int buf2 = 1;
    int temp = 0;

    if (num == 0) { return 0; }
    else if (num == 1 || num == 2) { return 1; }
    else
    {
      for (int fibIdx = 3; fibIdx <= num; ++fibIdx)
      {
        temp = buf1;
        buf1 = buf2;
        buf2 = buf1 + temp;
      }
    }
    return buf2;
  }
}
