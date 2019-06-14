#ifndef TTIME_H
    #define TTIME_H TTIME_H

    #include <iostream>
    #include <fstream>

    using namespace std;



    class TTime
    {
        int hour;
        int minute;
        int second;

        public:
            TTime();
            TTime(int h, int m, int s = 0);
            
            friend ostream &operator<< (ostream &, const TTime &);
            
            int get_hour()   const  {return hour;}
            int get_minute() const  {return minute;}
            int get_second() const  {return second;}

            void set_time(int h, int m, int s = 0);
            void set_current_time();

            void load(ifstream &);
    };

#endif
