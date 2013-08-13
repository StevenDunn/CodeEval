// Unique Elements solution in Java for CodeEval.com by Steven A. Dunn

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Set;


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
        Set<String> uniqueElements = new LinkedHashSet<String>(Arrays.asList(tokens)); 

        StringBuffer sb = new StringBuffer("");
        for(String element : uniqueElements)
          sb.append(element + ",");

        sb.setLength(sb.length() - 1);

        System.out.println(sb.toString());
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
}
