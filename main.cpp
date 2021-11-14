#include <iostream>
#include <list>
#include "modules/interest_rate.h"


int main() {

    interest_rate Rate1 (0.25, "APR", "APR", 2);

    std::cout << Rate1.getInputType() << std::endl;



}
