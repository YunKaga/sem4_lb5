#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <memory>

class MusicDisk; // Из вашей DLL

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onAdd();
    void onEdit();
    void onDelete();
    void refreshUI();

private:
    void setupLayout();
    void initDefaultData(); // Инициализация через фабрики (требование ЛР №5)

    std::unique_ptr<MusicDisk> disk;
    QComboBox* cbTracks;
    QLabel* lblTotalDuration;
    QPushButton* btnAdd, *btnEdit, *btnDelete;
};

#endif
