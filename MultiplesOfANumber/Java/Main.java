// Multiples of a Number solution in Java for CodeEval.com by Steven A. Dunn

import java.io.*;

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
        int x = Integer.parseInt(tokens[0]);
        int n = Integer.parseInt(tokens[1]);
        
        while (x >= n)
          n = n << 1;

        System.out.println(n);
      }
    }
    catch(IOException ex) { ex.printStackTrace(); } 
  }
}
