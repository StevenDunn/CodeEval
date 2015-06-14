// JSON menu ids soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class JSONMenuIds {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        line = line.Trim();
        string [] segments = line.Split(new string[] {"id"}, StringSplitOptions.None);
        int sum = 0;
        foreach (string segment in segments) {
          string[] labels = segment.Split(new string[] {"label"}, StringSplitOptions.None);
          foreach (string label in labels) {
            int start = label.IndexOf("Label");
            if (start < 0)
              continue;
            string sub = label.Substring(start+6);

            int end = sub.IndexOf("\"");
            if (end < 0)
              continue;
            sub = sub.Substring(0, end);
            sum += Int32.Parse(sub);
          }
        }
        Console.WriteLine(sum);
      }
    }
  }
}