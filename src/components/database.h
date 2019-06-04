#ifndef DATABASE_H
    #define DATABASE_H

    class database_intf
    {
        public:

            virtual ~database_intf();

            virtual void save_one_task() = 0;
            virtual void get_LUT() = 0;
            virtual void set_ID() = 0;
            virtual void load_all() = 0;
    };

#endif
