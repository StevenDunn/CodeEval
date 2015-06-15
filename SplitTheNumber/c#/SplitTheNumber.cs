// split the number c# soln for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class SplitTheNumber {
  public static void Main(string[] args) {
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (line == null)
          continue;

        string[] input = line.Split();
        string text = input[0];
        string pattern = input[1];

        List<int> numbers = new List<int>();
        List<char> operators = new List<char>();

        int last_idx = 0;
        for (int i = 0; i < pattern.Length; i++) {
          if (pattern[i] == '+' || pattern[i] == '-') {
            int number = Int32.Parse(text.Substring(last_idx, i-last_idx));
            last_idx = i;
            numbers.Add(number);
            operators.Add(pattern[i]);
          }
        }
        numbers.Add(Int32.Parse(text.Substring(last_idx)));
        
        int result = 0;
        foreach (char op in operators) {
          if (op == '+') 
            result += (numbers[0] + numbers[1]);
          else 
            result += (numbers[0] - numbers[1]);
          numbers[1] = result;
          numbers.RemoveAt(0);
        }
        Console.WriteLine(result);
      }
    }
  }
}

