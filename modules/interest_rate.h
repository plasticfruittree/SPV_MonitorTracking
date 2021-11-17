#ifndef SPV_MONITORTRACKING_INTEREST_RATE_H
#define SPV_MONITORTRACKING_INTEREST_RATE_H

#endif //SPV_MONITORTRACKING_INTEREST_RATE_H

#include <cmath>
#include <iostream>
#include <chrono>
#include <ctime>
#include <list>


class InterestRate {
private:
    float Interest_Rate;
    float Periods;
    std::string Input_Type;
    std::string Output_Type;

public:

    // setter and getter

    [[nodiscard]] float getInterestRate() const {
        return Interest_Rate;
    }

    void setInterestRate(float interestRate) {
        Interest_Rate = interestRate;
    }

    [[nodiscard]] float getPeriodsUntilMaturity() const {
        return Periods;
    }

    void setPeriodsUntilMaturity(float periodsUntilMaturity) {
        Periods = periodsUntilMaturity;
    }

    [[nodiscard]] const std::string &getInputType() const {
        return Input_Type;
    }

    void setInputType(const std::string &inputType) {
        Input_Type = inputType;
    }

    [[nodiscard]] const std::string &getOutputType() const {
        return Output_Type;
    }

    void setOutputType(const std::string &outputType) {
        Output_Type = outputType;
    }



    // constructor ---------------------------------------------------------------------------------

    InterestRate(float rate, std::string input , std::string output, float periods) {
        Interest_Rate = rate;
        Input_Type = input;
        Output_Type = output;
        Periods = periods;
    }

    // conversion functions --------------------------------------------------------------------------





};

class MoneyMarket : public InterestRate {
private:
    float present_value, addon_rate, days_until_maturity;
    int days_in_year;

public:


};

// help documentation

void help_periods() {
    std::list<std::string> period_type = {"annual | 1, semiannual | 2, quarterly | 4, monthly | 12, "
                                          "weekly | 52, daily | 365"};
    std::cout << "---------------" << std::endl;
    std::cout << "Type | Periods" << std::endl;
    std::cout << "---------------" << std::endl;

    for (std::string type: period_type) {
        std::cout << type << std::endl;

    }
}