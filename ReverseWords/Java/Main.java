// Reverse Words solution in Java for CodeEval.com by Steven A. Dunn

import java.io.*;

public class Main
{
  public static void main(String[] args)
  {
    try
    {
      BufferedReader br = new BufferedReader(new FileReader(args[0]));
      String line;
      
      while ( (line = br.readLine()) != null)
        System.out.println(reverseLine(line));
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static String reverseLine (String line)
  {
    String result = "";
    String[] words = line.split(" ");
    for (int i = words.length - 1; i >= 0; --i)
       result += (words[i] + " ");

    return result;
  }
}
