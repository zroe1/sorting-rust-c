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
    let mut nums: Vec<u16> = vec![1, 2, 3];
    println!("{:?}", nums);
    insertion_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u16> = vec![3, 2, 1];
    println!("{:?}", nums);
    insertion_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u16> = vec![1, 11, 2, 6, 3, 5, 4];
    println!("{:?}", nums);
    insertion_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u16> = vec![1];
    println!("{:?}", nums);
    insertion_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u16> = vec![2, 1];
    println!("{:?}", nums);
    insertion_sort(&mut nums);
    println!("{:?}\n", nums);
}
