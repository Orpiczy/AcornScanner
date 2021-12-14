#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtQuick>
#include <QtWidgets>
#include <QtCharts>
#include <QChart>

#include <controllers/master-controller.h>
#include <controllers/command-controller.h>
#include <controllers/navigation-controller.h>

#include <data/datetime-decorator.h>
#include <data/enumerator-decorator.h>
#include <data/int-decorator.h>
#include <data/string-decorator.h>
#include <framework/command.h>
#include <models/scannedData.hpp>
#include <models/dailyStatisticsData.h>
#include <data/map-decorator.h>
//class Helper: public QObject
//{
//    Q_OBJECT
//public:
//    ~Helper() {};
//    Q_INVOKABLE void update_chart(QQuickItem *item){
//        if(QGraphicsScene *scene = item->findChild<QGraphicsScene *>()){
//            for(QGraphicsItem *it : scene->items()){
//                if(QChart *chart = dynamic_cast<QChart *>(it)){
//                    // Customize chart background
//                    QLinearGradient backgroundGradient;
//                    backgroundGradient.setStart(QPointF(0, 0));
//                    backgroundGradient.setFinalStop(QPointF(0, 1));
//                    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
//                    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
//                    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//                    chart->setBackgroundBrush(backgroundGradient);
//                    // Customize plot area background
//                    QLinearGradient plotAreaGradient;
//                    plotAreaGradient.setStart(QPointF(0, 1));
//                    plotAreaGradient.setFinalStop(QPointF(1, 0));
//                    plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
//                    plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
//                    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//                    chart->setPlotAreaBackgroundBrush(plotAreaGradient);
//                    chart->setPlotAreaBackgroundVisible(true);
//                }
//            }
//        }
//    }
//    Q_INVOKABLE void update_axes(QAbstractAxis *axisX, QAbstractAxis *axisY){
//        if(axisX && axisY){
//            // Customize axis colors
//            QPen axisPen(QRgb(0xd18952));
//            axisPen.setWidth(2);
//            axisX->setLinePen(axisPen);
//            axisY->setLinePen(axisPen);
//            // Customize grid lines and shades
//            axisY->setShadesPen(Qt::NoPen);
//            axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
//        }
//    }
//};


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterType<cm::data::DateTimeDecorator>("CM", 1, 0, "DateTimeDecorator");
    qmlRegisterType<cm::data::EnumeratorDecorator>("CM", 1, 0, "EnumeratorDecorator");
    qmlRegisterType<cm::data::IntDecorator>("CM", 1, 0, "IntDecorator");
    qmlRegisterType<cm::data::StringDecorator>("CM", 1, 0, "StringDecorator");
    qmlRegisterType<cm::data::MapDecorator>("CM", 1, 0, "MapDecorator");
    qmlRegisterType<ac::models::ScannedData>("AC", 1, 0, "ScannedData");
    qmlRegisterType<ac::models::DailyStatisticsData>("AC", 1, 0, "DailyStatisticsData");


    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");
    cm::controllers::MasterController masterController(nullptr);
   // Helper helper;

    QQmlApplicationEngine engine;

    engine.addImportPath("qrc:/");
    engine.addImportPath("C:/Qt/5.15.2/mingw81_64/qml/QtGraphicalEffects");
    engine.rootContext()->setContextProperty("masterController", &masterController);
 //   engine.rootContext()->setContextProperty(QStringLiteral("helper"), &helper);
    engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
