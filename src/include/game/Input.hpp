#ifndef __INPUT__H__
#define __INPUT__H__

#include <string_view>
#include <iostream>
#include <exception>
#include <vector>
#include <map>
#include <limits>

namespace game
{
    class Input
    {
    public:
        class InputError : public std::runtime_error
        {
        public:
            using std::runtime_error::runtime_error;
        };

        std::string getString(std::string_view title) const noexcept(false)
        {
            std::string res{};
            std::cout << title;
            if (std::getline(std::cin >> std::ws, res, '\n').eof()) {
                throw InputError{ "Interrupted" };
            }
            return res;
        }

        template<typename Val>
        std::size_t getMenuChoice(
            std::string_view title,
            std::string_view failMsg,
            const std::vector<Val>& items
        ) const
        {
            while (true) {

                int itemIndex{ 1 };
                std::cout << title << "\n---\n";
                for (auto&& item : items) {
                    std::cout << itemIndex << ") " << item << '\n';
                    ++itemIndex;
                } std::cout << "---\n> ";

                if (std::size_t input{ 0 }; std::cin >> input && input > 0 && input < std::size(items)) {
                    return input - 1;
                }

                if (std::cin.eof()) {
                    throw InputError{ "Interrupted" };
                }

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << failMsg << '\n';
            }
        }

        template<typename Key, typename Val>
        Key getMenuChoice(
            std::string_view title,
            std::string_view failMsg,
            const std::map<Key, Val>& items
        ) const
        {
            while (true) {

                std::cout << title << "\n---\n";
                for (auto&& [key, item] : items) {
                    std::cout << key << ") " << item << '\n';
                } std::cout << "---\n> ";

                if (Key input{}; std::cin >> input && items.count(input) > 0) {
                    return input;
                }

                if (std::cin.eof()) {
                    throw InputError{ "Interrupted" };
                }

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << failMsg << '\n';
            }
        }
    };
} // namespace game


#endif  //!__INPUT__H__