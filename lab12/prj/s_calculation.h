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

// 12.1
class ClassLab12_Virchenko {
private:
    double width;
    double height;
    std::string material;

public:
    ClassLab12_Virchenko(double w = 1.0, double h = 1.0, std::string mat = "Paperback");

    bool setWidth(double w);
    bool setHeight(double h);
    void setMaterial(std::string mat);

    double getWidth() const { return width; }
    double getHeight() const { return height; }
    std::string getMaterial() const;

    double calculateArea() const;
};

#endif
