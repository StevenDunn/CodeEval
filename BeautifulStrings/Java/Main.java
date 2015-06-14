// Beautiful Strings solution in Java for CodeEval.com by Steven A. Dunn

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

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
        System.out.println(maxBeauty(line));
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static int maxBeauty(String line)
  {
    line = line.toLowerCase();

    final char ASCII_CONVERSION_VALUE = 'a';
    ArrayList<Integer> counts = new ArrayList<Integer>();
    for(int i = 0; i < 26; ++i)
      counts.add(0);

    for (int strIdx = 0; strIdx < line.length(); strIdx++)
    {
      if (line.charAt(strIdx) - ASCII_CONVERSION_VALUE >= 0 && line.charAt(strIdx) - ASCII_CONVERSION_VALUE <= 25)
      {
        int index = line.charAt(strIdx) - ASCII_CONVERSION_VALUE;
        int updatedVal = counts.get(index) + 1;
        counts.set(index, updatedVal);
      }
    }
    Collections.sort(counts);

    int beauty = 0;
    int weight = 26;
    for (int countsIdx = counts.size() - 1; countsIdx >= 0; countsIdx--)
    {
      beauty += (weight * counts.get(countsIdx));
      weight--;
    }
    return beauty;
  }
}
