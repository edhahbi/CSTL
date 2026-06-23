#define IS_PRIMITIVE(x) _Generic((x), \
    _Bool: 1, \
    char: 1, \
    signed char: 1, \
    unsigned char: 1, \
    short: 1, \
    unsigned short: 1, \
    int: 1, \
    unsigned int: 1, \
    long: 1, \
    unsigned long: 1, \
    long long: 1, \
    unsigned long long: 1, \
    float: 1, \
    double: 1, \
    long double: 1, \
    default: 0 \
)

