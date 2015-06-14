// N Mod M solution in Java for CodeEval.com by Steven A. Dunn

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
        String[] tokens = line.split(",");
        int n = Integer.parseInt(tokens[0]);
        int m = Integer.parseInt(tokens[1]);

        int x = n / m;
        int y = x * m;
        int mod = n - y;
 
        System.out.println(mod); 
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
}
