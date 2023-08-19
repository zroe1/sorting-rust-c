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

fn max_heapify(nums: &mut Vec<u16>, i: usize, heap_limit: usize) {
    if ((i + 1) * 2) < heap_limit {
        let left_child: usize = (i + 1) * 2 - 1;
        let right_child: usize = (i + 1) * 2;

        if nums[left_child] > nums[right_child] {
            if nums[left_child] > nums[i] {
                let temp: u16 = nums[i];
                nums[i] = nums[left_child];
                nums[left_child] = temp;
                max_heapify(nums, left_child, heap_limit)
            }
        } else {
            if nums[right_child] > nums[i] {
                let temp: u16 = nums[i];
                nums[i] = nums[right_child];
                nums[right_child] = temp;
                max_heapify(nums, right_child, heap_limit)
            }
        }
    } else if ((i + 1) * 2) - 1 < heap_limit {
        let left_child: usize = (i + 1) * 2 - 1;

        if nums[left_child] > nums[i] {
            let temp: u16 = nums[i];
            nums[i] = nums[left_child];
            nums[left_child] = temp;
            max_heapify(nums, left_child, heap_limit)
        }
    } else {
        return;
    }
}

fn build_max_heap(nums: &mut Vec<u16>) {
    for i in (0..(nums.len() / 2)).rev() {
        max_heapify(nums, i, nums.len());
    }
}

fn swap(nums: &mut Vec<u16>, i: usize, j:usize) {
    let temp: u16 = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

fn heap_sort(nums: &mut Vec<u16>) {
    build_max_heap(nums);
    let mut heap_limit = nums.len();

    while heap_limit >= 2 {
        swap(nums,heap_limit - 1, 0);
        heap_limit -= 1;
        max_heapify(nums, 0, heap_limit);
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
        heap_sort(&mut nums);
        let duration = start.elapsed();
        println!("{},{:?}", i * 100, duration.as_secs_f64());
    }
}
