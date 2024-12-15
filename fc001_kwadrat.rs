use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let n: u64 = stdin.lock().lines().next().unwrap().unwrap().parse().unwrap();
    let mut m: u64 = n;
    let mut counter: HashMap<u64, i32> = HashMap::new();
    while m % 2 == 0 {
        m >>= 1;
        *counter.entry(2).or_insert(0) += 1;
    }
    let mut i = 3;
    while i * i <= n {
        while m % i == 0 {
            *counter.entry(i).or_insert(0) += 1;
            m /= i;
        }
        i += 2;
    }
    if m > 1 {
        counter.insert(m, 1);
    }
    for (_, v) in &mut counter {
        *v += *v & 1;
    }
    let mut res = 1;
    for (k, v) in counter {
        res *= k.pow(v as u32);
    }
    println!("{}", res);
}
