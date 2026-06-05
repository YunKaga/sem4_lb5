#ifndef MUSICALCOMPOSITION_HPP
#define MUSICALCOMPOSITION_HPP

#include "AudioContent.hpp" // подключение заголовка

class MUSIC_API MusicalComposition : public AbstractAudioContent { // наследование от абстрактного класса
protected: // данные поля доступны наследникам
    std::string composer;
    std::string genre;

public: // видимые методы
    MusicalComposition(const std::string& title, double duration, const std::string& composer, const std::string& genre); // конструктор
    // геттеры
    std::string GetComposer() const;
    std::string GetGenre() const;
    void ShowInfo() const override;
    std::string GetInfo() const;
    // деструктор
    virtual ~MusicalComposition() override;
};

#endif
