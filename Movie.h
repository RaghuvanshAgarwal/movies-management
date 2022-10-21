//
// Created by CarnageBFR on 19-10-2022.
//

#ifndef MOVIE_MOVIE_H
#define MOVIE_MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    size_t watch_count;
public:
    explicit Movie(std::string name = "Movie",std::string rating = "G",size_t watch_count = 0); // Normal Constructor
    Movie(const Movie& source); //Deep Copy Constructor
    Movie(Movie&& source) noexcept; //Move Constructor

    std::string get_name(); // Name Getter

    size_t get_watch_count() const; // Watch Count Getter
    void set_watch_count(size_t value); // Watch Count Setter

    void print_detail() const;

};


#endif //MOVIE_MOVIE_H
