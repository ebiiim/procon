use proconio::input;

fn main() {
    input! {
        a: i64,
        b: i64,
        c: i64,
    }

    let mut ans = c-(a-b);
    if ans < 0{
        ans = 0
    }
    println!("{}", ans)
}
