//
// Created by CarnageBFR on 20-10-2022.
//

#ifndef MOVIE_MOVIES_H
#define MOVIE_MOVIES_H

#include <vector>
#include <string>
#include "Movie.h"

class Movies {
private:
    std::vector<Movie> movies;

private:
    Movie* has_movie(std::string name);
    static std::string to_lowercase(const std::string& input);

public:
    Movies();
    bool add_movie(const std::string& name,const std::string& rating,size_t watch_time);
    bool increment_watch_count(const std::string& name);
    void print_movies();
};


#endif //MOVIE_MOVIES_H
