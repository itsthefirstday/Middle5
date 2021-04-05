//
//  main.cpp
//  Middle5
//
//  Created by Юрий Филиппов on 05.04.2021.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Fraction
{
public:
    Fraction(int numenator, int denominator)
    {
        if (!denominator)
            throw std::runtime_error("Ошибка: Знаменатель равен 0\n");
        
        m_numenator = numenator;
        m_denominator = denominator;
    }
private:
    int m_numenator, m_denominator;
};

int main(int argc, const char * argv[]) {
    int a, b;
    cin.exceptions(std::ios_base::failbit);
    while (1)
    {
        cout << "Введите два числа\n";
        try {
            cin >> a >> b;
            break;
        } catch (std::exception& e) {
            cout << "Вы ввели некоректные данные" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    cout << a << ' ' << b << endl;
    try {
        Fraction f(a, b);
    } catch (std::runtime_error& e) {
        cout << e.what();
    }
    return 0;
}
