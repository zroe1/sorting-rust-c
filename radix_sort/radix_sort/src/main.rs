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

fn count_sort(nums: &Vec<u16>, divisor: u32) -> Vec<u16> {
    let mut count_arr: Vec<u16> = vec![0; 10];

    for num in nums.into_iter() {
        count_arr[((*num as u32 / divisor) % 10) as usize] += 1;
    }

    let mut previous_count: u16 = 0;
    for count in count_arr.iter_mut() {
        *count += previous_count;
        previous_count = *count;
    }

    let mut rv: Vec<u16> = vec![0; nums.len()];
    for i in (0..nums.len()).rev() {
        let digit_of_focus: usize = ((nums[i] as u32/ divisor) % 10) as usize;
        let idx_for_rv: usize = (count_arr[digit_of_focus] - 1) as usize;
        rv[idx_for_rv] = nums[i];
        count_arr[digit_of_focus] -= 1;
    }
    rv
}

fn radix_sort(nums: &mut Vec<u16>) {
    let mut divisor: u32 = 1;
    while divisor <= 10000 {
        *nums = count_sort(&nums, divisor);
        divisor *= 10;
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
        radix_sort(&mut nums);
        let duration = start.elapsed();

        println!("{},{:?}", i * 100, duration.as_secs_f64());
    }
}