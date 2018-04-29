#include "sundata.h"
#include <string>
#include <time.h>
#include <QDebug>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <stdio.h>

using namespace std;
SunData::SunData(){};

SunData::SunData(string city, float latitude, float length)
{
    this->city = city;
    this->lat = latitude;
    this->lng = length;
    setup();
}
bool SunData::parseUtcJsonStr(std::string str){
    QJsonDocument jdoc = QJsonDocument::fromJson(QString::fromStdString(str).toUtf8());
    if (jdoc.isObject()) {
        QJsonObject jobj = jdoc.object();
        std::string status = jobj["status"].toString().toStdString();
        if(status.compare("OK") == 0){

            auto utcShift = jobj["rawOffset"].toInt() + jobj["dstOffset"].toInt();
            this->UTCShiftSeconds = utcShift;
            this->timeZoneId = jobj["timeZoneId"].toString().toStdString();
            this->timeZoneName = jobj["timeZoneName"].toString().toStdString();
            return true;
        } else
            return false;
    } else {
        return false;
    }
}

bool SunData::parseTimeJsonStr(std::string str){
    QJsonDocument jdoc = QJsonDocument::fromJson(QString::fromStdString(str).toUtf8());
    if (jdoc.isObject()) {
        QJsonObject jobj = jdoc.object();
        std::string status = jobj["status"].toString().toStdString();

        if(status.compare("OK") == 0){
            auto results = jobj["results"].toObject();
            auto sunriseRaw = results["sunrise"].toString().toStdString();
            auto sunsetRaw = results["sunset"].toString().toStdString();
            qDebug() << "Data received time";
            this->sunrise = sunriseRaw;
            this->sunset = sunsetRaw;
            //for seconds setter
            int timeHours = 0;
            int timeMinutes = 0;
            int timeSeconds = 0;
            if( sscanf(sunriseRaw.c_str(), "%d:%d:%d", &timeHours, &timeMinutes, &timeSeconds) < 3){
               qDebug() << "parse time sunrise setting error   " << QString::fromStdString(str) ;
                return false;
            }

            std::size_t found = sunriseRaw.find("PM");
            if (found!=std::string::npos){
               timeHours += 12;
            }
            this->sunriseSeconds = timeHours * 60 * 60 + timeMinutes * 60 + timeSeconds;

            if(sscanf(sunsetRaw.c_str(), "%d:%d:%d", &timeHours, &timeMinutes, &timeSeconds) < 3){
                qDebug() << "parse time sunset setting error";
                return false;
            }

            found = sunsetRaw.find("PM");
            if (found!=std::string::npos){
               timeHours += 12;
            }
            this->sunsetSeconds = timeHours * 60 * 60 + timeMinutes * 60 + timeSeconds;


            return true;
        } else
        {
            qDebug() << "parse time wrong status";
            return false;
        }

    } else  {
        qDebug() << "parse time not object";
        return false;
    }
}

void SunData::setup(){
    //http calls(one for sunrise sunset, other for utc shift)
    //analyzing
    //setting shift, sunrise, sunset, previous 2 in seconds, shift

    // network getters
    string timeJsonStr = askTime();
    string utcJsonStr = askUtc();
    if(timeJsonStr.compare("ERROR") == 0 || utcJsonStr.compare("ERROR") == 0 ){
        // leaves all fields empty, after that class should be checked and not added to list
        this->city = "ERROR";
        return;
    }

    // json parsers : setts appropriate fields or leave them empty
    if(!parseTimeJsonStr(timeJsonStr) ){
        qDebug() << "ERRORS WITH PARSING TIME OCCURED";
        this->city = "ERROR";
        return;
    }
    if(!parseUtcJsonStr(utcJsonStr)){
        qDebug() << "ERRORS WITH PARSING UTC OCCURED";
        this->city = "ERROR";
        return;
    }


}
string SunData::askTime(){
    string result;
    try {
           curlpp::Cleanup myCleanup;
           string url = "https://api.sunrise-sunset.org/json?lat=";
           url += std::to_string(this->lat) ;
           url += "&lng=" ;
           url += std::to_string(this->lng);
           //qDebug() << QString::fromStdString(url);
           curlpp::options::Url myUrl(url);
           curlpp::Easy myRequest;
           myRequest.setOpt(myUrl);

           std::ostringstream os;
           os << myRequest;
           result = os.str();
       } catch( curlpp::RuntimeError &e ) {
           qDebug() << e.what();
           return "ERROR";
       } catch( curlpp::LogicError &e ) {
           qDebug() << e.what();
           return "ERROR";
       }
   // qDebug() << QString::fromStdString(result);
    return result;
}
string SunData::askUtc(){
    string result;
    try {
           curlpp::Cleanup myCleanup;
           string url = "https://maps.googleapis.com/maps/api/timezone/json?location=";
           url += std::to_string((int)this->lat) ;
           url += "," ;
           url += std::to_string((int)this->lng);
           url += "&timestamp=";
           url += std::to_string(time(0));
           url += "&key=AIzaSyA61GBAbkHvAjBkazo7Kuy7XYi_1As7xOw";
           qDebug() <<"url" << QString::fromStdString(url);
           curlpp::options::Url myUrl(url);
           curlpp::Easy myRequest;
           myRequest.setOpt(myUrl);

           std::ostringstream os;
           os << myRequest;
           result = os.str();
       } catch( curlpp::RuntimeError &e ) {
           qDebug() << e.what();
           return "ERROR";
       } catch( curlpp::LogicError &e ) {
           qDebug() << e.what();
           return "ERROR";
       }
    qDebug() << QString::fromStdString(result);
    return result;
}

int SunData::GetSunriseSeconds(){
    return this->sunriseSeconds;
}

int SunData::GetSunsetSeconds(){
    return this->sunsetSeconds;
}

time_t SunData::GetTimeSeconds(){
    //getting local time - 2*60*60
    //adding seconds according to UTCShift
    //returning
    time_t timeUTCZero = time(0) - 3*60*60;

    return timeUTCZero + this->UTCShiftSeconds ;
}

std::string SunData::GetLocalTime(){
    //get time seconds method
    //converting it to str
    time_t localtime = GetTimeSeconds();

    return ctime(&localtime);
}
std::string SunData::GetSunrise(){
    return sunrise;
}

std::string SunData::SunData::GetSunset(){
    return sunset;
}

std::string SunData::GetTimeZoneId(){
    return this->timeZoneId;
}

std::string SunData::GetTimeZoneName(){
    return this->timeZoneName;
}

int SunData::GetUTCShiftSeconds(){
    return this->UTCShiftSeconds;
}

time_t SunData::GetTimeSinceMidnightSeconds(){
    time_t curTime = this->GetTimeSeconds();
    struct tm tms;
    time_t t2;
    localtime_r(&curTime, &tms);
    tms.tm_hour = 0;
        tms.tm_min = 0;
        tms.tm_sec = 0;
        t2 = mktime(&tms);
        return curTime - t2;
}

std::string SunData::GetCity(){
    return city;
}
float SunData::GetLat(){
    return lat;
}

float SunData::GetLng(){
    return lng;
}

std::string SunData::GetUTCShift(){
    return std::to_string(UTCShiftSeconds) ;
}
