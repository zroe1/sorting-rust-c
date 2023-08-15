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

fn selection_sort(nums: &mut Vec<u16>) {
    for i in 0..nums.len() {
        let mut current_min = nums[i];
        let mut idx_current_min = i;
        for j in i..nums.len() {
            if nums[j] < current_min {
                current_min = nums[j];
                idx_current_min = j;
            }
        }
        let temp: u16 = nums[i];
        nums[i] = nums[idx_current_min];
        nums[idx_current_min] = temp;
    }
}

fn main() {
    let mut rng = rand::thread_rng();

    let mut nums: Vec<u16> = vec![0; 10];
    for num in nums.iter_mut() {
        *num = rng.gen_range(0..u16::MAX);
    }

    println!("{:#?}", nums);
    selection_sort(&mut nums);
    println!("{:#?}", nums);

    if check_array_sorted(&nums) {
        println!("Result of sorting check: True (selection sort worked)");
    } else {
        println!("Result of sorting check: False (selection sort failed)");
    }
}
