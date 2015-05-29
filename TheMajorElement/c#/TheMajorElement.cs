// the major element soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class TheMajorElement {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] elements = line.Trim().Split(',');
        int threshold = elements.Length/2;

        string majElem = "None";
        var groups = elements.GroupBy(item => item);
        foreach (var group in groups) {
          if (group.Count() > threshold)
            majElem = group.Key;
        }

        Console.WriteLine(majElem);
      }
    }
  }
}
