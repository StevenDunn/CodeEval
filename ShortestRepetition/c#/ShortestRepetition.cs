// roman numerals soln in c# for code eval by steven a dunn

using System;
using System.IO;

class RomanNumerals {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        int period = 1;
        string subSeq = "" + line[0];
        for (int i = 1; i < line.Length; i++) {
          if (line.Substring(period).IndexOf(subSeq) != 0) {
            period += 1;
            subSeq += line[i];
          }
        }
        Console.WriteLine(period);
      }
    }
  }
}