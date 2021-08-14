#![allow(non_snake_case, unused_variables, unused_mut)]

use proconio::input;

fn main() {
    input! {
        N: i64,
        // A: i64,
        // B: i64,
        // C: i64,
        // mut X: [i64; N],
    }

    let mut ans = 0;

    if N <= 125 {
        ans = 4;
    } else if N <= 211 {
        ans = 6;
    } else {
        ans = 8;
    }

    println!("{:?}", ans)
}
