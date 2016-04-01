#include "frame/mainwidget.h"
#include <QApplication>
#include <DLog>

using namespace Dtk::Util;

namespace {

const char kPlatformThemeName[] = "QT_QPA_PLATFORMTHEME";

}  // namespace

int main(int argc, char *argv[])
{
    // If platform theme name is empty, fallback to gtk2.
    // gtk2 theme is included in libqt5libqgtk2 package.
    if (qgetenv(kPlatformThemeName).length() == 0) {
      qputenv(kPlatformThemeName, "gtk2");
    }
    QApplication a(argc, argv);

    a.setOrganizationName("deepin");
    a.setApplicationName("deepin-image-viewer");
    a.setApplicationDisplayName("Deepin Image Viewer");

//    // install translators
//    QTranslator translator;
//    translator.load("/usr/share/deepin-viewer/translations/deepin-viewer_" + QLocale::system().name());
//    a.installTranslator(&translator);

    DLogManager::registerConsoleAppender();
    DLogManager::registerFileAppender();
    dInfo()<< "LogFile:" << DLogManager::getlogFilePath();

    MainWidget w;
    w.show();

    return a.exec();
}