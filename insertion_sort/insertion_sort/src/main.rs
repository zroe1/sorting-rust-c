extern crate rand;
use rand::Rng;

fn check_array_sorted(nums: &Vec<u16>) -> bool {
    let mut last_num: u16 = 0;
    for num in nums.iter() {
        if *num < last_num {
            return false
        }
        last_num = *num;
    }
    return true;
}

fn insertion_sort(nums: &mut Vec<u16>) {
    for i in 1..nums.len() {
        let temp: u16 = nums[i];
        let mut current_idx: usize = i;
        while current_idx > 0 && temp < nums[current_idx - 1] {
            nums[current_idx] = nums[current_idx - 1];
            current_idx -= 1;
        }
        nums[current_idx] = temp;
    }
}

fn main() {
    let mut rng = rand::thread_rng();

    let mut nums: Vec<u16> = vec![0; 10];
    for num in nums.iter_mut() {
        *num = rng.gen_range(0..u16::MAX);
    }

    println!("{:#?}", nums);
    insertion_sort(&mut nums);
    println!("{:#?}", nums);

    if check_array_sorted(&nums) {
        println!("Result of sorting check: True (insertion sort worked)");
    } else {
        println!("Result of sorting check: False (insertion sort failed)");
    }
}
