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

fn count_sort(nums: &mut Vec<u16>) {
    let mut count_arr: Vec<u16> = vec![0; (65536) as usize];

    for num in nums.into_iter() {
        count_arr[*num as usize] += 1;
    }
    
    let mut rv_idx: usize = 0;
    for i in 0..count_arr.len() {
        while count_arr[i] > 0 {
            nums[rv_idx] = i as u16;
            count_arr[i] -= 1;
            rv_idx += 1;
        }
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
        count_sort(&mut nums);
        let duration = start.elapsed();

        println!("{},{:?}", i * 100, duration.as_secs_f64());
    }
}
