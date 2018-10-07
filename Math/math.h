#include <math.h>

namespace math {
// Primes
const int PRIMES_LENGTH = 168;
const int PRIMES[PRIMES_LENGTH] = {
#include "./primes.arr"
};

// max number
const int MAX_INT = 0;
const long MAX_LONG = 0;
const long long MAX_LONG_LONG = 0;
const long long int MAX_LONG_LONG_INT = 0;
const unsigned long long int MAX_UNSIGNED_LONG_LONG_INT = 0;

#include "./pow.h"

#include "./cbrt.h"
#include "./random.h"
#include "./sqrt.h"

#include "./gcd.h"
#include "./modinv.h"
#include "./prime.h"
}; // namespace math
