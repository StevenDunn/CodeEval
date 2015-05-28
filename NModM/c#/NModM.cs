// n mod m soln in c# for code eval by steven a dunn

using System;
using System.IO;

class NModM {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] inputs = line.Split(',');
        int n = Int32.Parse(inputs[0]);
        int m = Int32.Parse(inputs[1]);

        int x = n / m;
        int y = x * m;
        int mod = n - y;

        Console.WriteLine(mod);
      }
    }
  }

}