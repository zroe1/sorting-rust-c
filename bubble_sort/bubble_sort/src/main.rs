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

fn bubble_sort(nums: &mut Vec<u16>) {
    for i in 0..(nums.len()) {
        for j in 0..(nums.len() - i - 1) {
            if nums[j] > nums[j + 1] {
                let temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

fn main() {
    let mut rng = rand::thread_rng();

    let mut nums: Vec<u16> = vec![0; 10];
    for num in nums.iter_mut() {
        *num = rng.gen_range(0..u16::MAX);
    }

    println!("{:#?}", nums);
    bubble_sort(&mut nums);
    println!("{:#?}", nums);

    if check_array_sorted(&nums) {
        println!("Result of sorting check: True (insertion sort worked)");
    } else {
        println!("Result of sorting check: False (insertion sort failed)");
    }
}
