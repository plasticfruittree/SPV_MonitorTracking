#include <string>

#ifndef SPV_MONITORTRACKING_INTERESTRATE_H
#define SPV_MONITORTRACKING_INTERESTRATE_H
#endif //SPV_MONITORTRACKING_INTERESTRATE_H

using namespace std;
class InterestRate {

private:
    double Rate;
    double Period;


public:

    //constructor

    InterestRate (double rate, double period) {
        Rate = rate;
        Period = period;
    }

    // setter and getters

    [[nodiscard]] double getRate() const {
        return Rate;
    }

    void setRate(double rate) {
        Rate = rate;
    }

    [[nodiscard]] double getPeriod() const {
        return Period;
    }

    void setPeriod(double period) {
        Period = period;
    }


    // function

    double rate_to_acr(double rate, double period) {
        return period * log(1+ (rate/period));
    }

    double acr_to_rate(double rate, double period) {
        return period * (exp(rate/period) - 1);
    }


};
