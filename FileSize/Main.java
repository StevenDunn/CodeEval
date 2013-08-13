// File Size solution in Java for CodeEval.com by Steven A. Dunn

import java.io.File;

class Main
{
  public static void main(String[] args)
  {
    File file = new File(args[0]);
    System.out.println(file.length());
  }
}
