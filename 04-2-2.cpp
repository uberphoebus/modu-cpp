#include <iostream>

class Date {
  int year_;
  int month_;
  int day_;

public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddYear(int inc);
  void AddMonth(int inc);

  int GetCurrentMonthTotalDays(int year, int month);
  void ShowDate();

  // constructor : set & init
  Date(int year, int month, int day) {
    std::cout << "call constructor (not default)" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }

  // default constructor : overloading
  Date() {
    std::cout << "call default constructor" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }
};

void Date::SetDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}

void Date::AddDay(int inc) {
  while (true) {
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      AddMonth(1);
    }
  }
}

void Date::AddMonth(int inc) {
  AddYear((inc + month_ - 1) / 12);
  month_ += (inc % 12);
  month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

int Date::GetCurrentMonthTotalDays(int year, int month) {
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) {
    return month_day[month - 1];
  } else if (year % 4 == 0 && year % 100 != 0) {
    return 29; // 윤년
  } else {
    return 28;
  }
}

void Date::ShowDate() {
  std::cout << "today is : " << year_ << "/" << month_ << "/" << day_
            << std::endl;
}

int main() {
  // no constructor
  // Date day;
  // day.SetDate(2011, 3, 1);

  // constructor
  Date day = Date(201, 3, 1); // Date day(2011, 3, 1);
  day.ShowDate();

  day.AddDay(30);
  day.ShowDate();

  day.AddDay(2000);
  day.ShowDate();

  day.SetDate(2012, 1, 31); // 윤년
  day.AddDay(29);
  day.ShowDate();

  day.SetDate(2012, 8, 4);
  day.AddDay(2500);
  day.ShowDate();

  Date day1 = Date();      // default constructor
  Date day2(2012, 10, 31); // constructor
  day1.ShowDate();
  day2.ShowDate();
  return 0;
}