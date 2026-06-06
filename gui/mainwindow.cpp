#include "mainwindow.hpp"
#include "addeditdialog.hpp"
#include "factories/CompositionFactory.hpp"
#include "domain/MusicDisk.hpp"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Меломан: Управление диском");
    resize(400, 300);

    // 1. Создаём диск (логика)
    disk = std::make_unique<MusicDisk>("My Collection", 80);

    initDefaultData();

    setupLayout();
    refreshUI();
}

MainWindow::~MainWindow() = default;

void MainWindow::initDefaultData() {
    SongFactory songFactory;
    InstrumentalFactory instFactory;

    // Добавляем начальные треки (длительность в секундах)
    disk->AddTrack(songFactory.CreateSong("Bohemian Rhapsody", 354.56, "Queen", "Rock", "Freddie Mercury", true));
    disk->AddTrack(instFactory.CreateInstrumental("Canon in D", 360.13, "Pachelbel", "Classical", "Violin", true));
}

void MainWindow::setupLayout() {
    auto* mainLayout = new QVBoxLayout(this);

    // Список треков
    cbTracks = new QComboBox(this);
    mainLayout->addWidget(new QLabel("Список композиций:"));
    mainLayout->addWidget(cbTracks);

    // Кнопки управления
    auto* btnLayout = new QHBoxLayout();
    btnAdd = new QPushButton("Добавить", this);
    btnEdit = new QPushButton("Редактировать", this);
    btnDelete = new QPushButton("Удалить", this);
    btnLayout->addWidget(btnAdd);
    btnLayout->addWidget(btnEdit);
    btnLayout->addWidget(btnDelete);
    mainLayout->addLayout(btnLayout);

    // Расчётный параметр (продолжительность)
    lblTotalDuration = new QLabel("Общая продолжительность: 0 сек", this);
    lblTotalDuration->setStyleSheet("font-weight: bold; font-size: 14px;");
    mainLayout->addWidget(lblTotalDuration);

    mainLayout->addStretch();

    // Привязка сигналов к слотам
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::onAdd);
    connect(btnEdit, &QPushButton::clicked, this, &MainWindow::onEdit);
    connect(btnDelete, &QPushButton::clicked, this, &MainWindow::onDelete);
}

void MainWindow::refreshUI() {
    cbTracks->clear();
    
    // Перебираем все треки в диске
    for (int i = 0; i < disk->GetTrackCount(); ++i) {
        // Получаем указатель на объект композиции
        auto track = disk->GetTrack(i);
        
        // Если объект валиден, берем его название
        if (track) {
            cbTracks->addItem(QString::fromStdString(track->GetTitle()));
        } else {
            // Заглушка, если трек по какой-то причине пуст
            cbTracks->addItem(QString("Unknown Track"));
        }
    }

    // Обновляем длительность
    double totalSec = disk->CalculateTotalDuration();
    lblTotalDuration->setText(QString("Общая продолжительность: %1 сек (%2 мин %3 сек)")
        .arg(totalSec, 0, 'f', 1) // Вывод с 1 знаком после запятой
        .arg(static_cast<int>(totalSec) / 60)
        .arg(static_cast<int>(totalSec) % 60));
}

void MainWindow::onAdd() {
    AddEditDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        auto track = dialog.createTrackFromData();
        if (track) {
            disk->AddTrack(std::move(track));
            refreshUI();
        }
    }
}

void MainWindow::onEdit() {
    int idx = cbTracks->currentIndex();
    if (idx < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите композицию для редактирования");
        return;
    }

    auto track = disk->GetTrack(idx);
    if (!track){
        QMessageBox::warning(this, "Ошибка", "Не удалось получить композицию");
        return;
    }

    AddEditDialog dialog(*track, this);
    if (dialog.exec() == QDialog::Accepted) {
        disk->UpdateTrack(idx, dialog.createTrackFromData());
        refreshUI();
    }
}

void MainWindow::onDelete() {
    int idx = cbTracks->currentIndex();
    if (idx < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите композицию для удаления");
        return;
    }
    disk->RemoveTrack(idx);
    refreshUI();
}
