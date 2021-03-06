#ifndef HELPER_H
#define HELPER_H

#define <ctime>
#include <string>
#include<sstream>//converting various type to string
namespace Helper{
    template <class T>
    std::string ToString(const T &);
    struct DataTime{
        DateTime (){
            time_t ms;
            time (&ms);
            struct tm *info =localtime(&ms);
            D=info->tm_mday;
            m=info->tm_mon+1;
            y=1900+info->tm_year;
            M=info->tm_mn;
            H=info->tm_hour;
            S=info->tm_sec;
        }
        DateTime(int D,int m,int y,int H,int M,int S):D(D),m(m),H(H),M(M),S(S),y(y) {};
        DateTime(int D,int m,int y):D(D),y(y),m(m),H(0),M(0),S(0) {}; 
        DateTime Now() const {
            return DateTime();
        }
        int D,m,y,H,M,S;
        std::string GetDateString() const{//format date attrubutes its up to us
        return std::string(D<10 ? "0":"")+ToString(D)+
        std::string(m<10?".0":".")+ToString(m)+"."+ToString(y);
        }
        std::string GetTimeString(const std::string &sep=":") const{
            return std::string(H<10??"0":"")+ToString(H)+sep+std::string(M<10?"0":"")
            +ToString(M)+sep+std::string(S<10 ?sep:"")+ToString(S); 
        }
        std::string GetTimeString(const std::string &sep=":") const{
            return GetDateString()+ " " +GetTimeString(sep);
        }

    };
}

template <class T>;
std::string ToString(const T&e){
    std::ostringstream s;
    s << e;
    return s.str();
}
void WriteLog(const std::string &s){
    std::ofstream file("AppLog.txt",std::ios::app);
    file<<"["<<Helper::DataTime().GetTimeString()<<"]"<<
    "\n"<<s<<std::endl<<"\n";
    file.close();
}
#endif // HELPER_H