// compressed sequences soln in c# for code eval by steven a dunn

using System;
using System.IO;

class CompressedSequence {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] vals = line.Trim().Split();
        int count = 0;
        string c = vals[0];
        foreach (string i in vals) {
          if (i == c)
            count += 1;
          else {
            Console.Write(count + " " + c + " ");
            count = 1;
            c = i;
          }
        }
        Console.WriteLine(count + " " + c);
      }
    }
  }
}