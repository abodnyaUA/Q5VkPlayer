#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QMetaType>

#ifdef WIN32
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
#ifdef WIN32
    QFile outFile("app.log");
#elif defined Q_OS_LINUX
    QFile outFile(QDir::homePath()+".config/kazak1377/app.log");
#endif
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}
#endif
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<QList<QUrl> >("QList<QUrl>");
    QCoreApplication::setOrganizationName("kazak1377");
    QCoreApplication::setOrganizationDomain("kazak1377.16mb.com");
    QCoreApplication::setApplicationName("QVkPlayer");
    QCoreApplication::setApplicationVersion("0.8a");
#ifdef WIN32
#ifdef QT_NO_DEBUG
    qInstallMessageHandler(customMessageHandler);
#endif
#endif
    qDebug()<<" \n\n\n\n\n\n\n\n\n\n";
    qDebug()<<"==========App_started=========";
    a.addLibraryPath(a.applicationDirPath());

    MainWindow w;
    w.setWindowIcon(QIcon(":/icons/qvk.ico"));
    w.show();
    return a.exec();
}
