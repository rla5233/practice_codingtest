#include <string>
#include <sstream>
#include <map>

std::string solution(std::string Letter) 
{
    std::map<std::string, std::string> Morse = 
    { 
        {".-","a"}, {"-...","b"}, {"-.-.","c"}, {"-..","d"}, {".","e"}, {"..-.","f"},
        {"--.","g"}, {"....","h"}, {"..","i"}, {".---","j"}, {"-.-","k"}, {".-..","l"},
        {"--","m"}, {"-.","n"}, {"---","o"}, {".--.","p"}, {"--.-","q"}, {".-.","r"},
        {"...","s"}, {"-","t"}, {"..-","u"}, {"...-","v"}, {".--","w"}, {"-..-","x"},
        {"-.--","y"}, {"--..","z"}
    };

    std::string Result = "", Temp = "";
    std::stringstream SS(Letter);
    while (SS >> Temp)
    {
        Result += Morse[Temp];
    }

    return Result;
}