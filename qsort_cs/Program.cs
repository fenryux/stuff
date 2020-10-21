using System;
using System.Collections.Generic;

namespace qsort_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> array = new List<int>();
            Random rng = new Random();
            Console.WriteLine("Enter array size: ");
            int size = Convert.ToInt32(Console.ReadLine());
            
            for (int i = 0; i < size; i++)
                array.Add(rng.Next(10000));
            foreach (var item in array)
                Console.Write(item.ToString() + ' ');
            Console.WriteLine();

            qsort(array,0,array.Count-1);

            foreach (var item in array)
                Console.Write(item.ToString() + ' ');

            Console.ReadLine();
        }
        static void qsort(List<int> array, int begin, int end)
        {
            int left = begin;
            int right = end;

            int pivot = array[(left + (right-1))/2];

            do
            {
                while (array[left] < pivot)
                    left++;
                while(array[right] > pivot)
                    right--;
                if(left <= right)
                {
                    int temp = array[left];
                    array[left] = array[right];
                    array[right] = temp;
                    left++;
                    right--;
                }
            } while (left <= right);

            if(begin < right)
                qsort(array,begin,right);
            if(left < end)
                qsort(array,left,end);
        }
    }
}
