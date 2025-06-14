#include <fstream>
#include "Render.hpp"

// "C:/Users/user/Desktop/m.png"

ItusKhomaRender::ItusKhomaRender(const std::string image_name, const std::string screenshot_name, const uint32 res)
 : image_name(image_name), screenshot_path(screenshot_name), screenshot_name(screenshot_name), RESOLUSION(res)
{
    // RESOLUSION = 12.f;
    ColorBias = 0x00000000;

    if(!ScanKhoam()) { return; }
    MakeChunkAverage();
    if(!InitFontText()) { return; }

    LoadToTextBuffer();
    AllgineAtoms();

    //* Window class....
    InitWindow(ImageX, ImageY);

    RenderKhoma();
}

ItusKhomaRender::~ItusKhomaRender()
{
    DeleteWindow();

}

bool ItusKhomaRender::ScanKhoam()
{
    if(!ItusKhoma.loadFromFile(image_name))
    {
        std::cout<<"Unable to load the Itu's Khoma\n";
        return false;
    }

    ImageX = ItusKhoma.getSize().x ;
    ImageY = ItusKhoma.getSize().y ;

    PixelBuffer.resize(ImageY/RESOLUSION + 1);
    PixelBuffer_R.resize(ImageY/RESOLUSION + 1);
    PixelBuffer_G.resize(ImageY/RESOLUSION + 1);
    PixelBuffer_B.resize(ImageY/RESOLUSION + 1);
    PixelBuffer_A.resize(ImageY/RESOLUSION + 1);

    AtomOfKhoma.resize(ImageY/RESOLUSION + 1);    

    for(int i = 0; i < PixelBuffer.size(); i++)
    {
        PixelBuffer.at(i).resize(ImageX/RESOLUSION + 1);
        PixelBuffer_R.at(i).resize(ImageX/RESOLUSION + 1);
        PixelBuffer_G.at(i).resize(ImageX/RESOLUSION + 1);
        PixelBuffer_B.at(i).resize(ImageX/RESOLUSION + 1);
        PixelBuffer_A.at(i).resize(ImageX/RESOLUSION + 1);

        AtomOfKhoma.at(i).resize(ImageX/RESOLUSION + 1);
    }

    std::ofstream dff("dff.txt");


    for(int j = 0; j < ImageY; j++)
    {
        for(int i = 0; i < ImageX; i++)
        {
            int ChunkX = i/RESOLUSION;
            int ChunkY = j/RESOLUSION;

            PixelBuffer.at(ChunkY).at(ChunkX) += MakePixelAverage(i, j);
            /**
             *  RESOLUSION = 3
             *      X0  X1  X2  X3  X4  X5  X6  X7  X8 
                   ###|###|###|###|###|###|###|###|###|
                Y0 ###|###|###|###|###|###|###|###|###|
                   ###|###|###|###|###|###|###|###|###|
                   ------------------------------------
                   ###|###|###|###|###|###|###|###|###|
                Y1 ###|###|###|###|###|###|###|###|###|
                   ###|###|###|###|###|###|###|###|###|
                   ------------------------------------
                   ###|###|###|###|###|###|###|###|###|
                Y2 ###|###|###|###|###|###|###|###|###|
                   ###|###|###|###|###|###|###|###|###|
                   ------------------------------------
            */
        }
    }

    return true;
}

uint32 ItusKhomaRender::MakePixelAverage(int i, int j)
{
    int ChunkX = i/RESOLUSION;
    int ChunkY = j/RESOLUSION;

    PixelBuffer_R.at(ChunkY).at(ChunkX) += ItusKhoma.getPixel(i, j).r;
    PixelBuffer_G.at(ChunkY).at(ChunkX) += ItusKhoma.getPixel(i, j).g;
    PixelBuffer_B.at(ChunkY).at(ChunkX) += ItusKhoma.getPixel(i, j).b;
    PixelBuffer_A.at(ChunkY).at(ChunkX) += ItusKhoma.getPixel(i, j).a;

    uint32 r,g,b,a;
    r = ItusKhoma.getPixel(i, j).r;
    g = ItusKhoma.getPixel(i, j).g;
    b = ItusKhoma.getPixel(i, j).b;
    a = ItusKhoma.getPixel(i, j).a;

    return (r + g + b + a)/4;
}

void ItusKhomaRender::MakeChunkAverage()
{
    for(int j  = 0; j < PixelBuffer.size(); j++)
    {
        for(int i = 0; i < PixelBuffer.at(j).size(); i++)
        {
            PixelBuffer.at(j).at(i) = PixelBuffer.at(j).at(i) / (RESOLUSION * RESOLUSION);

            PixelBuffer_R.at(j).at(i) = PixelBuffer_R.at(j).at(i) / (RESOLUSION * RESOLUSION);
            PixelBuffer_G.at(j).at(i) = PixelBuffer_G.at(j).at(i) / (RESOLUSION * RESOLUSION);
            PixelBuffer_B.at(j).at(i) = PixelBuffer_B.at(j).at(i) / (RESOLUSION * RESOLUSION);
            PixelBuffer_A.at(j).at(i) = PixelBuffer_A.at(j).at(i) / (RESOLUSION * RESOLUSION);
        }
    }
}

