//
// Created by destin on 7/3/23.
//

#ifndef SQUEAL_GUI_MODALS_H
#define SQUEAL_GUI_MODALS_H

#include <vector>
#include <cstdio>
#include <format>
#include <string>
#include "imgui/imgui.h"
#include "constants.hpp"

enum SQ_Message_Type {
    Error,
    Info,
    Success
};
struct SQ_Modal_Message {
    int id;
    SQ_Message_Type type;
    std::string msg;
};

class GUIModals {

public:

    GUIModals();

    ~GUIModals();

    void run();

    void open_modal_connect_to_db();

    void show_top_message();

    char *get_db_filename();

    bool is_db_filename_set();

    void add_message(SQ_Message_Type type, std::string msg);

private:
    bool is_connect_popup_open = false;
    bool has_db_filename = false;
    std::vector<SQ_Modal_Message> m_messages;
    int m_message_id = 0;
    char *m_id_connect;
    char m_db_filename[SQ_DB_FILENAME_SIZE] = "";


    void reg_modal_connect_to_db();

    void reg_modal_message_box();
};


#endif //SQUEAL_GUI_MODALS_H
