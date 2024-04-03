#include "Render.hpp"

int main()
{
    {
        std::string image_name = "test.png";
        std::cin>>image_name;

        ItusKhomaRender ikr(image_name);

    }
    std::cin.get();
    // system("pause");

    return 0;
}