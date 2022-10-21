//
// Created by CarnageBFR on 19-10-2022.
//
#include <iostream>
#include "Movie.h"


Movie::Movie(std::string name, std::string rating, size_t watch_count) : name(std::move(name)), rating(std::move(rating))
{
    this->watch_count = watch_count;
}

Movie::Movie(const Movie &source) : name(source.name), rating(source.rating) {
    this->watch_count = source.watch_count;
}

Movie::Movie(Movie &&source) noexcept : Movie(source.name,source.rating,source.watch_count){

}

std::string Movie::get_name() {
    return this->name;
}


size_t Movie::get_watch_count() const {
    return this->watch_count;
}

void Movie::set_watch_count(size_t value) {
    this->watch_count = value;
}

void Movie::print_detail() const {
    std::cout << "Name=> " << this->name << std::endl;
    std::cout << "Rating=> " << this->rating << std::endl;
    std::cout << "Watch Count=> " << this->watch_count << std::endl;
}