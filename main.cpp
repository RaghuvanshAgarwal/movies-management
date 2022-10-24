#include <iostream>
#include "Movies.h"
#include "Utility.h"

void init_add_movie(Movies& movies);
void init_watch_time_increment(Movies& movies);
void add_movie(Movies& movies, const std::string& name,const std::string& rating,size_t watch_time);
void increment_watched(Movies& movies, const std::string& name);

int main() {
    auto* my_movies = new Movies();
    bool should_continue {true};

    int choice;

    while(should_continue){
        choice = Utility::take_choice(std::vector<std::string>{"Add Movie","Increment Watch Count for Movie", "Print All Movies" ,"Exit"});
        switch (choice) {
            case 1:
                init_add_movie(*my_movies);
                break;
            case 2:
                init_watch_time_increment(*my_movies);
                break;
            case 3:
                my_movies->print_movies();
                break;
            case 4:
                should_continue = false;
                std::cout << "Program Exit......" << std::endl;
                break;
            default:
                std::cout << "Invalid Input Try Again" << std::endl;
                break;
        }
        Utility::print_breaker();
    }


    return 0;
}
void add_movie(Movies& movies, const std::string& name,const std::string& rating,size_t watch_time){
    if(movies.add_movie(name,rating,watch_time)){
        std::cout <<name <<" Added"<<std::endl;
    }else{
        std::cout <<name <<" exist"<<std::endl;
    }
}

void increment_watched(Movies& movies, const std::string& name){
    if(movies.increment_watch_count(name)){
        std::cout <<name <<" incremented"<<std::endl;
    }else{
        std::cout <<name <<" does not exist"<<std::endl;
    }
}

void init_add_movie(Movies& movies){
    std::string name;
    std::string rating;
    size_t watch_time;

    std::cin.ignore();
    std::cout<<"Name of the Movie => ";
    std::getline(std::cin,name);


    std::vector<std::string> options {"G","PG","PG-13","R"};

    bool valid_option_taken {false};
    while (!valid_option_taken){
        int rate = Utility::take_choice(options);
        if(rate < static_cast<int>(options.size())){
            rating = options[rate];
            valid_option_taken = true;
        }else{
            std::cout<<"Invalid Rating..." <<std::endl;
        }
    }
    std::cout<<"Number of Times Movie Watched => ";
    std::cin >> watch_time;

    add_movie(movies,name,rating,watch_time);
}

void init_watch_time_increment(Movies& movies){
    std::string name;

    std::cin.ignore();
    std::cout<<"Name of the Movie => ";
    std::getline(std::cin,name);

    increment_watched(movies,name);
}
