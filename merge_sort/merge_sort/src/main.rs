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

fn merge(left: &mut Vec<u16>, right: &mut Vec<u16>, merged: &mut Vec<u16>) {
    let mut left_pointer: usize = 0;
    let mut right_pointer: usize = 0;

    let mut merged_pointer: usize = 0;
    while left_pointer < left.len() && right_pointer < right.len() {
        if left[left_pointer] < right[right_pointer] {
            merged[merged_pointer] = left[left_pointer];
            left_pointer += 1;
        } else {
            merged[merged_pointer] = right[right_pointer];
            right_pointer += 1
        }
        merged_pointer += 1
    }

    while left_pointer < left.len() {
        merged[merged_pointer] = left[left_pointer];
        left_pointer += 1;
        merged_pointer += 1;
    }

    while right_pointer < right.len() {
        merged[merged_pointer] = right[right_pointer];
        right_pointer += 1;
        merged_pointer += 1;
    }
}


fn merge_sort(nums: &mut Vec<u16>) {
    if nums.len() <= 1 {
        return
    }

    let left_len: usize = nums.len() / 2;
    let mut left: Vec<u16> = nums[0..left_len].to_vec();
    let mut right: Vec<u16> = nums[left_len..nums.len()].to_vec();

    merge_sort(&mut left);
    merge_sort(&mut right);
    merge(&mut left, &mut right, nums)
}

fn main() {
    let mut rng = rand::thread_rng();

    let mut nums: Vec<u16> = vec![0; 10];
    for num in nums.iter_mut() {
        *num = rng.gen_range(0..u16::MAX);
    }

    println!("{:#?}", nums);
    merge_sort(&mut nums);
    println!("{:#?}", nums);

    if check_array_sorted(&nums) {
        println!("Result of sorting check: True (merge sort worked)");
    } else {
        println!("Result of sorting check: False (merge sort failed)");
    }
}


