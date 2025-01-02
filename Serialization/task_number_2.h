//
// Created by Oleksandr Demnychenko on 31.12.2024.
//

#include "iostream"
#include "vector"
#include "pugixml.hpp"

std::string text = R"(<?xml version="1.0"?>
<movies>
	<movie title="The Matrix" year="1999" length="196">
		<directors />
		<writers />
	</movie>
	<cast>
		<role star="Keanu Reeves" name="Neo" />
		<role star="Laurence Fishburne" name="Morpheus" />
		<role star="Carrie-Anne Moss" name="Trinity" />
		<role star="Hugo Weaving" name="Agent Smith" />
		<role star="Lana Wachowski" name="Lilly Wachowski" />
		<role star="Lana Wachowski" name="Lilly Wachowski" />
	</cast>
	<movie title="Forest Gump" year="1994" length="202">
		<directors>
			<director name="Robert Zemeckis" />
		</directors>
		<writers>
			<writer name="Winston Groom" />
			<writer name="Eric Roth" />
		</writers>
	</movie>
	<cast>
		<role star="Tom Hanks" name="Forrest Gump" />
		<role star="Sally Field" name="Mrs. Gump" />
		<role star="Robin Wright" name="Jenny Curran" />
		<role star="Mykelti Wiliamson" name="Bubba Blue" />
	</cast>
</movies>
)";

static void task_number_2()
{
    pugi::xml_document doc;
    if(doc.load_string(text.c_str()))
    {
        try {
            auto titles = doc.select_nodes("/movies/movie[@year>1995]");
            for(auto it: titles)
            {
                std::cout << it.node().attribute("title").as_string() << std::endl;
            }
        }
        catch(pugi::xpath_exception const& e)
        {
            std::cout << e.result().description() << std::endl;
        }

        try {
            auto titles = doc.select_nodes("/movies/movie/cast/role[last()]");
            for(auto it: titles)
            {
                std::cout << it.node().attribute("start").as_string() << std::endl;
            }
        }
        catch (pugi::xpath_exception const& e)
        {
            std::cout << e.result().description() << std::endl;
        }
    }
}


