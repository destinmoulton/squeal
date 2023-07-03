//
// Created by destin on 7/3/23.
//

#ifndef SQUEAL_GUI_MODALS_H
#define SQUEAL_GUI_MODALS_H


class GUIModals {

public:

    static char *open_modal_connect_to_db();

    static void open_modal_message_box(char message_title[100], char message[512]);

private:
};


#endif //SQUEAL_GUI_MODALS_H
