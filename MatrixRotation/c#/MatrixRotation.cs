// matrix rotation soln in c# for code eval by steven a dunn

using System;
using System.IO;

class MatrixRotation {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        string[] matrix = line.Trim().Split();
        int n = (int)Math.Sqrt(matrix.Length);
        string result = "";

        for (int j = 0; j < n; j++)
          for (int i = n - 1; i > -1; i--)
            result += matrix[(i * n) + j] + " ";
        Console.WriteLine(result);
      }
    }
  }
}