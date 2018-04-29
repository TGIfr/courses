#ifndef SUNDATA_H
#define SUNDATA_H

#include <string>
#include <qmetaobject.h>
using namespace std;
class SunData
{
private:
   int analyzeStr();
    void setup();
    string askTime();
    string askUtc();
    bool parseUtcJsonStr(std::string str);
    bool parseTimeJsonStr(std::string str);

    std::string sunrise;
    std::string sunset;
    std::string timeZoneId;
    std::string timeZoneName;
    int sunriseSeconds;
    int sunsetSeconds;
    std::string city;
    float lat;
    float lng;
    int UTCShiftSeconds;


public:
    SunData();
    SunData(string city, float latitude, float length);
    time_t GetTimeSeconds();
    time_t GetTimeSinceMidnightSeconds();
    std::string GetLocalTime();
    std::string GetSunrise();
    std::string GetSunset();
    std::string GetTimeZoneId();
    std::string GetTimeZoneName();
    int GetSunriseSeconds();
    int GetSunsetSeconds();
    std::string GetCity();
    float GetLat();
    float GetLng();
    std::string GetUTCShift();
    int GetUTCShiftSeconds();
};
Q_DECLARE_METATYPE(SunData )
#endif // SUNDATA_H
