#include <iostream>
#include <list>

class interest_rate {
private:
    float Interest_Rate;
    float Periods_Until_Maturity;
    std::string Input_Type;
    std::string Output_Type;

public:

    // constructor
    interest_rate(float rate, std::string input, std::string output, float periods) {
        Interest_Rate = rate;
        Input_Type = input;
        Output_Type = output;
        Periods_Until_Maturity = periods;
    }

    // functions



};