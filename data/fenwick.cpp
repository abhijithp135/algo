template <typename T> class FenwickTree {
public:
  vector<T> fenw;
  int n;
  int pw;

  FenwickTree() : n(0) {}
  FenwickTree(int n_) : n(n_) {
    fenw.resize(n);
    pw = bit_floor(unsigned(n));
  }

  void Modify(int x, T v) {
    assert(0 <= x && x < n);
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  T Query(int x) {
    assert(0 <= x && x <= n);
    T v{};
    while (x > 0) {
      v += fenw[x - 1];
      x &= x - 1;
    }
    return v;
  }

  // Returns the length of the longest prefix with sum <= c
  // want first index with at least c? call this with c-1
  // The output can be directly used in the original array 0 indexed array
  int MaxPrefix(T c) {
    T v{};
    int at = 0;
    for (int len = pw; len > 0; len >>= 1) {
      if (at + len <= n) {
        auto nv = v;
        nv += fenw[at + len - 1];
        // If sum < c, then replace < with <=
        if (!(c < nv)) {
          v = nv;
          at += len;
        }
      }
    }
    assert(0 <= at && at <= n);
    return at;
  }
};
