#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>


#ifdef QT_NO_DEBUG
void customMessageHandler(QtMsgType type, const QMessageLogContext &/*context*/, const QString &msg)
{
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("%1").arg(msg);
        break;

    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        abort();
    }

    QFile outFile("app.log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("kazak1377");
    QCoreApplication::setOrganizationDomain("kazak1377.16mb.com");
    QCoreApplication::setApplicationName("QVkPlayer");
    QCoreApplication::setApplicationVersion("0.5a");
#ifdef QT_NO_DEBUG
    qInstallMessageHandler(customMessageHandler);
#endif
    qDebug()<<" \n\n\n\n\n\n\n\n\n\n";
    qDebug()<<"==========App_started=========";
    a.addLibraryPath(a.applicationDirPath());
    MainWindow w;
    w.setWindowIcon(QIcon(":/icons/qvk.ico"));
    w.show();
    return a.exec();
}
