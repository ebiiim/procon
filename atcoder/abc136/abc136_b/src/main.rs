#![allow(non_snake_case)]

use proconio::input;

fn main() {
    input! {
        N: i64,
    }

    // 1..9, 100..999, 10000..99999
    // 10..99, 1000..9999, 100000..

    let mut ans = 0;

    let n1 = 99-10+1;
    let n2 = 9999-1000+1;

    let a1 = 9;
    let a2 = a1 + 900;
    let a3 = a2 + 90000;

    if N < 10 {
        ans = N;
    } else if N < 100 {
        ans = a1;
    } else if N < 1000 {
        ans = N - n1;
    } else if N < 10000 {
        ans = a2;
    } else if N < 100000 {
        ans = N - n1 - n2;
    } else if N < 1000000 {
        ans = a3;
    }

    println!("{}", ans)
}
