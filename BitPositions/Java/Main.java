// Bit Positions solution in Java for CodeEval.com by Steven A. Dunn

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
        String binaryRep = Integer.toBinaryString(n);

        int p1 = Integer.parseInt(tokens[1]);
        char bit1 = binaryRep.charAt(binaryRep.length() - p1);

        int p2 = Integer.parseInt(tokens[2]);
        char bit2 = binaryRep.charAt(binaryRep.length() - p2);

        boolean result = false;
        if (bit1 == bit2)
          result = true;

        System.out.println(result);
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
}
