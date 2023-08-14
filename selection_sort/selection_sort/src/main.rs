fn selection_sort(nums: &mut Vec<u32>) {
    for i in 0..nums.len() {
        let mut current_min = nums[i];
        let mut idx_current_min = i;
        for j in i..nums.len() {
            if nums[j] < current_min {
                current_min = nums[j];
                idx_current_min = j;
            }
        }
        let temp: u32 = nums[i];
        nums[i] = nums[idx_current_min];
        nums[idx_current_min] = temp;
    }
}

fn main() {
    let mut nums: Vec<u32> = vec![3, 2, 1];
    println!("{:?}", nums);
    selection_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u32> = vec![2, 1];
    println!("{:?}", nums);
    selection_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u32> = vec![1];
    println!("{:?}", nums);
    selection_sort(&mut nums);
    println!("{:?}\n", nums);

    let mut nums: Vec<u32> = vec![3, 5, 1, 2, 11];
    println!("{:?}", nums);
    selection_sort(&mut nums);
    println!("{:?}\n", nums);
}
