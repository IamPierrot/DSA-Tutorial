#include <iostream>
#include <time.h>
#include <cstdlib>

void quickSort(long long arr[], long long left, long long right)
{
     long long pivot;
     if (left < right)
     {
          pivot = arr[(long long)(left + right) / 2];

          long long i = left, j = right;

          while (i < j)
          {
               while (arr[i] < pivot)
               {
                    i++;
               }
               while (arr[j] > pivot)
               {
                    j--;
               }
               if (i <= j)
               {
                    auto swap = [](long long &a, long long &b)
                    {
                         long long temp = a;
                         a = b;
                         b = temp;
                    };

                    swap(arr[i], arr[j]);
                    i++;
                    j--;
               }
          }
          quickSort(arr, left, j);
          quickSort(arr, i, right);
     }
     return;
}
void BinarySearch(long long arr[], long long target, int start, int end)
{
     if (start > end)
     {
          std::cout << "Not Found";
          return;
     }

     int middle = (int)(start + end) / 2;

     if (arr[middle] == target)
     {
          std::cout << "Found it at index: " << middle << std::endl;
          return;
     }

     if (arr[middle] > target)
     {
          BinarySearch(arr, target, start, middle - 1);
          std::cout << "middle - 1" << std::endl;
          return;
     }

     if (arr[middle] < target)
     {
          BinarySearch(arr, target, middle + 1, end);
          std::cout << "middle +1" << std::endl;
          return;
     }
}
int Searching()
{
     srand(time(0));

     const int n = 100000;
     long long Array[n]{};

     long long target;
     std::cin >> target;
     
     for (int i = 0; i < n; i++)
     {
         Array[i] = static_cast<long long>(rand() % 100) + 1;
     }

     quickSort(Array, 0, static_cast<long long>(n) - 1);

     std::cout << "Sau khi sap xep" << std::endl;
     for (auto &&x : Array)
     {
          std::cout << x << " ";
     }

     
     BinarySearch(Array, target, 0, n - 1);

     return 0;
}
