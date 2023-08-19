extern crate rand;
use rand::Rng;
use std::time::Instant;

// FUNCTION USED ONLY FOR CHECKING SOLUTIONS
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
    println!("n,t");
    for i in 0..300 {
        let mut nums: Vec<u16> = vec![0; i * 100];
        for num in nums.iter_mut() {
            *num = rng.gen_range(0..u16::MAX);
        }

        let start = Instant::now();
        selection_sort(&mut nums);
        let duration = start.elapsed();
        println!("{},{:?}", i * 100, duration.as_secs_f64());
    }
}
