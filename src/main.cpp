#include <iostream>
#include <locale>
#include <vector>

#include "game/Input.hpp"
#include "game/Engine.hpp"

int main()
{
    auto locale{ std::locale("") };
    auto oldLocale{ std::locale::global(locale) };
    std::cout.imbue(locale);

    game::Input inpit{};

    try {
        // Game run here ...
        std::cout << "Привет, моя RPG игрушка!\n";
        std::vector classes{
            "Хитрец",
            "Боец",
            "Богатырь",
        };

        auto name{ inpit.getString("Приветствую тебя странник, назови своё имя: ") };
        auto choice{
            inpit.getMenuChoice(
                "Опиши себя " + name,
                "Не понял тебя. Повторим.",
                classes
            )
        };

        std::cout << "Your choice is: " << name << " - " << classes[choice] << '\n';

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::locale::global(oldLocale);
    std::cout.imbue(oldLocale);

    return 0;
}
