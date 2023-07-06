//
// Created by destin on 6/27/23.
//

#ifndef SQUEAL_GUI_H
#define SQUEAL_GUI_H


#include <GLFW/glfw3.h> // system OpenGL headers
#include "sqlitewrap.h"
#include "gui_modals.h"

struct GUIDB {
    SQLiteWrap db;
    bool is_connected = false;
    bool has_tables_list = false;
};

class GUI {

public:
    GUI();

    ~GUI();

    int run();


private:
    GUIDB m_db;
    GUIModals m_guimodals;

    void win_list_sqlite_tables();
    //static GLFWerrorfun glfw_error_callback(int error, const char *description);
};


#endif //SQUEAL_GUI_H
