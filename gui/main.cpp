#include <QApplication>
#include "mainwindow.hpp"

int main(int argc, char *argv[]) {
    // 1. Инициализация приложения Qt.
    // Аргументы argc и argv необходимы Qt для обработки системных параметров
    QApplication app(argc, argv);

    // 2. Создание экземпляра главного окна.
    MainWindow window;

    // 3. Отображение окна на экране.
    window.show();

    // 4. Запуск основного цикла обработки событий Qt.
    return app.exec();
}
