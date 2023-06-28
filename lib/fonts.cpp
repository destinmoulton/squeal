//
// Created by destin on 6/26/23.
//

#include "fonts.h"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<std::string> Fonts::find_fonts() {
    std::vector<std::string> paths = {
            "/usr/share/fonts",
            "/usr/local/share/fonts",
            "~/.fonts"
    };

    std::vector<std::string> fonts;

    for (std::string path: paths) {

        std::cout << "--- " << path << " ---" << std::endl;
        if (fs::exists(path)) {

            for (const fs::directory_entry &dir_entry: fs::recursive_directory_iterator(path)) {
                if (dir_entry.path().extension() == ".ttf") {
                    fonts.push_back(dir_entry.path());
                    std::cout << dir_entry.path() << std::endl;
                }
            }
        }
    }

    return fonts;

}
