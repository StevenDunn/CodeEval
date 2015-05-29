// read more soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class ReadMore {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        line = line.Trim();
        int lineLength = line.Length;
        if (lineLength > 55) {
          line = new string(line.Take(40).ToArray());
          int lastSpace = line.LastIndexOf(" ");
          if (lastSpace != -1)
            line = new string(line.Take(lastSpace).ToArray());
          line += "... <Read More>";
        }
        Console.WriteLine(line);
      }
    }
  }
}
