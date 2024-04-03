#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>
#include <string>
#include <vector>


class ItusKhomaRender
{
public:

    ItusKhomaRender(const std::string image_name);
    ~ItusKhomaRender();

    bool ScanKhoam();
    void RenderKhoma();

    void MakeDisplayKhoma();
    void GetUserAcion();

    void MakeChunkAverage();
    void LoadToTextBuffer();
    int CalculateDensity(int i, int j);
    int32_t MakePixelAverage(int i, int j);

    bool InitFontText();
    void AllgineAtoms();

    //* Window....
    void InitWindow(int imageX, int imageY);
    void DeleteWindow();

private:

    int32_t ImageX, ImageY;
    int32_t RESOLUSION;

    int32_t ColorBias;

    const std::string image_name;

    const std::string Density = " .,-~*=!%A&@#";

    sf::Image ItusKhoma;

    std::vector<std::vector<int32_t>> PixelBuffer;


    sf::Text UniversalAtom;
    std::vector<std::vector<sf::Text>> AtomOfKhoma;

    std::vector<std::vector<int32_t>> PixelBuffer_R;
    std::vector<std::vector<int32_t>> PixelBuffer_G;
    std::vector<std::vector<int32_t>> PixelBuffer_B;
    std::vector<std::vector<int32_t>> PixelBuffer_A;


    //* Window....

    float FontDistanceX, FontDistanceY;
    sf::Font KhomaR_Font;

    sf::RenderWindow* KhomaDorshon;
    sf::Event event;

};

