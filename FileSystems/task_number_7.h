//
// Created by O.Demnychenko on 10/10/2024.
//

#include <filesystem>
#include <fstream>
#include <uuid.h>

namespace  fs = std::filesystem;
class logger {
    fs::path logpath;
    std::ofstream logfile;
public:
    logger() {
        auto name = uuids::to_string(uuids::uuid_random_generator{}());
        logpath = fs::temp_directory_path() / (name + ".temp");
        logfile.open(logpath.c_str(), std::ios::out | std::ios::trunc);
    }

    ~logger() noexcept {
        try {
            if (logfile.is_open()) {
                logfile.close();
            }
            if (!logpath.empty()) {
                fs::remove(logpath);
            }
        }
        catch (...) {}
    }

    void persist(fs::path const &path)
    {
        logfile.close();
        fs::rename(logpath, path);
        logpath.clear();
    }

    logger& operator<<(std::string_view message)
    {
        logfile << message.data() << '\n';
        return *this;
    }
};

static void task_number_7()
{
    logger log;
    try{
        log << "this is a line" << "and this is another one";
        throw std::runtime_error("error");
    }
    catch(...)
    {
        log.persist(R"(lastlog.txt)");
    }
}