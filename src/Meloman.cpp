#include "factories/CompositionFactory.hpp"
#include "factories/LoggerFactory.hpp"
#include "presentation/ConsolePresenter.hpp"
#include "presentation/FilePresenter.hpp"
#include "domain/MusicDisk.hpp"
#include "datasource/DiskStorage.hpp"
#include <memory>
#include <iostream>

// Что-то типо ядра
class ApplicationController {
private:
    std::unique_ptr<ILogger> logger;
    std::unique_ptr<IPresenter> presenter;

public:
    ApplicationController(std::unique_ptr<ILogger> logger, 
                         std::unique_ptr<IPresenter> presenter)
        : logger(std::move(logger)), presenter(std::move(presenter)) {}
    
    void Run() {
        logger->LogInfo("=== Music Disk Application Started ===");
        
        // Создание фабрик
        SongFactory songFactory;
        InstrumentalFactory instrumentalFactory;
        
        // Создание песен фабриками
        logger->LogDebug("Creating songs and instrumental tracks...");
        
        auto song1 = songFactory.CreateSong(
            "В весеннем лесу очень хорошо", 35.4,
            "Дворовая", "Pop",
            "Двор", true
        );
        
        auto song2 = songFactory.CreateSong(
            "Что такое осень", 183.13,
            "ДДТ", "Punk-rock",
            "Имя", true
        );
        
        auto instrumental1 = instrumentalFactory.CreateInstrumental(
            "Rush E", 281.36,
            "Кто-то там", "Classical",
            "Piano", false
        );
        
        auto instrumental2 = instrumentalFactory.CreateInstrumental(
            "Zaglushka", 360.19,
            "Ludwig van Beethoven", "Classical",
            "Piano", true
        );
        
        // Создание диска
        logger->LogInfo("Creating music disk...");
        MusicDisk disk("My Collection", 80);
        
        // Добавление треков
        disk.AddTrack(std::move(song1));
        disk.AddTrack(std::move(song2));
        disk.AddTrack(std::move(instrumental1));
        disk.AddTrack(std::move(instrumental2));
        
        logger->LogDebug("Added 4 tracks to disk");
        
        // Вывод информации
        presenter->ShowMessage("\n=== Displaying disk information ===");
        presenter->ShowDisk(disk);
        
        // Сохранение информации о диске
        logger->LogInfo("Saving disk information to file...");
        DiskStorage::SaveDiskInfo(disk, "disk_info.txt");
        
        logger->LogInfo("=== Application Finished Successfully ===");
    }
};

int main() {
    try {
        // Создаем зависимости через фабрики
        ConsoleLoggerFactory loggerFactory;
        auto logger = loggerFactory.CreateLogger();
        
        auto presenter = std::make_unique<ConsolePresenter>();
        
        // Создаем и запускаем контроллер
        ApplicationController app(std::move(logger), std::move(presenter));
        app.Run();
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
}
