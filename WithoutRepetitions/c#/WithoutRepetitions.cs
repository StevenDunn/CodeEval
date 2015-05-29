// without repetitions soln in c# for code eval by steven a dunn

using System;
using System.IO;

class WithoutRepetitions {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        line = line.Trim();
        string newLine = "";
        if (line.Length == 1) {
          Console.WriteLine(line);
          continue;
        }
        else {
          int x = 0;
          int y = 1;

          while (y < line.Length) {
            if (line[x] != line[y]) {
              newLine += line[x];
              if (y == line.Length - 1)
                newLine += line[y];
            }
            else {
              if (y == line.Length - 1)
                newLine += line[x];
            }
            x++; 
            y++;
          }
        }
        Console.WriteLine(newLine);
      }
    }
  }
}