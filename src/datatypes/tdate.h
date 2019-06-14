#ifndef TDATE_H
    #define TDATE_H TDATE_H

    #include <iostream>
    #include <fstream>

    using namespace std;



    class TDate
    {
        int day;
        int month;
        int year;

        public:
            TDate(); 
            TDate(int d, int m, int y);
            
            friend ostream &operator<< (ostream &, const TDate &);

            int get_day()   const   {return day;}
            int get_month() const   {return month;}
            int get_year()  const   {return year;}

            void set_date(int d, int m, int y);
            void set_today();
            
            void load(ifstream &);
    };

#endif
