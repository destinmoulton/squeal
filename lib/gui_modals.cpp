//
// Created by destin on 7/3/23.
//


#include "gui_modals.h"


GUIModals::GUIModals() {

}

GUIModals::~GUIModals() {
    m_messages.clear();
}

void GUIModals::run() {

    // Show messages first
    if (m_messages.size() > 0) {
        show_top_message();
    } else {
        // Other modals
        if (is_newtable_popup_open) {
            reg_modal_newtable();
            if (!ImGui::IsPopupOpen(m_id_newtable)) {
                ImGui::OpenPopup(m_id_newtable);
            }
        }
        if (is_connect_popup_open) {
            reg_modal_connect_to_db();
            if (!ImGui::IsPopupOpen(m_id_connect)) {
                ImGui::OpenPopup(m_id_connect);
            }
        }
    }
}

void GUIModals::show_top_message() {

    SQ_Modal_Message msg = m_messages[0];

    char id[12];
    std::cout << "message text" << msg.msg << std::endl;
    std::sprintf(id, "%d", msg.id);
    if (!ImGui::IsPopupOpen(id)) {
        ImGui::OpenPopup(id);
        m_messages.erase(m_messages.begin());
    }
    if (ImGui::BeginPopupModal(id, nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("%s", msg.msg.c_str());

        // Always center this window when appearing
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        ImVec2 button_size(ImGui::GetFontSize() * 7.0f, 0.0f);
        if (ImGui::Button("Ok", button_size)) {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

// Connect to db text input modal
void GUIModals::open_modal_connect_to_db() {
    is_connect_popup_open = true;
}

void GUIModals::open_modal_newtable() {
    is_newtable_popup_open = true;
}

void GUIModals::reg_modal_connect_to_db() {

    if (ImGui::BeginPopupModal(m_id_connect, nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {

        ImGui::Text("DB Filename:");
        ImGui::SameLine();
        ImGui::InputText("##dbfilename", m_db_filename, SQ_DB_FILENAME_SIZE);

        // Always center this window when appearing
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        ImVec2 button_size(ImGui::GetFontSize() * 7.0f, 0.0f);
        if (ImGui::Button("Connect", button_size)) {
            if (strcmp(m_db_filename, "") != 0) {
                ImGui::CloseCurrentPopup();
                is_connect_popup_open = false;
                has_db_filename = true;
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel", button_size)) {
            ImGui::CloseCurrentPopup();
            is_connect_popup_open = false;
            clear_db_filename();
        }
        ImGui::EndPopup();
    }
}

void GUIModals::reg_modal_newtable() {

    if (ImGui::BeginPopupModal(m_id_newtable, nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {

        ImGui::Text("New Table Name:");
        ImGui::SameLine();
        ImGui::InputText("##dbfilename", m_db_newtable_name, SQ_DB_FILENAME_SIZE);

        // Always center this window when appearing
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        ImVec2 button_size(ImGui::GetFontSize() * 7.0f, 0.0f);
        if (ImGui::Button("Create Table", button_size)) {
            if (strcmp(m_db_filename, "") != 0) {
                ImGui::CloseCurrentPopup();
                is_newtable_popup_open = false;
                has_newtable_name = true;
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel", button_size)) {
            ImGui::CloseCurrentPopup();
            is_newtable_popup_open = false;
            clear_db_newtable_name();
        }
        ImGui::EndPopup();
    }
}

char *GUIModals::get_db_filename() {
    return m_db_filename;
}

bool GUIModals::is_db_filename_set() {
    return has_db_filename;
}

bool GUIModals::is_db_newtable_name_set() {
    return has_db_filename;
}

void GUIModals::clear_db_filename() {
    strcpy(m_db_filename, "");
}

void GUIModals::clear_db_newtable_name() {
    strcpy(m_db_newtable_name, "");
}

void GUIModals::add_message(SQ_Message_Type type, std::string msg) {
    m_messages.push_back(SQ_Modal_Message{m_message_id, type, msg});
    m_message_id++;
}


