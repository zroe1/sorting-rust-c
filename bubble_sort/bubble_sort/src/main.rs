fn bubble_sort(nums: &mut Vec<u32>) {
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
    let mut nums: Vec<u32> = vec![4, 3, 2, 1];
    bubble_sort(&mut nums);
    println!("{:?}", nums);
}
