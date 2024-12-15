use std::io::{self, BufRead, Stdin};
use std::collections::BTreeSet;

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let line = lines.next().unwrap().unwrap();
    let n: i32 = line.parse().unwrap();
    let mut arr: Vec<i32> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut lis = BTreeSet::new();
    for num in arr {
        let pos = lis.range(num..).next().cloned();
        if let Some(val) = pos {
            lis.remove(&val);
        }
        lis.insert(num);
    }
    println!("{}", lis.len());
}
