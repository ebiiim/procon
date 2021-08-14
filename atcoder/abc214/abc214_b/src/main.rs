#![allow(non_snake_case, unused_variables, unused_mut)]

use proconio::input;

fn main() {
    input! {
        // N: i64,
        A: i64,
        B: i64,
        // C: i64,
        // mut X: [i64; N],
    }

    let mut ans = 0;

    for a in 0..101 {
        for b in 0..101 {
            for c in 0..101 {
                if a+b+c <= A && a*b*c <= B {
                    // println!("{} {} {}", a,b,c);
                    ans +=1;
                }
            }
        }
    }
    println!("{:?}", ans)
}
