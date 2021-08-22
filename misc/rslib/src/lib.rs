pub trait ExtSlice<T> {
    fn lower_bound(&self, x: &T) -> usize;
    fn upper_bound(&self, x: &T) -> usize;
}

impl<T: Ord> ExtSlice<T> for [T] {
    fn lower_bound(&self, x: &T) -> usize {
        let mut l = 0;
        let mut r = self.len();
        while l != r {
            let c = (l + r) / 2;
            if &self[c] < x {
                l = c + 1;
            } else {
                r = c;
            }
        }
        return l;
    }
    fn upper_bound(&self, x: &T) -> usize {
        let mut l = 0;
        let mut r = self.len();
        while l != r {
            let c = (l + r) / 2;
            if &self[c] <= x {
                l = c + 1;
            } else {
                r = c;
            }
        }
        l
    }
}

#[test]
fn test_binary_search() {
    let t = vec![1, 2, 4, 8, 16, 32, 64, 64, 64, 64, 128, 256];
    assert_eq!(t.lower_bound(&-1), 0);
    assert_eq!(t.lower_bound(&7), 3);
    assert_eq!(t.lower_bound(&8), 3);
    assert_eq!(t.lower_bound(&9), 4);
    assert_eq!(t.lower_bound(&64), 6);
    assert_eq!(t.lower_bound(&1024), 12);
    assert_eq!(t.upper_bound(&-1), 0);
    assert_eq!(t.upper_bound(&7), 3);
    assert_eq!(t.upper_bound(&8), 4);
    assert_eq!(t.upper_bound(&9), 4);
    assert_eq!(t.upper_bound(&64), 10);
    assert_eq!(t.upper_bound(&1024), 12);
}
