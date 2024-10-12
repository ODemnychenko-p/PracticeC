//
// Created by O.Demnychenko on 10/10/2024.
//

#include <filesystem>
#include <vector>
#include <regex>
#include <iostream>

namespace fs = std::filesystem;

std::vector<fs::directory_entry> find_files(fs::path const& path, std::string_view regex)
{
    std::vector<fs::directory_entry> result;
    std::regex rx(regex.data());

    std::copy_if(
            fs::recursive_directory_iterator(path),
            fs::recursive_directory_iterator(),
            std::back_inserter(result),
            [&rx](fs::directory_entry const& entry)
            {
                return std::regex_match(entry.path().filename().string(), rx);
            });
    return result;
}

static void task_number_6(){
    auto dir = fs::temp_directory_path();
    auto pattern = R"(wct[0-9a-zA-Z]{3}\.tmp)";
    auto result = find_files(dir, pattern);
    for(auto const& entry: result){
        std::cout << entry.path().string() << std::endl;
    }
}