#pragma once
#include <iostream>
#include <string>
#include <vector>
class Utility
{
public:
	static std::string generate_menu(const std::vector<std::string>& options)
	{
		std::string menu;
		menu += "Menu:\n";
		for (size_t i = 0; i < options.size(); i++)
		{
			menu += "     " + std::to_string(i + 1) + "-> " + options[i] + "\n";
		}
		menu += "Your Choice-> ";
		return menu;
	}

	static int take_choice(const std::vector<std::string>& options) {
		std::cout << generate_menu(options);
		int choice{ 0 };
		std::cin >> choice;
		return choice;
	}

    static int take_choice(const std::vector<std::string>&& options) {
        std::cout << generate_menu(options);
        int choice{ 0 };
        std::cin >> choice;
        return choice;
    }

	static void print_breaker(int leave_lines = 2)
	{
		std::cout << std::string(leave_lines - 1, '\n') << std::string(20, '=') << std::string(leave_lines, '\n');
	}
};

