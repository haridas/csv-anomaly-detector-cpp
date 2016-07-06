#ifndef BINSELECTOR
#define BINSELECTOR

enum BIN_SELECTOR {
    DIGIT,
    ALPHA_LOWER,
    ALPHA_UPPER,
    AT_CHAR,
    SPACE,
    SEMI_COLON,
    COLON,

    // Special value to know the size of the bin, keep it last always.
    BIN_SELECTOR_SIZE
};


#endif // BINSELECTOR

