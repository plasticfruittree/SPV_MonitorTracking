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

class MoneyMarketAddon
{

private:
    double Addon_rate;
    double Present_value, Future_value;
    double Days_in_year, Days_til_maturity, Annualized_period;

public:
    // setter and getter
    double getAddonRate() const {
        return Addon_rate;
    }

    void setAddonRate(double addonRate) {
        Addon_rate = addonRate;
    }

    double getPresentValue() const {
        return Present_value;
    }

    void setPresentValue(double presentValue) {
        Present_value = presentValue;
    }

    double getFutureValue() const {
        return Future_value;
    }

    void setFutureValue(double futureValue) {
        Future_value = futureValue;
    }

    double getDaysInYear() const {
        return Days_in_year;
    }

    void setDaysInYear(double daysInYear) {
        Days_in_year = daysInYear;
    }

    double getDaysTilMaturity() const {
        return Days_til_maturity;
    }

    void setDaysTilMaturity(double daysTilMaturity) {
        Days_til_maturity = daysTilMaturity;
    }

    double getAnnualizedPeriod() const {
        return Annualized_period;
    }

    void setAnnualizedPeriod(double annualizedPeriod) {
        Annualized_period = annualizedPeriod;
    }


    // constructor
    MoneyMarketAddon(double rate, double present_value, double future_value, double days_in_year, double days_til_maturity)
    {
        Addon_rate = rate;
        Present_value = present_value;
        Future_value = future_value;
        Days_in_year = days_in_year;
        Days_til_maturity = days_til_maturity;
        Annualized_period = days_in_year / days_til_maturity;
    }


    // functions
    double futureValue()
    {
        double addon_fv =  Present_value + (Present_value * Addon_rate * Annualized_period);
        setFutureValue(addon_fv);
        return addon_fv;
    }

    double presentValue()
    {
        double addon_pv = Future_value / (1 + (Addon_rate * Annualized_period));
        setPresentValue(addon_pv);
        return addon_pv;
    }

    double rate()
    {
        double rate_addon = Annualized_period * (Future_value / Present_value);
        setAddonRate(rate_addon);
        return rate_addon;

    }

};

class MoneyMarketDiscount {

private:
    double Discount_rate, Addon_rate;
    double Present_value, Future_value;
    double Days_in_year, Days_til_maturity, Annualized_period;


public:

    // setters and getters

    double getDiscountRate() const {
        return Discount_rate;
    }

    void setDiscountRate(double discountRate) {
        Discount_rate = discountRate;
    }

    double getPresentValue() const {
        return Present_value;
    }

    void setPresentValue(double presentValue) {
        Present_value = presentValue;
    }

    double getFutureValue() const {
        return Future_value;
    }

    void setFutureValue(double futureValue) {
        Future_value = futureValue;
    }

    double getDaysInYear() const {
        return Days_in_year;
    }

    void setDaysInYear(double daysInYear) {
        Days_in_year = daysInYear;
    }

    double getDaysTilMaturity() const {
        return Days_til_maturity;
    }

    void setDaysTilMaturity(double daysTilMaturity) {
        Days_til_maturity = daysTilMaturity;
    }

    double getAnnualizedPeriod() const {
        return Annualized_period;
    }

    void setAnnualizedPeriod(double annualizedPeriod) {
        Annualized_period = annualizedPeriod;
    }

    double getAddonRate() const {
        return Addon_rate;
    }

    void setAddonRate(double addonRate) {
        Addon_rate = addonRate;
    }

    // constructors

    MoneyMarketDiscount(double rate, double present_value, double future_value, double days_in_year, double days_til_maturity)
    {
        Discount_rate = rate;
        Present_value = present_value;
        Future_value = future_value;
        Days_in_year = days_in_year;
        Days_til_maturity = days_til_maturity;
        Annualized_period = days_in_year / days_til_maturity;
    }

    // functions

    double present_value()
    {
       double pv = Future_value * (1 - (Discount_rate * Annualized_period));
       setPresentValue(pv);
       return pv;
    }

    double rate()
    {
        double rate = Annualized_period * ((Future_value - Present_value) / Future_value);
        setDiscountRate(rate);
        return rate;
    }

    double convertTo_addon()
    {
        double addon_rate = Days_in_year * Discount_rate / (Days_in_year * (Days_til_maturity * Discount_rate));
        setAddonRate(addon_rate);
        return addon_rate;
    }
};


