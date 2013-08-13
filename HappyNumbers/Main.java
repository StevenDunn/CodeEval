// Happy Numbers solution in Java for CodeEval.com by Steven A. Dunn

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main
{
  static ArrayList<Integer> visited = new ArrayList<Integer>();

  public static void main(String[] args)
  {
    try
    {
      BufferedReader br = new BufferedReader(new FileReader(args[0]));
      String line;

      while( (line = br.readLine()) != null)
      {
        if (isHappy(Integer.parseInt(line)))
          System.out.println(1);
        else
          System.out.println(0);
        visited.clear();
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static boolean isHappy(int num)
  {
    int sum = 0;
    int part = 0;
 
    while (num > 0)
    {
      part = (num % 10);
      sum += (part * part);
      num = (num / 10);
    }
 
    if (sum == 1) { return true; }
 
    for (int i = 0; i < visited.size(); i++)
      if (i == sum) { return false; }
    visited.add(sum);

    if(isHappy(sum)) { return true; }

    return false;
  }
}
