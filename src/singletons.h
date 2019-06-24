#ifndef SINGLETONS_H
    #define SINGLETONS_H

    #include "main_controller.h"
    #include "calender_manager.h"
    #include "database.h"
    #include "input_controller.h"
    #include "output_controller.h"
    #include "task_manager.h"

    extern mainController mainCntrl;
    extern calender_manager cm_c;
    extern database db_c;
    extern input_controller ic_c;
    extern output_controller oc_c;
    extern task_manager tm_c;

#endif // SINGELTONS_H
