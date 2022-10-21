#include <iostream>
#include "Movies.h"
#include "Utility.h"

void add_movie(Movies& movies, const std::string& name,const std::string& rating,size_t watch_time);
void increment_watched(Movies& movies, const std::string& name);

int main() {
    Movies* my_movies = new Movies();
    bool should_continue {true};

    int choice;

    while(should_continue){
        choice = Utility::take_choice(std::vector<std::string>{"Add Movie","Increment Watch Count for Movie","Exit"});
        switch (choice) {
            case 1:
                std::string name;
                std::string rating;
                int watch_time;

                std::cout<<"Name of the Movie => ";
                std::getline(std::cin,name);

                std::vector<std::string> options {"Add Movie","Increment Watch Count for Movie","Exit"};

                bool valid_option_taken {false};
                while (!valid_option_taken){
                    int rate = Utility::take_choice(options);
                    if(rate < options.size()){
                        rating = options[rate];
                        valid_option_taken = true;
                    }else{
                        std::cout<<"Invalid Rating..." <<std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Invalid Input Try Again" << std::endl;
                break;
            case 3:
                should_continue = false;
                std::cout << "Invalid Input Try Again" << std::endl;
                break;
            default:
                std::cout << "Invalid Input Try Again" << std::endl;
                break;
        }
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

