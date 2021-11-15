#ifndef SPV_MONITORTRACKING_INTEREST_RATE_H
#define SPV_MONITORTRACKING_INTEREST_RATE_H

#endif //SPV_MONITORTRACKING_INTEREST_RATE_H

#include <cmath>
#include <iostream>


class interest_rate {
private:
    float Interest_Rate;
    float Periods_Until_Maturity;
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
        return Periods_Until_Maturity;
    }

    void setPeriodsUntilMaturity(float periodsUntilMaturity) {
        Periods_Until_Maturity = periodsUntilMaturity;
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

    interest_rate(float rate, std::string input , std::string output, float periods) {
        Interest_Rate = rate;
        Input_Type = input;
        Output_Type = output;
        Periods_Until_Maturity = periods;
    }

    // conversion functions --------------------------------------------------------------------------

    float apr_to_apr() {
        if (Input_Type == "APR" and Output_Type == "APR")
        {
            return Interest_Rate;

        }
        else return -1;
    }

    float apr_to_apy() {
        if (Input_Type == "APR" and Output_Type == "APY")
        {
            return (1 + Interest_Rate/Periods_Until_Maturity) * Periods_Until_Maturity - 1;

        }
        else return -1;
    }

    float apr_to_acr() {
        if (Input_Type == "APR" and Output_Type == "ACR")
        {
            float apy_rate = (1 + Interest_Rate/Periods_Until_Maturity) * Periods_Until_Maturity - 1;
            return std::log(1 + apy_rate) * Periods_Until_Maturity;
        }
        else return -1;
    }

    float apy_to_apr() {
        if (Input_Type == "APY" and Output_Type == "APR")
        {
            return (pow(1 + Interest_Rate, 1/Periods_Until_Maturity) - 1) * Periods_Until_Maturity;

        }
        else return -1;
    }

    float apy_to_acr() {
        if (Input_Type == "APY" and Output_Type == "ACR")
        {
            return Periods_Until_Maturity * log(1 + (Interest_Rate/Periods_Until_Maturity));

        }
        else return -1;
    }

    float acr_to_apy() {
        if (Input_Type == "ACR" and Output_Type == "APY")
        {
            return Periods_Until_Maturity * (exp(Interest_Rate/Periods_Until_Maturity) - 1);

        }
        else return -1;
    }

    float acr_to_apr() {
        if (Input_Type == "ACR" and Output_Type == "APR") {
            float result = acr_to_apy();
            return (pow(result + 1, 1/Periods_Until_Maturity) - 1) * Periods_Until_Maturity;


        }
        else return -1;
    }

};
