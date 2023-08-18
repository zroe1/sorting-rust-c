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

fn swap(nums: &mut Vec<u16>, i: usize, j:usize) {
    let temp: u16 = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

fn shuffle(nums: &mut Vec<u16>, rng: &mut rand::rngs::ThreadRng) {

    let mut idx1: usize;
    let mut idx2: usize;

    for _ in 0..nums.len() {
        idx1 = rng.gen_range(0..nums.len());
        idx2 = rng.gen_range(0..nums.len());

        swap(nums, idx1, idx2);
    }
}

fn bogo_sort(nums: &mut Vec<u16>) {
    let mut rng = rand::thread_rng();

    while !check_array_sorted(nums) {
        shuffle(nums, &mut rng)
    }
}

fn main() {
    let mut rng = rand::thread_rng();

    let mut nums: Vec<u16> = vec![0; 10];
    for num in nums.iter_mut() {
        *num = rng.gen_range(0..u16::MAX);
    }

    println!("{:#?}", nums);
    bogo_sort(&mut nums);
    println!("{:#?}", nums);

    if check_array_sorted(&nums) {
        println!("Result of sorting check: True (bogo sort worked)");
    } else {
        println!("Result of sorting check: False (bogo sort failed)");
    }
}
