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

        int number = Int32.Parse(line);
        number = calc(number, 1000, "M");
        number = calc(number, 900, "CM");
        number = calc(number, 500, "D");
        number = calc(number, 400, "CD");
        number = calc(number, 100, "C");
        number = calc(number, 90, "XC");
        number = calc(number, 50, "L");
        number = calc(number, 40, "XL");
        number = calc(number, 10, "X");
        number = calc(number, 9, "IX");
        number = calc(number, 5, "V");
        number = calc(number, 4, "IV");
        for (int i = 0; i < number; i++)
          Console.Write("I");
        Console.WriteLine();
      }
    }
  }

  static int calc(int number, int value, string letter) {
    while (number >= value) {
      Console.Write(letter);
      number -= value;
    }
    return number;
  }
}