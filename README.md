# Comparing Sorting Algorithms in Rust and C

I created this repository to experiment with different sorting algorithms and compare the preformance of C and Rust. To my surprise, Rust has significantly better preformance than C in most of the sorting algorithms I tested (big win for Rustaceans🦀). Although this doesn't mean that Rust is univerally faster than C, it shows how despite being new, the Rust language is extremely powerful and useful.

## How I tested preformance:
All algorithms were tested on arrays filled randomly with 16 bit unsigned integers of varying length. The largest arrays I tested were about 30,000 numbers long which was enough to get a good idea of how the algorithm preforms on larger inputs.

<b>Note about NULL pointers in C code: </b>I don't check for NULL pointers after memory allocation in this repository although if you use any of this code as a part of larger product, I would recomend it.

## Bubble sort
<b>Description: </b> Bubble interates through an array and swaps larger elements up twoards the top of the array. This process is repeated untill the array is sorted. Bubble sort is often chosen for it's simplicity an conciseness.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-21 at 10 10 35 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/f8a731f1-ea47-4ac0-aa90-ea3954db7e36">

## Insertion sort
<b>Description: </b> Insertion sort builds up a sorted array by inserting each element into its correct position relative to the previously sorted elements. I like insertion sort because it is similar to how I would approach sort in the physical world. It also seems to be faster than bubble sort in my implementations.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-21 at 10 12 00 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/4f292b47-d9fe-4de0-b813-e7c23d1b42ec">

## Selection sort
<b>Description: </b> Insertion sort selects the smallest number in the array, stores it in the correct possition and then repeats (finding the second smallest number, then the third, then the fourth, ect.) until the array is sorted. I find selection sort to be the easiest sorting algorithm to wrap your head arround.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-21 at 10 15 14 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/7c8f2e17-1687-4604-b227-4d81a7b36911">

## Merge sort
<b>Description: </b> Merge sort breaks an array down into single pieces and then puts it back together in sorted order using resursive calls. It is faster on larger inputs than simpler algorithms like bubble sort, but cannot sort in constant space like those other algorithms (there actually is a constant space implementation of merge sort but it is not commonly used or discussed).  
<b>Time complexity: </b> O(nlog(n))  
<b>Space complexity: </b> O(n)  
<img width="603" alt="Screenshot 2023-08-21 at 10 17 16 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/7db866fc-be8a-405e-9b32-e8afd694d294">

## Heap sort
<b>Description: </b> Heap sort turns an array into a max heap and then removes the max item one by one to create a sorted array. Unlike merge sort, the algorithm works in constant space.  
<b>Time complexity: </b> O(nlog(n))  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-21 at 10 20 27 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/a452919a-fd1d-4e3d-9a98-b5561b067d43">

## Count sort
<b>Description: </b> Count sort works by allocating an array with length (input max - input min + 1) and initializing all elements to 0. It then counts how many of each element is in the original array, storing the counts in the allocated array. By doing this, the algorithm can reproduce a sorted version of the array based on the counts it collected. As you can see below, it is faster than merge sort and heap sort on the arrays of unsigned 16 bit integers I tested in this repository.  
<b>Note: </b>  My version of count sort is designed it work on unsigned 16 bit integers. It would have to be modified to work on larger or negative data types.  
<b>Time complexity: </b> O(n + k) (k being input max - input min + 1)  
<b>Space complexity: </b> O(k) (there is also a common O(n + k) space complexity version of this algorithm)  
<img width="603" alt="Screenshot 2023-08-20 at 1 26 36 PM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/dbc348ae-6d38-4c88-8250-97eed5f71f84">

## Radix sort
<b>Description: </b> Radix sort uses count sort (slight variation to the count sort described above) to sort the numbers by least significant digit up to most. Radix sort is helpful on arrays with larger integers or strings because it doesn't require allocation of a data structure that is the size of the range of the input.  
<b>Time complexity: </b> O(n)  
<b>Space complexity: </b> O(n)  
<img width="603" alt="Screenshot 2023-08-21 at 12 13 48 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/065c578a-d47b-41cc-9d95-ed0f0885a9e1">


## Bogo sort (stupid sort)
<b>Description: </b> Bogo sort shuffles an array until it finds the right solution. My implementation of bogo sort randomly shuffles an array (there is also a deterministic solution) so it basically just guesses until it guesses right. For an 11 length array, my Rust solution takes 12 seconds to guess the right answer. I couldn't test larger arrays becuase it would take too long to run. So, yeah. It's pretty slow. We can do better.  
<b>Time complexity: </b> I don't even want to know.  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-21 at 10 22 17 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/a556706c-fb92-4954-8f93-9388db655fa0">









