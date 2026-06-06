#ifndef ADDEDITDIALOG_HPP
#define ADDEDITDIALOG_HPP

#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <memory>

class MusicalComposition; // Из DLL

class AddEditDialog : public QDialog {
    Q_OBJECT
public:
    // Конструктор 1: для добавления нового объекта
    explicit AddEditDialog(QWidget *parent = nullptr);
    // Конструктор 2: для редактирования существующего
    explicit AddEditDialog(const MusicalComposition& comp, QWidget *parent = nullptr);

    std::unique_ptr<MusicalComposition> createTrackFromData();

private:
    void setupUI();
    void populateFields(const MusicalComposition& comp);
    void onTypeChanged(int index);
    bool validateInputs();

    QLineEdit* editTitle, *editComposer, *editGenre, *editSpecific;
    QSpinBox* spinDuration;
    QComboBox* comboType;
    QCheckBox* checkFlag; // Текст песни / Соло
    QPushButton* btnOK, *btnCancel;
};

#endif
