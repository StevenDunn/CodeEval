// capitalize words soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Linq;

class CapitalizeWords {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        
        string[] words = line.Split(' ').Select(x => UppercaseFirst(x)).ToArray();
        Console.WriteLine(String.Join(" ", words));
      }
    }
  }

  static string UppercaseFirst(string s) {
    if (s.Length == 0)
      return String.Empty;
    return char.ToUpper(s[0]) + s.Substring(1);
  }
}