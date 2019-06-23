#ifndef SINGELTONS_H
    #define SINGELTONS_H

    #include"main_controller.h"
    #include "calender_manager.h"
    #include "database.h"
    #include "input_controller.h"
    #include "output_controller.h"
    #include "task_manager.h"

    extern mainController mainCntrl;
    extern task_manager tm_c;
    extern input_controller ic_c;

#endif // SINGELTONS_H
