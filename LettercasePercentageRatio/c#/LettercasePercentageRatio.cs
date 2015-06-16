// lettercase percentage ratio soln in c# for code eval by steven a dunn

using System;
using System.IO;

class DataRecovery {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        float upper_count = 0.0f;
        float lower_count = 0.0f;

        char[] chars = line.Trim().ToCharArray();
        foreach (char c in chars) {
          if (char.IsUpper(c))
            upper_count += 1.0f;
          else if (char.IsLower(c))
            lower_count += 1.0f;
        }

        float total_count = upper_count + lower_count;
        float upper_percent = (upper_count / total_count) * 100.0f;
        float lower_percent = (lower_count / total_count) * 100.0f;

        Console.WriteLine("lowercase: " + lower_percent.ToString("N" + 2) +  " uppercase: " + upper_percent.ToString("N" + 2));
      }
    }
  }
}