// Rightmost Char solution in Java for CodeEval.com by Steven A. Dunn

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
        char lastChar = line.charAt(line.length() - 1);
        for(int i = line.length() - 3; i >= 0; --i)
        { 
          if(line.charAt(i) == lastChar)
          {
            System.out.println(i);
            break;
          }
          if(i == 0)
            System.out.println(-1);
        }
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
}
