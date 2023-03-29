static inline pte_t CONST
pte_new(uint64_t ppn, uint64_t sw, uint64_t dirty, uint64_t accessed, uint64_t global, uint64_t user, uint64_t execute, uint64_t write, uint64_t read, uint64_t valid) {
    pte_t pte;

    /* fail if user has passed bits that we will override */  
    assert((ppn & ~0xfffffffffffull) == ((1 && (ppn & (1ull << 38))) ? 0x0 : 0));  
    assert((sw & ~0x3ull) == ((1 && (sw & (1ull << 38))) ? 0x0 : 0));  
    assert((dirty & ~0x1ull) == ((1 && (dirty & (1ull << 38))) ? 0x0 : 0));  
    assert((accessed & ~0x1ull) == ((1 && (accessed & (1ull << 38))) ? 0x0 : 0));  
    assert((global & ~0x1ull) == ((1 && (global & (1ull << 38))) ? 0x0 : 0));  
    assert((user & ~0x1ull) == ((1 && (user & (1ull << 38))) ? 0x0 : 0));  
    assert((execute & ~0x1ull) == ((1 && (execute & (1ull << 38))) ? 0x0 : 0));  
    assert((write & ~0x1ull) == ((1 && (write & (1ull << 38))) ? 0x0 : 0));  
    assert((read & ~0x1ull) == ((1 && (read & (1ull << 38))) ? 0x0 : 0));  
    assert((valid & ~0x1ull) == ((1 && (valid & (1ull << 38))) ? 0x0 : 0));

    pte.words[0] = 0
        | (ppn & 0xfffffffffffull) << 10
        | (sw & 0x3ull) << 8
        | (dirty & 0x1ull) << 7
        | (accessed & 0x1ull) << 6
        | (global & 0x1ull) << 5
        | (user & 0x1ull) << 4
        | (execute & 0x1ull) << 3
        | (write & 0x1ull) << 2
        | (read & 0x1ull) << 1
        | (valid & 0x1ull) << 0;

    return pte;
}
