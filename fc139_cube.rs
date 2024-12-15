use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let n: i32 = stdin.lock().lines().next().unwrap().unwrap().parse().unwrap();
    let mut i = 0;
    let mut s = 0;
    loop {
        if s >= n {
            break;
        }
        s += i * (i + 1) / 2;
        i += 1;
    }
    println!("{}", i - 2);
}
