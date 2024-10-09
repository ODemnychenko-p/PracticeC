//
// Created by O.Demnychenko on 10/9/2024.
//

#include <filesystem>
#include <numeric>
#include <iostream>

namespace fs = std::filesystem;

std::uintmax_t get_directory_size(fs::path const& dir, bool const follow_symlinks = false)
{
    auto iterator = fs::recursive_directory_iterator(dir, follow_symlinks ? fs::directory_options::follow_directory_symlink:
    fs::directory_options::none);

    return std::accumulate(fs::begin(iterator), fs::end(iterator), 0ull,
                           [](std::uintmax_t total, const fs::directory_entry& entry) {
                               return total + (fs::is_regular_file(entry) ? fs::file_size(entry.path()) : 0);
                           });
}

static void task_number_4()
{
    std::string path;
    std::cout << "Path: ";
    std::cin >> path;
    std::cout << "Size: " << get_directory_size(path) << std::endl;
}