import java.io.*;

public class Main
{
  public static void main(String[] args)
  {
    try
    {
      BufferedReader br = new BufferedReader(new FileReader(args[0]));
      String line;
 
      while ((line = br.readLine()) != null)
      {
        String[] tokens = line.split(" ");
        int A = Integer.parseInt(tokens[0]);
        int B = Integer.parseInt(tokens[1]);
        int N = Integer.parseInt(tokens[2]);

        System.out.println(fizzBuzz(A, B, N));
      }
    }
    catch(IOException ex) { ex.printStackTrace(); }
  }

  static String fizzBuzz(int a, int b, int n)
  {
    String result = "";
    for(int i = 1; i <= n; i++)
    {
      if (i % a == 0 && i % b == 0) { result += "FB"; }
      else if (i % a == 0) { result += "F"; }
      else if (i % b == 0) { result += "B"; }
      else { result += i; }
      result += " "; 
    }
    return result;
  }
}
