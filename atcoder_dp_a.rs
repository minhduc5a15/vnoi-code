use std::io::{self, BufRead, Stdin};

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line = lines.next().unwrap().unwrap();
    let n: usize = line.parse().unwrap();
    let arr: Vec<i32> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut dp: Vec<i32> = vec![0; n + 1];
    dp[0] = 0;
    dp[1] = (arr[1] - arr[0]).abs();
    for i in 2..n {
        dp[i] = std::cmp::min(dp[i - 1] + (arr[i] - arr[i - 1]).abs(), dp[i - 2] + (arr[i] - arr[i - 2]).abs());
    }
    let res = dp[n - 1];
    println!("{}", res);
}
