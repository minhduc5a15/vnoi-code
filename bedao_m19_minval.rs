use std::io::{self, BufRead};

fn gcd(a: i32, b: i32) -> i32 {
    return if b == 0 { a } else { gcd(b, a % b) };
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let arr: Vec<i32> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut res = arr[0];
    for i in 1..n {
        res = gcd(res, arr[i]);
    }
    println!("{}", res);
}
