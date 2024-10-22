fn bubble_sort(arr: &mut [i32]) {
    let mut n = arr.len();
    let mut swapped;
    while n > 1 {
        swapped = false;
        for i in 0..n - 1 {
            if arr[i] > arr[i + 1] {
                arr.swap(i, i + 1);
                swapped = true;
            }
        }
        if !swapped {
            break;
        }
        n -= 1;
    }
}

fn selection_sort(arr: &mut [i32]) {
    let n = arr.len();
    for i in 0..n {
        let mut min_idx = i;
        for j in i + 1..n {
            if arr[j] < arr[min_idx] {
                min_idx = j;
            }
        }
        arr.swap(i, min_idx);
    }
}

fn insertion_sort(arr: &mut [i32]) {
    let n = arr.len();
    for i in 1..n {
        let mut j = i;
        while j > 0 && arr[j - 1] > arr[j] {
            arr.swap(j, j - 1);
            j -= 1;
        }
    }
}

fn merge_sort(arr: &mut [i32]) {
    let n = arr.len();
    if n <= 1 {
        return;
    }
    let mid = n / 2;
    merge_sort(&mut arr[..mid]);
    merge_sort(&mut arr[mid..]);
    let mut merged = arr.to_vec();
    merge(&arr[..mid], &arr[mid..], &mut merged[..]);
    arr.copy_from_slice(&merged);
}

fn merge(left: &[i32], right: &[i32], result: &mut [i32]) {
    let (mut i, mut j, mut k) = (0, 0, 0);
    while i < left.len() && j < right.len() {
        if left[i] <= right[j] {
            result[k] = left[i];
            i += 1;
        } else {
            result[k] = right[j];
            j += 1;
        }
        k += 1;
    }
    if i < left.len() {
        result[k..].copy_from_slice(&left[i..]);
    }
    if j < right.len() {
        result[k..].copy_from_slice(&right[j..]);
    }
}

fn quick_sort(arr: &mut [i32]) {
    let len = arr.len();
    if len <= 1 {
        return;
    }
    let pivot_index = partition(arr);
    quick_sort(&mut arr[0..pivot_index]);
    quick_sort(&mut arr[pivot_index + 1..len]);
}

fn partition(arr: &mut [i32]) -> usize {
    let len = arr.len();
    let pivot = len - 1;
    let mut i = 0;
    for j in 0..pivot {
        if arr[j] < arr[pivot] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, pivot);
    i
}


fn main() {
    println!("Top 5 sorting algorithms in rust above!");
}
