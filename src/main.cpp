#include <iostream>
#include <locale>

int main()
{
    auto locale{ std::locale("") };
    auto oldLocale{ std::locale::global(locale) };
    std::cout.imbue(locale);

    try {
        // Game run here ...
        std::cout << "Привет, моя RPG игрушка!\n";

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::locale::global(oldLocale);
    std::cout.imbue(oldLocale);

    return 0;
}
