//
// Created by destin on 7/3/23.
//

#include "imgui/imgui.h"
#include "gui_modals.h"


void GUIModals::open_modal_message_box(char *title, char *message) {

    if (ImGui::BeginPopupModal(title, NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text(message);

        // Always center this window when appearing
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        ImVec2 button_size(ImGui::GetFontSize() * 7.0f, 0.0f);
        if (ImGui::Button("Ok", button_size)) {
            ImGui::CloseCurrentPopup();
            //connect_to_db(filename);
        }
        ImGui::EndPopup();
    }
    ImGui::OpenPopup(title);
}

// Connect to db text input modal
char *GUIModals::open_modal_connect_to_db() {
    char filename[255];
    if (ImGui::BeginPopupModal("Connect to DB", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {

        ImGui::Text("DB Filename:");
        ImGui::SameLine();
        ImGui::InputText("##dbfilename", filename, IM_ARRAYSIZE(filename));

        // Always center this window when appearing
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        ImVec2 button_size(ImGui::GetFontSize() * 7.0f, 0.0f);
        if (ImGui::Button("Connect", button_size)) {
            ImGui::CloseCurrentPopup();
            return filename;
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel", button_size)) {
            ImGui::CloseCurrentPopup();
            return nullptr;
        }
        ImGui::EndPopup();
    }
    ImGui::OpenPopup("Connect to DB");
}




