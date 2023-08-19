# Comparing Sorting Algorithms in Rust and c

## Bogo sort
<b>Description: </b> Bogo sort shuffles an array until it finds the right solution. My implementation of bogo sort randomly shuffles an array (there is also a deterministic solution) so it basically just guesses until it guesses right. For an 11 length array, my Rust solution takes 12 seconds to guess the right answer. I couldn't test larger arrays becuase it would take too long to run. So, yeah. It's pretty slow. We can do better.  
<b>Time complexity: </b> I don't even want to know.  
<b>Space complexity: </b> O(n)  
<img width="603" alt="Screenshot 2023-08-18 at 8 32 40 PM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/91945f06-b66a-40d5-9a73-6decdc56844e">


## Bubble sort
<b>Description: </b> Bubble interates through an array and swaps larger elements up twoards the top of the array. This process is repeated untill the array is sorted. Bubble sort is often chosen for it's simplicity an conciseness.  
<b>Time complexity: </b> O(n<sup>2</sup>)  
<b>Space complexity: </b> O(n)  
<img width="603" alt="Screenshot 2023-08-18 at 9 02 28 PM" src="https://github.com/zroe1/sorting-rust-c/assets/114773939/77d34fda-0090-47bc-bd35-d17f09ffab3d">
