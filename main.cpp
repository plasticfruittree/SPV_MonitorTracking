#include <iostream>
#include "modules/interest_rate.h"


int main() {

    interest_rate Rate1 (0.25, "APR", "APY", 2);
    std::cout << Rate1.getInputType() << std::endl;
    std::cout << Rate1.apr_to_apy() << std::endl;
}
