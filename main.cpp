#include <iostream>
#include "modules/interest_rate.h"


int main() {

    InterestRate Rate1 (0.10, "APR", "APY", 2);
    std::cout << Rate1.apr_to_apy();
}
