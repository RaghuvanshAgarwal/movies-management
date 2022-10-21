//
// Created by CarnageBFR on 20-10-2022.
//

#include <iostream>
#include "Movies.h"
#include "Movie.h"


Movies::Movies() : movies() {}

Movie* Movies::has_movie(std::string name) {
    Movie* ptr {nullptr};
    name = to_lowercase(name);

    for (Movie& movie : this->movies) {
        if(to_lowercase(movie.get_name()) == name){
            ptr = &movie;
        }
    }

    return ptr;
}

std::string Movies::to_lowercase(const std::string& input) {
    std::string new_str;
    for (const char & i : input){
        new_str += static_cast<char>(std::tolower(i)) ;
    }
    return new_str;
}

bool Movies::add_movie(const std::string& name, const std::string &rating, size_t watch_time) {
    Movie* ptr = this->has_movie(name);
    if(ptr != nullptr){
        return false;
    }
    this->movies.emplace_back(Movie{name,rating,watch_time});
    return true;
}

bool Movies::increment_watch_count(const std::string& name) {
    Movie* ptr = this->has_movie(name);
    if(ptr == nullptr){
        return false;
    }
    ptr->set_watch_count(ptr->get_watch_count() + 1);
    return true;
}

void Movies::print_movies() {
    for(const Movie& movie : this->movies){
        movie.print_detail();
        std::cout<<std::endl;
    }
}
