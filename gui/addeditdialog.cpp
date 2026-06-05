#include "addeditdialog.hpp"
#include "factories/CompositionFactory.hpp"
#include "domain/Song.hpp"
#include "domain/InstrumentalTrack.hpp"
#include <QMessageBox>

AddEditDialog::AddEditDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Добавить композицию");
    setupUI();
}

AddEditDialog::AddEditDialog(const MusicalComposition& comp, QWidget *parent) : QDialog(parent) {
    setWindowTitle("Редактировать композицию");
    setupUI();
    populateFields(comp);
}

void AddEditDialog::setupUI() {
    auto* layout = new QVBoxLayout(this);
    auto* form = new QFormLayout();

    editTitle = new QLineEdit(this);
    editComposer = new QLineEdit(this);
    editGenre = new QLineEdit(this);
    spinDuration = new QSpinBox(this);
    spinDuration->setRange(1, 9999);
    spinDuration->setSuffix(" сек");

    comboType = new QComboBox(this);
    comboType->addItems({"Песня (Song)", "Инструментал (Instrumental)"});
    connect(comboType, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AddEditDialog::onTypeChanged);

    editSpecific = new QLineEdit(this); // Вокалист или Инструмент
    checkFlag = new QCheckBox(this);    // Есть текст / Есть соло

    form->addRow("Название:", editTitle);
    form->addRow("Композитор:", editComposer);
    form->addRow("Жанр:", editGenre);
    form->addRow("Длительность:", spinDuration);
    form->addRow("Тип:", comboType);
    form->addRow("Спец. поле:", editSpecific);
    form->addRow("Доп. флаг:", checkFlag);

    layout->addLayout(form);

    auto* btnLayout = new QHBoxLayout();
    btnOK = new QPushButton("OK", this);
    btnCancel = new QPushButton("Отмена", this);
    btnLayout->addWidget(btnOK);
    btnLayout->addWidget(btnCancel);
    layout->addLayout(btnLayout);

    connect(btnOK, &QPushButton::clicked, this, &QDialog::accept);
    connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}

void AddEditDialog::populateFields(const MusicalComposition& comp) {
    editTitle->setText(QString::fromStdString(comp.GetTitle()));
    editComposer->setText(QString::fromStdString(comp.GetComposer()));
    editGenre->setText(QString::fromStdString(comp.GetGenre()));
    spinDuration->setValue(comp.GetDuration());

    // Определяем тип через dynamic_cast
    if (dynamic_cast<const Song*>(&comp)) {
        comboType->setCurrentIndex(0);
        const auto& s = static_cast<const Song&>(comp);
        editSpecific->setText(QString::fromStdString(s.GetVocalist()));
        checkFlag->setChecked(s.HasLyrics());
        checkFlag->setText("Есть текст");
    } else if (dynamic_cast<const InstrumentalTrack*>(&comp)) {
        comboType->setCurrentIndex(1);
        const auto& i = static_cast<const InstrumentalTrack&>(comp);
        editSpecific->setText(QString::fromStdString(i.GetLeadInstrument()));
        checkFlag->setChecked(i.HasSolo());
        checkFlag->setText("Есть соло");
    }
    onTypeChanged(0); // Обновить подписи
}

void AddEditDialog::onTypeChanged(int index) {
    if (index == 0) { // Песня
        editSpecific->setPlaceholderText("Вокалист");
        checkFlag->setText("Есть текст");
    } else { // Инструментал
        editSpecific->setPlaceholderText("Ведущий инструмент");
        checkFlag->setText("Есть соло");
    }
}

bool AddEditDialog::validateInputs() {
    if (editTitle->text().isEmpty() || editComposer->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка ввода", "Название и композитор не могут быть пустыми");
        return false;
    }
    return true;
}

std::unique_ptr<MusicalComposition> AddEditDialog::createTrackFromData() {
    if (!validateInputs()) return nullptr;

    SongFactory songFactory;
    InstrumentalFactory instFactory;
    bool isSong = (comboType->currentIndex() == 0);

    if (isSong) {
        return songFactory.CreateSong(
            editTitle->text().toStdString(),
            spinDuration->value(),
            editComposer->text().toStdString(),
            editGenre->text().toStdString(),
            editSpecific->text().toStdString(),
            checkFlag->isChecked()
        );
    } else {
        return instFactory.CreateInstrumental(
            editTitle->text().toStdString(),
            spinDuration->value(),
            editComposer->text().toStdString(),
            editGenre->text().toStdString(),
            editSpecific->text().toStdString(),
            checkFlag->isChecked()
        );
    }
}
