// morse code soln in c# for code eval by steven a dunn

using System;
using System.IO;
using System.Collections.Generic;

class MorseCode {
  static Dictionary<string, char> morse = new Dictionary<string, char>();

  public static void Main(string[] args) {
    initializeDict();
    using (StreamReader reader = new StreamReader(args[0])) {
      while (!reader.EndOfStream) {
        string line = reader.ReadLine();
        if (null == line)
          continue;
        string[] words = line.Trim().Split();
        foreach (string word in words) {
          Console.Write(morse[word]);
        }
        Console.WriteLine();
      }
    }
  }

  static void initializeDict() {
    morse.Add(".-", 'A');
    morse.Add("-...", 'B');
    morse.Add("-.-.", 'C');
    morse.Add("-..", 'D');
    morse.Add(".", 'E');
    morse.Add("..-.", 'F');
    morse.Add("--.", 'G');
    morse.Add("....", 'H');
    morse.Add("..", 'I');
    morse.Add(".---" , 'J');
    morse.Add("-.-", 'K');
    morse.Add(".-..", 'L');
    morse.Add("--", 'M');
    morse.Add("-.", 'N');
    morse.Add("---", 'O');
    morse.Add(".--.", 'P');
    morse.Add("--.-", 'Q');
    morse.Add(".-.", 'R');
    morse.Add("...", 'S');
    morse.Add("-", 'T');
    morse.Add("..-", 'U');
    morse.Add("...-", 'V');
    morse.Add(".--", 'W');
    morse.Add("-..-", 'X');
    morse.Add("-.--", 'Y');
    morse.Add("--..", 'Z');
    morse.Add("-----", '0');
    morse.Add(".----", '1');
    morse.Add("..---", '2');
    morse.Add("...--", '3');
    morse.Add("....-", '4');
    morse.Add(".....", '5');
    morse.Add( "-....", '6');
    morse.Add("--...", '7');
    morse.Add("---..", '8');
    morse.Add("----.", '9');
    morse.Add("", ' ');
  }
}
