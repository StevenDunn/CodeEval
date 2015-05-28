// even numbers soln in c# for code eval by steven a dunn

using System;
using System.IO;

class FindAWriter {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        int n = Int32.Parse(line);
        if (n % 2 == 0)
          Console.WriteLine(1);
        else
          Console.WriteLine(0);
      }
    }
  }
}