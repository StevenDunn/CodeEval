// hidden digits soln in c# for code eval by steven a dunn

using System;
using System.IO;

class HiddenDigits {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

          string result = "";
          foreach (char c in line)
            if (char.IsLetter(c)) {
              int x = (int)(c - 'a');
              if (x < 10 && x >= 0)
                result += x;
            }
            else if (char.IsDigit(c))
              result += c;

          if (result.Length == 0)
            result = "NONE";
          Console.WriteLine(result);
      }
    }
  }
}