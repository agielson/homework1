using System;
namespace Project {
    class MainClass {
        public static void Main(string[] args) {
            int a = 0; int b = 0;   
            string str = "(5*(x+3))-1/(cos(x)))-2";
            if (str.Contains(")")){
                a++;
            }
            if (str.Contains("(")){ 
                b++;
            }
            int c = a - b;
            if (c == 0)
            {
                Console.WriteLine("All ok");
            }
            else
            {
                Console.WriteLine("You have mistake, my friend");
            }
        }
    }
}