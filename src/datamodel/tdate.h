#ifndef TDATE_H
    #define TDATE_H TDATE_H

    #include <iostream>
    #include <fstream>

    using namespace std;



    class tdate
    {
        int day;
        int month;
        int year;

        public:
            tdate();
            tdate(int d, int m, int y);

            friend ostream &operator<< (ostream &, const tdate &);

            int get_day()   const   {return day;}
            int get_month() const   {return month;}
            int get_year()  const   {return year;}

            void set_date(int d, int m, int y);
            void set_today();
    };

#endif
