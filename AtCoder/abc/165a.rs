#![allow(unused_imports)]
#![allow(unused_macros)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(unused_assignments)]
use proconio::input;
use proconio::marker::Usize1;
use std::collections::*;
use std::cmp::*;
use std::f64::consts::*;

const MOD: u64 = 1000000007;
const INF: usize = std::usize::MAX / 4;

fn main() {
    input! {
        K: i64,
        A: i64,
        B: i64,
    }

    for i in A..B+1 {
        if i % K == 0 {
            println!("OK");
            return;
        }
    }

    println!("NG")
}
