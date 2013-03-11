#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include <gphoto2/gphoto2.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    CameraAbilities a;
    int size,r;
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(this);

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Camera")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Comment")));
    ui->tableView->setModel(model);

    GPContext* context = gp_context_new();
    CameraAbilitiesList* list;

    gp_abilities_list_new(&list);
    gp_abilities_list_load(list, context);

    size = gp_abilities_list_count(list);
    for(int i= 0; i < size; i++)
    {
        r = gp_abilities_list_get_abilities(list, i, &a);
        if( r < 0 ) break;
        QStandardItem* cam = new QStandardItem(QString(a.model));
        model->setItem(i,0, cam);

        QStandardItem* com = new QStandardItem();
        switch (a.status)
        {
        case GP_DRIVER_STATUS_TESTING:
            com->setText(QString("TESTING"));
            break;
        case GP_DRIVER_STATUS_EXPERIMENTAL:
             com->setText(QString("EXPERIMENTAL"));
            break;
        case GP_DRIVER_STATUS_DEPRECATED:
            com->setText(QString("DEPRECATED"));
            break;
        case GP_DRIVER_STATUS_PRODUCTION:
            break;
        default:
            com->setText(QString("UNKOWN"));
            break;
        }
        model->setItem(i,1, com);
    }

    gp_abilities_list_free(list);
    list = NULL;
    gp_context_unref(context);
    context = NULL;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QAbstractItemModel *model = ui->tableView->model();

    QList<QModelIndex> list = model->match(model->index(0,0), Qt::DisplayRole, arg1, -1, Qt::MatchContains | Qt::MatchRecursive );

    if (!list.empty())
    {
        ui->tableView->setCurrentIndex(list.at(0));
    }

}
