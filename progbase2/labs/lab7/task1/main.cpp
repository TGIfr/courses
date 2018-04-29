#include <iostream>
#include <progbase-cpp/net.h>

using namespace std;
using namespace progbase::net;
int main(){

    TcpClient client;
    NetMessage message(100);
    std::string subResStr = "";
    try {
        client.connect(IpAddress(Ip::resolveHostname("api.github.com"), 80));
        message.setDataString("GET / HTTP/1.1\r\n Host: api.github.com \r\n\r\n");
        client.send(message);
        cout << ">> Request sent" << endl;
        do {
            client.receive(message);
            std::string str = message.dataAsString();

            subResStr += str;
        } while (!message.isEmpty());
        cout << subResStr;
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    //string resString = subResStr.substr(subResStr.find("\n\n"));
    //cout << resString;
    return 0;
}



//#include <stdio.h>
//#include <curl/curl.h>
//#include <iostream>
//using namespace std;
//static int writer(char *data, size_t size, size_t nmemb, string *buffer)
//{
//    //переменная - результат, по умолчанию нулевая
//    int result = 0;
//    //проверяем буфер
//    if (buffer != NULL)
//    {
//        //добавляем к буферу строки из data, в количестве nmemb
//        buffer->append(data, size * nmemb);
//        //вычисляем объем принятых данных
//        result = size * nmemb;
//    }
//    //вовзращаем результат
//    return result;
//}
////главная функция
//int main(void)
//{
//    std::string buffer;
//    //уже знакомый объект CURL
//    CURL *curl;
//    //объект - результат вызова функции curl_easy_perform
//    CURLcode res;
//    //выполняем инициализацю
//    curl = curl_easy_init();
//    if(curl) { //проверяем
//        //задаем опцию - получить страницу по адресу http://google.com
//        curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com");
//        //указываем прокси сервер
//        //задаем опцию отображение заголовка страницы
//        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
//
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
//        //вызываем функцию, выполняющюю все операции, заданные в опциях (получение страницы, передача данных и т.д.), результат - объект типа CURLcode
//        res = curl_easy_perform(curl);
//        //выполняем обязательное завершение сессии
//        curl_easy_cleanup(curl);
//        if (res == CURLE_OK)
//            //выводим полученные данные на стандартный вывод (консоль)
//            std::cout << buffer << "\n";
//        else
//            //выводим сообщение об ошибке
//            std::cout << "Ошибка! \n";
//    }
//    return 0;
//}