#ifndef DATABASE_INTF_H
#define DATABASE_INTF_H

class database_intf
{
    virtual ~database_intf();

    /**
     * @brief loadFile läd alle Daten aus File
     */
    virtual void loadFile() = 0;

    /**
     * @brief storeFile speichert alle Daten in File
     */
    virtual void storeFile() = 0;
};

#endif // DATABASE_INTF_H
