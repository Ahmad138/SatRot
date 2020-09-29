#include "includes/timekeeperworker.h"

TimeKeeperWorker::TimeKeeperWorker(QObject *parent, QString endpoint, int start, int stop) : QObject(parent)
{
    url = endpoint;
    m_start=start;
    m_stop=stop;
    count = ceil((stop-start)/300);

    QTimer *timerT = new QTimer();
    connect(timerT, SIGNAL(timeout()), this, SLOT(Timer()));
    timerT->start(250);
}

void TimeKeeperWorker::Timer(){
    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime myDateTime;
    QJsonArray l = positions.value("positions").toArray();

    if(m_start-15 == UTC.toSecsSinceEpoch()){
        getSatPos();
    }else if(m_start <= UTC.toSecsSinceEpoch() && m_stop >= UTC.toSecsSinceEpoch()){

        for (int i = 1; i < l.size(); i++) {
            if(positions.value("positions")[i]["timestamp"].toInt() == UTC.toSecsSinceEpoch()){

                QString a = QString::number(positions.value("info")["satid"].toInt());
                QString b = positions.value("info")["satname"].toString();

                QString c = QString::number(positions.value("positions")[i]["satlatitude"].toDouble())+"°";
                QString d = QString::number(positions.value("positions")[i]["satlongitude"].toDouble())+"°";
                QString e = QString::number(positions.value("positions")[i]["sataltitude"].toDouble())+" Km";
                QString f = QString::number(positions.value("positions")[i]["azimuth"].toDouble())+"°";
                QString g = QString::number(positions.value("positions")[i]["elevation"].toDouble())+"°";
                QString h = QString::number(positions.value("positions")[i]["ra"].toDouble())+"°";
                QString j = QString::number(positions.value("positions")[i]["dec"].toDouble())+"°";
                myDateTime.setTime_t(positions.value("positions")[i]["timestamp"].toInt());
                QString k = myDateTime.toString("ddd dd-MMM-yyyy hh:mm:ss");

            }
        }

    }

    if((m_stop-(count*285)) > UTC.toSecsSinceEpoch()){
        getSatPos();
    }
}

void TimeKeeperWorker::getSatPos()
{
    api *a = new api();

    //qDebug()<<url;
    a->initRequester(url, 80, nullptr);

    api::handleFunc getData = [this](const QJsonObject &o) {
        //cout << "Got data " << endl;
        positions = o;
        --count;
    };

    api::handleFunc errData = [](const QJsonObject &o) {
        //cout << "Error: connection dropped";
        QJsonObject x = o;
        QString r = "Error: connection dropped";
        qDebug()<< r;
    };

    a->sendRequest(url, getData, errData);

}
