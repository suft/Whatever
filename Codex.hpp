#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Codex {
private:
    static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
    static std::unordered_map<std::string, std::shared_ptr<sf::Image>> images;
    static std::unordered_map<std::string, std::shared_ptr<sf::Font>> fonts;
    static std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> sounds;

public:
    static std::shared_ptr<sf::Texture> AcquireTexture(const std::string& name);
    static std::shared_ptr<sf::Image> AcquireImage(const std::string& name);
    static std::shared_ptr<sf::Font> AcquireFont(const std::string& name);
    static std::shared_ptr<sf::SoundBuffer> AcquireSound(const std::string& name);
    static void Clean();
private:
    static void CleanTextures();
    static void CleanImages();
    static void CleanFonts();
    static void CleanSounds();
};