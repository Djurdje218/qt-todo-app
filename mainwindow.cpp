#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>

#include <QFile>
#include <QTextStream>
#include <QCloseEvent>
#include <QMessageBox>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <QShortcut>
#include <QKeySequence>

#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddTask);
    connect(ui->taskInput, &QLineEdit::returnPressed, this, &MainWindow::onAddTask);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveSelectedTasks);
    connect(ui->removeAllButton, &QPushButton::clicked, this, &MainWindow::onRemoveAllTasks);

    auto *delShortcut = new QShortcut(QKeySequence::Delete, ui->taskList);
    connect(delShortcut, &QShortcut::activated, this, &MainWindow::onRemoveSelectedTasks);

    ui->taskList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->taskList, &QListWidget::customContextMenuRequested, this, &MainWindow::onTaskListContextMenuRequest);

    connect(ui->taskList, &QListWidget::itemChanged, this, &MainWindow::onTaskItemChanged);

    setWindowTitle("To-Do list");
    loadTasksFromFile();
    updateStatusBar();


}

void MainWindow::onAddTask()
{
    const QString text = ui->taskInput->text().trimmed();
    if(text.isEmpty()) return;

    auto* item = new QListWidgetItem(text,ui->taskList);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
    item->setCheckState(Qt::Unchecked);

    ui->taskList->addItem(item);
    ui->taskInput->clear();

    updateStatusBar();
}
void MainWindow::onRemoveSelectedTasks()
{
    const auto selectedItems = ui->taskList->selectedItems();
    for(QListWidgetItem *item : selectedItems) {
        delete item;
    }

    updateStatusBar();
}

void MainWindow::onRemoveAllTasks()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Remove All",
                                  "Are you sure you want to remove all tasks?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) ui->taskList->clear();

    updateStatusBar();
}

void MainWindow::loadTasksFromFile()
{
    QFile file("tasks.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    const QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if(parseError.error != QJsonParseError::NoError || !doc.isArray()){
        return;
    }

    QJsonArray array = doc.array();

    for(const QJsonValue &value : array) {
        if(!value.isObject()) continue;

        QJsonObject obj = value.toObject();

        QString text = obj.value("text").toString();
        bool done = obj.value("done").toBool(false);

        if(text.isEmpty()) continue;

        auto *item = new QListWidgetItem(text, ui->taskList);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
        item->setCheckState(done ? Qt::Checked : Qt::Unchecked);
        ui->taskList->addItem(item);
    }
}

void MainWindow::saveTasksToFile()
{
    QJsonArray array;
    for(int i = 0; i < ui->taskList->count(); i++){
        QListWidgetItem *item = ui->taskList->item(i);

        QJsonObject obj;
        obj["text"] = item->text();
        obj["done"] = (item->checkState() == Qt::Checked);

        array.append(obj);
    }

    QJsonDocument doc(array);
    QFile file("tasks.json");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Close",
                                  "Are you sure you want to quit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Accept the close event and let the window close
        saveTasksToFile();
       // event->accept();
        QMainWindow::closeEvent(event);

    } else {
        // Ignore the close event, the window will remain open
        event->ignore();
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTaskListContextMenuRequest(const QPoint &pos)
{
    if(QListWidgetItem *item = ui->taskList->itemAt(pos)){
        if(!item->isSelected()){
            ui->taskList->setCurrentItem(item);
        }
    }

    QMenu menu(this);
    QAction *deleteAction = menu.addAction("Delete");

    QPoint globalPos = ui->taskList->viewport()->mapToGlobal(pos);
    QAction *chosen = menu.exec(globalPos);

    if(chosen == deleteAction){
        onRemoveSelectedTasks();
    }
}

void MainWindow::onTaskItemChanged(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked){
        QFont f = item->font();
        f.setItalic(true);
        f.setStrikeOut(true);
        item->setFont(f);
        item->setForeground(Qt::gray);
    } else {
        QFont f = item->font();
        f.setItalic(false);
        f.setStrikeOut(false);
        item->setFont(f);
        item->setForeground(Qt::white);
    }

    updateStatusBar();
}

void MainWindow::updateStatusBar()
{
    int total = ui->taskList->count();
    int done = 0;

    for (int i = 0; i < total; ++i) {
        auto *item = ui->taskList->item(i);
        if (item->checkState() == Qt::Checked)
            done++;
    }

    int left = total - done;

    statusBar()->showMessage(
        QString("Tasks: %1 | Done: %2 | Left: %3")
            .arg(total)
            .arg(done)
            .arg(left)
        );
}

