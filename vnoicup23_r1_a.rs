use ::std::io::{self, BufRead, Stdin};

fn main() {
    let stdin: Stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: i32 = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
        let mut arr: Vec<usize> = lines.next().unwrap().unwrap().split_whitespace().map(|x| x.parse().unwrap()).collect();
        arr.insert(0, 0);
        let mut check = false;
        for i in 1..=n {
            if i == arr[arr[arr[i]]] {
                println!("<3");
                check = true;
                break;
            }
        }
        if !check { println!("</3"); }
    }
}
