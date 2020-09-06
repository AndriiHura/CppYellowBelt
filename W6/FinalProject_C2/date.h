#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include<memory>

using namespace std;



class Date {
public:
    // ����������� ����������� ����������, ���� ��� ��������� �����������
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& stream);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);
