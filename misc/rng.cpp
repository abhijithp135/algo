mt19937_64
    rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng((uint64_t)new char);
