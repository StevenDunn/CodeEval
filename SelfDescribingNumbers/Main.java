// Self Describing Numbers solution in Java for CodeEval.com by Steven A. Dunn

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main
{
  static ArrayList<Integer> counts = new ArrayList<Integer>();

  public static void main(String[] args)
  {
    try 
    {
      BufferedReader br = new BufferedReader(new FileReader(args[0]));
      String line;

      while( (line = br.readLine()) != null)
      {
        System.out.println(isSelfDescribing(Integer.parseInt(line)));
        counts.clear();
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static int isSelfDescribing(int number)
  {
    for(int i = 0; i < 10; ++i)
      counts.add(0);

    final int ASCII_TO_INT_CONVERSION = (int)('0');
    int digit = 0;
    int n = number;
    while (n > 0)
    {
      digit = (n % 10);
      int updatedDigit = counts.get(digit) + 1;
      counts.set(digit, updatedDigit);
      n = (n / 10);
    }

    String numStr = "" + number;
    for (int i = 0; i < numStr.length(); ++i)
      if ((numStr.charAt(i) - ASCII_TO_INT_CONVERSION) != counts.get(i)) { return 0; }

    return 1;
  }
}
