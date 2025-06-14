#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>
#include <string>
#include <vector>


typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;


class ItusKhomaRender
{
public:

    ItusKhomaRender(const std::string image_name, const std::string screenshot_name, const uint32 res);
    ~ItusKhomaRender();

    bool ScanKhoam();
    void RenderKhoma();

    void MakeDisplayKhoma();
    void GetUserAction();
    void TakeScreenShot();

    void MakeChunkAverage();
    void LoadToTextBuffer();
    int CalculateDensity(int i, int j);
    uint32 MakePixelAverage(int i, int j);

    bool InitFontText();
    void AllgineAtoms();

    //* Window....
    void InitWindow(int imageX, int imageY);
    void DeleteWindow();

private:

    uint32 ImageX, ImageY;
    uint32 RESOLUSION;

    uint32 ColorBias;

    const std::string image_name;
    std::string screenshot_path;
    std::string       screenshot_name;

    const std::string Density = " .,-~*=!%A&@#";

    sf::Image ItusKhoma;

    std::vector<std::vector<uint32>> PixelBuffer;


    sf::Text UniversalAtom;
    std::vector<std::vector<sf::Text>> AtomOfKhoma;

    std::vector<std::vector<uint32>> PixelBuffer_R;
    std::vector<std::vector<uint32>> PixelBuffer_G;
    std::vector<std::vector<uint32>> PixelBuffer_B;
    std::vector<std::vector<uint32>> PixelBuffer_A;


    //* Window....

    uint32 FontDistanceX, FontDistanceY;
    sf::Font KhomaR_Font;

    sf::RenderWindow* KhomaDorshon;
    sf::Event event;

};

