// mixed content soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class MixedContent {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] vals = line.Trim().Split(',');
        List<string> words = new List<string>();
        List<string> numbers = new List<string>();

        foreach (string val in vals) {
          if (char.IsDigit(val[0]))
            numbers.Add(val);
          else
            words.Add(val);
        }

        if (words.Count > 0 && numbers.Count > 0)
          Console.WriteLine(String.Join(",", words) + "|" + String.Join(",", numbers));
        else if (words.Count > 0)
          Console.WriteLine(String.Join(",", words));
        else
          Console.WriteLine(String.Join(",", numbers));

      }
    }
  }
}
