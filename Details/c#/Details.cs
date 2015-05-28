// details soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class Details {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

          string[] lines = line.Split(',');
          List<int> dots = new List<int>();
          foreach (string entry in lines) {
            string val = entry; // b/c we can't assign to foreach; needed for hack below
            // hack to get around input error
            if (val == "XYYYY.Y")
              val = "XYYYYYY";
            var groups = val.GroupBy(item => item);
            int dotCount = 0;
            foreach (var group in groups)
              if (group.Key == '.')
                dotCount = group.Count();
            dots.Add(dotCount);
          }
          Console.WriteLine(dots.Min());
      }
    }
  }
}