// swap case soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class SwapCase {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        
        string swappedCase = new string(
          line.Select(
            c => char.IsLetter(c) ?
              (char.IsUpper(c) ? char.ToLower(c) : char.ToUpper(c))
              : c
          ).ToArray());
        Console.WriteLine(swappedCase);
      }
    }
  }

 
}