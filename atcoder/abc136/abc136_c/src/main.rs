#![allow(non_snake_case)]
use proconio::input;

fn main() {
    input! {
        N: i64,
        mut H: [i64; N],
    }

    let mut ans = "Yes";

    for i in 0..(H.len()) {
        if i == 0 {
            continue;
        }
        if H[i] >= H[i - 1] + 1 {
            H[i] -= 1;
        }
        if H[i] < H[i - 1] {
            ans = "No";
        }
    }

    // println!("{:?}", H);
    println!("{}", ans);
}