int ItusKhomaRender::CalculateDensity(int i, int j)
{
    return this->Density.size() * PixelBuffer.at(j).at(i) / 255;
}

void ItusKhomaRender::LoadToTextBuffer()
{
    union Color{
        uint32 color;

        struct {
            uint8 a;
            uint8 b;
            uint8 g;
            uint8 r;
        } clr;
    };
    Color color;
    
    for (int j = 0; j < ImageY/RESOLUSION; j++)
    {
        for (int i = 0; i < ImageX/RESOLUSION; i++)
        {
            AtomOfKhoma.at(j).at(i) = UniversalAtom;

            color.clr.r = static_cast<uint8>(PixelBuffer_R[j][i]);
            color.clr.g = static_cast<uint8>(PixelBuffer_G[j][i]);
            color.clr.b = static_cast<uint8>(PixelBuffer_B[j][i]);
            color.clr.a = static_cast<uint8>(PixelBuffer_A[j][i]);
            
            AtomOfKhoma.at(j).at(i).setString(sf::String( Density.at(CalculateDensity(i, j)) ));
            if(color.color + ColorBias > 0xffffffff)
            {
                color.color = 0xffffffff;
            } else {
                color.color += ColorBias;
            }
                AtomOfKhoma.at(j).at(i).setFillColor(sf::Color(color.color));
        }
    }


}
void ItusKhomaRender::AllgineAtoms()
{
    for(int j = 0; j < ImageY/RESOLUSION; j++)
    {
        for(int i = 0; i < ImageX/RESOLUSION; i++)
        {
            AtomOfKhoma.at(j).at(i).setPosition(sf::Vector2f(i*(RESOLUSION + FontDistanceX), j*(RESOLUSION + FontDistanceY)));
        }
    }
}

void ItusKhomaRender::RenderKhoma()
{
    while (KhomaDorshon->isOpen())
    {
        KhomaDorshon->clear();

        MakeDisplayKhoma();

        KhomaDorshon->display();

        GetUserAction();
    }
    

}

void ItusKhomaRender::MakeDisplayKhoma()
{
    for(int j = 0; j < ImageY/RESOLUSION; j++)
    {
        for(int i = 0; i < ImageX/RESOLUSION; i++)
        {
            KhomaDorshon->draw(AtomOfKhoma.at(j).at(i));
        }
    }
}

void ItusKhomaRender::GetUserAction()
{
    if(KhomaDorshon->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
                KhomaDorshon->close();
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::S)
            {
                TakeScreenShot();
            }
            break;
        }
    }
}

void ItusKhomaRender::TakeScreenShot()
{

    if(screenshot_path == "n"){
        screenshot_path = "C:/Users/user/Pictures/ItusKhoma_ScreenShot_";
        screenshot_name = screenshot_path + std::to_string(rand()) + ".png";
    }

    if(!KhomaDorshon->capture().saveToFile(this->screenshot_name))
    {
        std::string command = "mkdir " + screenshot_path;
        std::cout<<command.data() <<std::endl;
        system(command.data());
    }
    if(!KhomaDorshon->capture().saveToFile(this->screenshot_name))
    {
        std::cout<<"Unable to localize screenshot file directory!!!\n";
    }
    else{
        std::cout<<"Screenshot saved to: "<<this->screenshot_name<<std::endl;
    }
}

bool ItusKhomaRender::InitFontText()
{
    if(!KhomaR_Font.loadFromFile("../Fonts/mew.ttf"))
    {
        std::cout<<"Unable To load font-family\n";
        return false;
    }

    FontDistanceX = 0.f;
    FontDistanceY = -0.1f;

    UniversalAtom.setFont(KhomaR_Font);

    UniversalAtom.setLetterSpacing(0.f);
    UniversalAtom.setLineSpacing(0.f);
    UniversalAtom.setCharacterSize(RESOLUSION);
    UniversalAtom.setFillColor(sf::Color::White);

    return true;
}


///*-------------------------------------------------------------------------------
///*--------------------------------Window-----------------------------------------
///*-------------------------------------------------------------------------------




void ItusKhomaRender::InitWindow(int imageX, int imageY)
{
    int windowX = imageX + ( (imageX/RESOLUSION) * FontDistanceX );
    int windowY = imageY + ( (imageY/RESOLUSION) * FontDistanceY );

    KhomaDorshon = new sf::RenderWindow(sf::VideoMode(windowX, windowY), "Itu's Khoma", sf::Style::Close | sf::Style::Titlebar);

    KhomaDorshon->setPosition(sf::Vector2i(100, 10));

}

void ItusKhomaRender::DeleteWindow()
{
    delete KhomaDorshon;
}
