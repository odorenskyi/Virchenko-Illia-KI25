#ifndef S_CALCULATION_H
#define S_CALCULATION_H

#include <string>
#include <vector>

double s_calculation(double x, double y, double z);

// Задача 9.1
void wind_calculation(int b, std::string& speed, std::string& description);

// Задача 9.2
void power_and_odds(int n, int m, double& n_pow_m, double& m_pow_n, std::vector<int>& odds);

// Задача 9.3
int binary_analysis(int N);

#endif
