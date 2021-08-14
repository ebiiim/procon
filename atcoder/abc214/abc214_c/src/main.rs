#![allow(non_snake_case, unused_variables, unused_mut)]

use proconio::input;

fn main() {
    input! {
        N: i64,
        // A: i64,
        // B: i64,
        // C: i64,
        mut S: [i64; N],
        mut T: [i64; N],
    }

    let mut min_idx = 0;
    // let mut min_idxS = 20000000000;
    for i in 0..N as usize {
        if T[min_idx] > T[i] {
            min_idx = i;
            // min_idxS = S[i] as i64;
            // println!("min_idx{:?}", min_idx);
        }
    }

    // println!("min_idx!{:?}", min_idx);

    let min_idx = min_idx as i64;
    for i in 0..N as usize {
        let mut nowidx = (min_idx + (i as i64)) % N;
        if nowidx < 0 {
            nowidx = N + nowidx;
        }
        let mut previdx = (min_idx + (i as i64) - 1) % N;
        if previdx < 0 {
            previdx = N + previdx;
        }

        let nowidx = nowidx as usize;
        let previdx = previdx as usize;
        if i == 0 {
            continue;
        }
        if T[nowidx] > (T[previdx] + S[previdx]) {
            T[nowidx] = T[previdx] + S[previdx];
        }
        // println!("now_idx{:?}", nowidx);
        // println!("S {:?}\nT {:?}", S,T);

        // println!("now_idx{:?} {}", nowidx, T[nowidx]);
        // println!("prev_idx{:?} {}", previdx, T[previdx] + S[previdx]);
    }

    for i in 0..N as usize {
        let mut nowidx = (min_idx + (i as i64)) % N;
        if nowidx < 0 {
            nowidx = N + nowidx;
        }
        let mut previdx = (min_idx + (i as i64) - 1) % N;
        if previdx < 0 {
            previdx = N + previdx;
        }

        let nowidx = nowidx as usize;
        let previdx = previdx as usize;
        if i == 0 {
            continue;
        }

        // println!("now_idx{:?} {}", nowidx, T[nowidx]);
        // println!("prev_idx{:?} {}", previdx, T[previdx] + S[previdx]);
        if T[nowidx] > (T[previdx] + S[previdx]) {
            T[nowidx] = T[previdx] + S[previdx];
        }
    }

    for i in 0..N as usize {
        println!("{:?}", T[i]);
    }
}
