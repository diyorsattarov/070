#include <QSqlDatabase>
#include <QDebug>

QSqlDatabase db = QSqlDatabase::addDatabase("DRIVER_NAME"); // Replace DRIVER_NAME with your database driver (e.g., QMYSQL, QPSQL)
db.setHostName("nginx-proxy"); // Use the service name as defined in docker-compose
db.setPort(8080); // Port on which Nginx is listening
db.setDatabaseName("your_db_name");
db.setUserName("username");
db.setPassword("password");

if (!db.open()) {
    qDebug() << "Error: Unable to connect to database.";
}
