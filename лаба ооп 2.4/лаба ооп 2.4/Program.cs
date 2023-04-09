using System;
namespace Prime
{
    class Program
    {
        public static bool IsPrime(int number)
        {
            for (int i = 2; i < number; i++)
            {
                if (number % i == 0)
                    return false;
            }
            return true;
        }
       
        static void Main(string[] args)
        {
            Console.WriteLine("Введите конечное значение диапазона 1...N и нажмите Enter");
            Console.WriteLine("N = ");
            if ((!int.TryParse(Console.ReadLine(), out int result)) || (result < 0))
                Console.WriteLine("Число должно быть положительным и целым");
            Console.WriteLine($"Простые числа из диапазона от 1 до {result}");
            int count = 0;
            for (int i = 1; i <= result; i++)
            {
                if (IsPrime(i))
                {
                    Console.Write($"{i} ");
                    count++;
                }
            }
            Console.WriteLine("");
            Console.WriteLine($"Найдено {count} простых чисел из диапазона от 1 до {result}\n");
            string str = "Hello, My name is Galiya";
            string str1 = "";

            foreach (char t in str)
                str1 += t.ToString().FirstOrDefault(s => s.ToString().ToLower() != "а" && s.ToString().ToLower() != "a" && s.ToString().ToLower() != "e" && s.ToString().ToLower() != "i" && s.ToString().ToLower() != "o" &&
                             s.ToString().ToLower() != "u" && s.ToString().ToLower() != "y");
            Console.WriteLine(str1);

            Console.WriteLine("Массив до");

            int[] arr2 = { 1, 2 , 3, 4 , 5, 6  };
            for (int i = 0; i < arr2.Length; i++) {
                Console.Write(arr2[i] + " ");



            }
            Array.Sort(arr2);
            Array.Reverse(arr2);
            Console.WriteLine();
            Console.WriteLine("Массив после");

            for (int i = 0; i < arr2.Length; i++)
            {
                Console.Write(arr2[i] + " ");
            }





        }
    }
}
