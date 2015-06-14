// Sum of Integers from File solution in Java for CodeEval.com by Steven A. Dunn

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
      int sum = 0;

      while( (line = br.readLine()) != null)
        sum += Integer.parseInt(line);

      System.out.println(sum);
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
}
