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

    double mrate_to_acr(double rate, double period) {
        return period * log(1+ (rate/period));
    }

    double acr_to_mrate(double rate, double period) {
        return period * (exp(rate/period) - 1);
    }

};

class MoneyMarketRates: public InterestRate {
private:
    double Addon_rate;
    double Discount_rate;
    double Present_value;
    double Future_value;
    double Days_in_year;


public:
    // constructors
    MoneyMarketRate(double value, double addon_rate, double days) {
        Present_value = value;
        Future_value = value;
        Addon_rate = addon_rate;
        Discount_rate = addon_rate;
        Days_in_year = days;
    }

    double Addon_fv()
    {
        return present_value + (present_value + addon)
    }








};
