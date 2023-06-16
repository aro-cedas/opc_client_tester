#include <QCoreApplication>
#include <opcclient.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OpcClient c;
    c.start();
    return a.exec();
}
