// juggling with zeros soln in c# for code eval by steven a dunn

using System;
using System.IO;

class JugglingWithZeros {

  public static string ones(string seq) {
    string result = "";
    for (int i = 0; i < seq.Length; i++)
      result += "1";
    return result;
  }

  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (line == null)
          continue;

        string[] tokens = line.Trim().Split();
        string binary = "";
        for (int i = 0; i < tokens.Length; i = i + 2) {
          string flag = tokens[i];
          string seq = tokens[i+1];
          if (flag == "00")
            binary += ones(seq);
          else
            binary += seq;
        }
        Console.WriteLine(Convert.ToInt64(binary, 2));
      }
    }
  }
}