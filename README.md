# Comparing Sorting Algorithms in Rust and c

## Bogo sort
<b>Description: </b> Bogo sort shuffles an array until it finds the right solution. My implementation of bogo sort randomly shuffles an array (there is also a deterministic solution) so it basically just guesses until it guesses right. For an 11 length array, my Rust solution takes 12 seconds to guess the right answer. I couldn't test larger arrays becuase it would take too long to run. So, yeah. It's pretty slow. We can do better.  
<b>Time complexity: </b> I don't even want to know.  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-18 at 8 32 40 PM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/91945f06-b66a-40d5-9a73-6decdc56844e">


## Bubble sort
<b>Description: </b> Bubble interates through an array and swaps larger elements up twoards the top of the array. This process is repeated untill the array is sorted. Bubble sort is often chosen for it's simplicity an conciseness.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-18 at 9 05 54 PM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/bc18a864-81c1-4249-b465-04040daece2c">

## Insertion sort
<b>Description: </b> Insertion sort builds up a sorted array by inserting each element into its correct position relative to the previously sorted elements. I like insertion sort because it is similar to how I would approach sort in the physical world. It also seems to be faster than bubble sort in my implementations.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-18 at 10 59 11 PM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/94252caf-fd7b-499b-8117-f326813b21f7">

## Selection sort
<b>Description: </b> Insertion sort selects the smallest number in the array, stores it in the correct possition and then repeats (finding the second smallest number, then the third, then the fourth, ect.) until the array is sorted. I find selection sort to be the easiest sorting algorithm to wrap your head arround.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(1)  
<img width="603" alt="Screenshot 2023-08-19 at 11 32 22 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/bbbc763e-9dfa-4532-acaf-4ba75605abad">

## Merge sort
<b>Description: </b> Merge sort breaks an array down into single pieces and then puts it back together in sorted order using resursive calls. It is faster on larger inputs than simpler algorithms like bubble sort, but cannot sort in constant space like those other algorithms (there actually is a constant space implementation of merge sort but it is not commonly used or discussed).  
<b>Time complexity: </b> O(nlog(n))  
<b>Space complexity: </b> O(n)  
<img width="598" alt="Screenshot 2023-08-19 at 11 52 04 AM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/a073c198-aa51-4960-8daa-81f7bde7c0f0">



