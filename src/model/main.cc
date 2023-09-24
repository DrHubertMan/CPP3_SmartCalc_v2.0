#include <iostream>
#include "deposit.h"


int main() {
    s21::DepositCalc calc(10000, 12, 5.00, 0.1, s21::Periodicity::kMonthly, true);
    calc.AddDeposit(3, 500.0);
    calc.AddWithdrawal(8, 200.0);
    std::cout << calc.CalculateInterest() << std::endl;
    std::cout << calc.CalculateTax() << std::endl;
    std::cout << calc.CalculateFinalAmount() << std::endl;
    return 0;
}