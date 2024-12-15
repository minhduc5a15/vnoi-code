use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
        let arr: Vec<i64> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let mut res: i64 = 0;
        for i in 1..n {
            res += (arr[i] - arr[i - 1]) * (i as i64) * ((n - i) as i64);
        }
        println!("{}", res as f64 / 2.0);
    }
}
