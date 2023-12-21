// mysql_qt.cpp
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    if (argc != 2) {
        qCritical() << "Usage:" << argv[0] << "<query>";
        return 1;
    }

    QString queryStr = argv[1];

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // or the appropriate host
    db.setUserName("root");
    db.setPassword("rootpassword");
    db.setDatabaseName("my-db");

    if (!db.open()) {
        qCritical() << "Failed to open database:" << db.lastError().text();
        return 1;
    }

    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qCritical() << "Failed to execute query:" << query.lastError().text();
        return 1;
    }

    while (query.next()) {
        qDebug() << "Result:" << query.value(0).toString();
    }

    return 0;
}
