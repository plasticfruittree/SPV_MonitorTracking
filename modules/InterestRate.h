#include <string>
#include <cmath>

#ifndef SPV_MONITORTRACKING_INTERESTRATE_H
#define SPV_MONITORTRACKING_INTERESTRATE_H
#endif //SPV_MONITORTRACKING_INTERESTRATE_H

using namespace std;
class InterestRate {

private:
    double Rate;
    double Period;
    string type;


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

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        InterestRate::type = type;
    }


    // function

    double mrate_to_acr(double rate, double period)
    {
        setType("ACR");
        return period * log(1+ (rate/period));
    }

    double acr_to_mrate(double rate, double period)
    {
        setType("Compound Period");
        return period * (exp(rate/period) - 1);
    }

};

class MoneyMarketRate{
private:
    //different rates
    double Addon_rate, Discount_rate;

    //future and present values
    double Present_value, Future_value;

    // annualized period
    double Days_in_year, Days_til_maturity;
    double annualized_period;


public:

    // constructors
    MoneyMarketRate(double rate, double value, double days_in_year, double days_til_maturity)
    {

    }



};