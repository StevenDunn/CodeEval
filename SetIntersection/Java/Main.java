// Set Intersection solution in Java for CodeEval.com by Steven A. Dunn

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
        String[] sets = line.split(";");
        String[] set1 = sets[0].split(",");
        String[] set2 = sets[1].split(",");

        Set<String> listSet1 = new LinkedHashSet<String>(Arrays.asList(set1));
        Set<String> listSet2 = new LinkedHashSet<String>(Arrays.asList(set2));
        Set<String> intersectionSet = new LinkedHashSet<String>();

        for(String s : listSet1)
          if(listSet2.contains(s))
            intersectionSet.add(s);
       
        StringBuffer formattedResult = new StringBuffer("");
        for(String s: intersectionSet)
          formattedResult.append(s + ",");
        if(formattedResult.length() == 0)
          System.out.println();
        else
        {
          formattedResult.setLength(formattedResult.length() - 1);
          System.out.println(formattedResult.toString());
        }
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }
}
