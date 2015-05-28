// Armstrong numbers soln in c# for code eval by steven a dunn

using System;
using System.IO;

class ArmstrongNumbers {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;

        if (isArmstrong(line))
          Console.WriteLine("True");
        else
          Console.WriteLine("False");
      }
    }
  }

  static bool isArmstrong(string n) {
    int sum = 0;
    int numDigits = n.Length;
    foreach (char c in n)
      sum += (int)Math.Pow(char.GetNumericValue(c), numDigits);
    if (sum == Int32.Parse(n))
      return true;
    return false;
  }
}