//
// Created by Oleksandr Demnychenko on 31.12.2024.
//
#include "iostream"
#include "fstream"
#include "nlohmann/json.hpp"
#include "task_number_1.h"

using json = nlohmann::json;

void to_json(json& j, casting_role const& c)
{
    j = json{{"star", c.actor}, {"name", c.role}};
}

void to_json(json& j, movie const& m)
{
    j = json::object({
                             {"id", m.id},
                             {"title", m.title},
                             {"year", m.year},
                             {"length", m.length},
                             {"cast", m.cast},
                             {"directors", m.directors},
                             {"writers", m.writers}
    });
}

void serialize_json(movie_list const& movies, std::string_view filepath)
{
    json jdata{{"movies", movies}};
    std::ofstream ofile(filepath.data());
    if(ofile.is_open())
    {
        ofile << std::setw(2) << jdata << std::endl;
    }
}

static void task_number_3()
{
    movie_list movies
            {
                    {
                            11001, "The Matrix", 1999, 196,
                            {
                                    {"Keanu Reeves", "Neo"},
                                    {"Laurence Fishburne", "Morpheus"},
                                    {"Carrie-Anne Moss", "Trinity"},
                                    {"Hugo Weaving", "Agent Smith"},
                                    {"Lana Wachowski", "Lilly Wachowski"},
                                    {"Lana Wachowski", "Lilly Wachowski"},
                            },
                    },
                    {
                            9871, "Forest Gump", 1994, 202,
                            {
                                    {"Tom Hanks", "Forrest Gump"},
                                    {"Sally Field", "Mrs. Gump"},
                                    {"Robin Wright", "Jenny Curran"},
                                    {"Mykelti Wiliamson", "Bubba Blue"}},
                            {"Robert Zemeckis"},
                            {"Winston Groom", "Eric Roth"},
                    }
            };
    serialize_json(movies, "../PracticeC/Serialization/test/movies.json");
}