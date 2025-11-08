#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddTask();
    void onRemoveSelectedTasks();
    void onRemoveAllTasks();
    void onTaskListContextMenuRequest(const QPoint &pos);
    void onTaskItemChanged(QListWidgetItem *item);
    void updateStatusBar();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void loadTasksFromFile();
    void saveTasksToFile();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
