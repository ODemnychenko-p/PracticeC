//
// Created by Oleksandr Demnychenko on 31.12.2024.
//

#include "iostream"
#include "fstream"
#include "exception"
#include "nlohmann/json.hpp"
#include "task_number_1.h"

using json = nlohmann::json;
movie_list deserialization(std::string_view filepath)
{
    movie_list movies;
    std::ifstream ifile(filepath.data());
    if(ifile.is_open())
    {
        json jdata;
        try {
            ifile >> jdata;
            if(jdata.is_object())
            {
                for(auto & element: jdata.at("movies"))
                {
                    movie m;

                    m.id = element.at("id").get<unsigned int>();
                    m.title = element.at("title").get<std::string>();
                    m.year = element.at("year").get<unsigned int>();
                    m.length = element.at("length").get<unsigned int>();

                    for(auto & role: element.at("cast"))
                    {
                        m.cast.push_back(casting_role{
                            role.at("star").get<std::string>(),
                                    role.at("name").get<std::string>()
                        });
                    }

                    for(auto & directors : element.at("directors"))
                    {
                        m.directors.push_back(directors);
                    }

                    for(auto & writer : element.at("writers"))
                    {
                        m.writers.push_back(writer);
                    }

                    movies.push_back(m);
                }
            }
        }
        catch (std::exception const& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
}

static void task_number_4()
{
    auto movies = deserialize("../PracticeC/Serialization/test/movies.json");
    assert(movies.size() == 2);
    assert(movies[0].title == "The Matrix");
    assert(movies[1].title == "Forest Gump");
}