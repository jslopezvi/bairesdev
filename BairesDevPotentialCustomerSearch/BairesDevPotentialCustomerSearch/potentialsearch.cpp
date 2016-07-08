// Developed by Juan Sebastian Lopez Villa for exclusive use in BairesDev recruitment process
// jslopezvilla@gmail.com - 2016

#include "potentialsearch.h"

#include <QApplication>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QHash>
#include <QtSql>

// Parse file line
void BairesWindow::parseLineFields(QString fileLine, QVector<QString> &sequence) {
    QRegularExpression re("(.*?)\\s\\|");
    QRegularExpressionMatchIterator i = re.globalMatch(fileLine); 
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();        
        sequence.push_back(match.captured(1));        
    }
}

// Insert item into database
void BairesWindow::addProfile(QSqlQuery &q,
                QString publicProfileURL,
                QString name,
                QString lastName,
                QString title,
                QString geographicArea,
                int numberOfRecommendations,
                int numberOfConnections,
                QString currentRole,
                QString industry,
                QString country)
{
    q.addBindValue(publicProfileURL);
    q.addBindValue(name);
    q.addBindValue(lastName);
    q.addBindValue(title);
    q.addBindValue(geographicArea);
    q.addBindValue(numberOfRecommendations);
    q.addBindValue(numberOfConnections);
    q.addBindValue(currentRole);
    q.addBindValue(industry);
    q.addBindValue(country);

    q.exec();
}

// Main window constructor
BairesWindow::BairesWindow()
{
    ui.setupUi(this);

    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        QMessageBox::critical(this, "Unable to load database", "This demo needs the SQLITE driver");

    // Initialize the database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");

    if (!db.open())
        return;

    QStringList tables = db.tables();
    if (tables.contains("profiles", Qt::CaseInsensitive))
        return;

    QSqlQuery q;
	// Create profiles table
    if (!q.exec(QLatin1String("create table profiles(id integer primary key, "
                              "linkedin_profile text, "
                              "name text, "
                              "last_name text, "
                              "title text, "
                              "geographic_area text, "
                              "recommendations_count integer, "
                              "connections_count integer, "
                              "current_role text, "
                              "industry text, "
                              "country text "
                              ")"))) {
        return;
    }

	// Prepare insert query
    if (!q.prepare(QLatin1String("insert into profiles("
                                 "linkedin_profile, "
                                 "name, "
                                 "last_name, "
                                 "title, "
                                 "geographic_area, "
                                 "recommendations_count, "
                                 "connections_count, "
                                 "current_role, "
                                 "industry, "
                                 "country"
                                 ")"
                                 "values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"))) {
        return;
    }   

	// Begin to read data from text file
    QFile inputFile(":/PeopleToRate.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QVector<QString> sequence;
            parseLineFields(line, sequence);
        
            // 0 PublicProfileURL
            // 1 Name
            // 2 LastName
            // 3 Title            
            // 4 GeographicArea            
            // 5 NumberOfRecommendations
            // 6 NumberOfConnections
            // 7 CurrentRole and Industry            
            // 8 Industry            
            // 9 Country            

			// Add register to database
            addProfile(q,
                        sequence.at(0),
                        sequence.at(1),
                        sequence.at(2),
                        sequence.at(3),
                        sequence.at(4),
                        sequence.at(5).toInt(),
                        sequence.at(6).toInt(),
                        sequence.at(7),
                        sequence.at(8),
                        sequence.at(9));
        }        
    }

    // Create the data model
    model = new QSqlRelationalTableModel(ui.customersTable);
    model->setTable("profiles");

    // Set the header captions
    model->setHeaderData(model->fieldIndex("linkedin_profile"), Qt::Horizontal, tr("PublicProfileURL"));
    model->setHeaderData(model->fieldIndex("name"), Qt::Horizontal, tr("Name"));
    model->setHeaderData(model->fieldIndex("last_name"), Qt::Horizontal, tr("LastName"));
    model->setHeaderData(model->fieldIndex("title"), Qt::Horizontal, tr("Title"));
    model->setHeaderData(model->fieldIndex("geographic_area"), Qt::Horizontal, tr("GeographicArea"));
    model->setHeaderData(model->fieldIndex("recommendations_count"), Qt::Horizontal, tr("Recommendations"));
    model->setHeaderData(model->fieldIndex("connections_count"), Qt::Horizontal, tr("Connections"));
    model->setHeaderData(model->fieldIndex("current_role"), Qt::Horizontal, tr("Current Role"));
    model->setHeaderData(model->fieldIndex("industry"), Qt::Horizontal, tr("Industry"));
    model->setHeaderData(model->fieldIndex("country"), Qt::Horizontal, tr("Country"));

    // Populate the model
    if (!model->select()) {
        qDebug() << "Error:" << model->lastError();
        return;
    }

    // Set the model and hide the ID column
    ui.customersTable->setModel(model);    
    ui.customersTable->setColumnHidden(model->fieldIndex("id"), true);  
    ui.customersTable->setCurrentIndex(model->index(0, 0));   
    ui.customersTable->horizontalHeader()->setStretchLastSection(true);
    ui.customersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	// Query main industries
    QSqlQuery query(db);	
    query.exec("select distinct industry, count(industry) from profiles group by industry order by count(industry) desc");

	// Populate combobox
    while (query.next()) {
        QString name = query.value(0).toString();
        industryList << name;
    }

    ui.filterByCombo->addItems(industryList);

	// Ugly part, just hidding test components used for development of queries
    ui.executeQueryButton->setVisible(false);
    ui.groupBox_2->setVisible(false);
    ui.customersTable->setVisible(false);
}

void BairesWindow::runQuery(QString queryString) {
    QSqlQueryModel *model = new QSqlQueryModel(ui.resultsTable);
    QSqlQuery q(queryString, db);    
    model->setQuery(q);

    if (model->lastError().type() != QSqlError::NoError) {
        qDebug() << model->lastError().text();
        qDebug() << tr("Query Error.");
    } else if (model->query().isSelect())
        qDebug() << tr("Query OK");
    else
        qDebug() << tr("Query OK, number of affected rows: %1").arg(model->query().numRowsAffected());

    ui.resultsTable->setModel(model);
    ui.resultsTable->horizontalHeader()->setStretchLastSection(true);
    ui.resultsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

// Business logic here, is just a simple query.
void BairesWindow::on_rankButton_pressed()
{
    QString currentIndustry = industryList.at(ui.filterByCombo->currentIndex());
    QString queryString =
            "select * from profiles where industry like \"%"+currentIndustry+"%\" "
            "and ("
            "title like \"%owner%\" or title like \"%ceo%\" or title like \"%director%\" or title like \"%founder%\" or title like \"%cto%\" "
            "or "
            "current_role like \"%owner%\" or current_role like \"%director%\" or current_role like \"%founder%\" or current_role like \"%cto%\" "
            ") "
            "ORDER BY case when title like \"%owner%\" then 1 "
            "when title like \"%ceo%\" then 2 "
            "when title like \"%director%\" then 3 "
            "when title like \"%founder%\" then 4 "
            "when title like \"%cto%\" then 5 "
            "else 5 "
            "end asc, "
            "case when country like \"%United States%\" then 1 "
            "when title like \"%Germany%\" then 2 "
            "when title like \"%United Kingdom%\" then 3 "
            "when title like \"%Canada%\" then 4 "
            "when title like \"%China%\" then 5 "
            "when title like \"%Argentina%\" then 6 "
            "else 7 "
            "end asc, "
            "recommendations_count desc, connections_count desc limit 30";

    runQuery(queryString);
}
