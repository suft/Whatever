#include "Codex.hpp"

std::unordered_map<std::string, std::shared_ptr<sf::Texture>> Codex::textures;
std::unordered_map<std::string, std::shared_ptr<sf::Image>> Codex::images;
std::unordered_map<std::string, std::shared_ptr<sf::Font>> Codex::fonts;
std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> Codex::sounds;

std::shared_ptr<sf::Texture> Codex::AcquireTexture(const std::string& name) {
    const auto i = textures.find(name);
    if (i != textures.end()) return i->second;
    else {
        auto tex = std::make_shared<sf::Texture>();
        tex->loadFromFile(name);
        textures.insert({name, tex});
        return tex;
    }
}

std::shared_ptr<sf::Image> Codex::AcquireImage(const std::string& name) {
    const auto i = images.find(name);
    if (i != images.end()) return i->second;
    else {
        auto img = std::make_shared<sf::Image>();
        img->loadFromFile(name);
        images.insert({name, img});
        return img;
    }
}

std::shared_ptr<sf::Font> Codex::AcquireFont(const std::string& name) {
    const auto i = fonts.find(name);
    if (i != fonts.end()) return i->second;
    else {
        auto font = std::make_shared<sf::Font>();
        font->loadFromFile(name);
        fonts.insert({name, font});
        return font;
    }
}

std::shared_ptr<sf::SoundBuffer> Codex::AcquireSound(const std::string& name) {
    const auto i = sounds.find(name);
    if (i != sounds.end()) return i->second;
    else {
        auto sound = std::make_shared<sf::SoundBuffer>();
        sound->loadFromFile(name);
        sounds.insert({name, sound});
        return sound;
    }
}


void Codex::Clean() {
    Codex::CleanTextures();
    Codex::CleanImages();
    Codex::CleanFonts();
    Codex::CleanSounds();
}

void Codex::CleanTextures() {
    for (auto i = textures.begin(); i != textures.end();) {
        if (i->second.unique()) i = textures.erase(i);
        else ++i;
    }
}

void Codex::CleanImages() {
    for (auto i = images.begin(); i != images.end();) {
        if (i->second.unique()) i = images.erase(i);
        else ++i;
    }
}

void Codex::CleanFonts() {
    for (auto i = fonts.begin(); i != fonts.end();) {
        if (i->second.unique()) i = fonts.erase(i);
        else ++i;
    }
}

void Codex::CleanSounds() {
    for (auto i = sounds.begin(); i != sounds.end();) {
        if (i->second.unique()) i = sounds.erase(i);
        else ++i;
    }
}
