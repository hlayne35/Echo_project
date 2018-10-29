#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <regex>

static std::random_device rd;
static std::mt19937 rng(rd()); 

int d20()
{
    static std::uniform_int_distribution<int> uid(1,20);
    return uid(rng);
}

std::string magic8ball()
{
    switch (d20())
    { 
        case 1:
            return "It is certain.";
        case 2:
            return "As I see it, yes.";
        case 3:
            return "Reply hazy, try again.";
        case 4:
            return "Don't count on it.";
        case 5:  ;
            return "It is decidedly so.";
        case 6:
            return "Most likely.";
        case 7:  ;
            return "Ask again later.";
        case 8:  ;
            return "My reply is no.";
        case 9:  ;
            return "Without a doubt.";
        case 10:
            return "Outlook is good.";
        case 11:  ;
            return "Better not tell you now.";
        case 12:  ;
            return "My sources say no.";
        case 13:  ;
            return "Definitely.";
        case 14:
            return "My reply is yes.";
        case 15:  ;
            return "Cannot predict now.";
        case 16:  ;
            return "Outlook is not so good.";
        case 17:  ;
            return "You can count on it.";
        case 18:
            return "Signs point to yes.";
        case 19:  ;
            return "Concentrate and ask again.";
        case 20:  ;
            return "Very doubtful.";
        default:
            return "Error.";
    }
}

int main()
{
    std::string x;
    std::cout << std::endl;
    std::cout << "(Type \"Goodbye Echo\" to exit the Echo game)" << std::endl;
    std::cout << std::endl;
    std::cout << "*Talk to me!*" << std::endl;
    std::regex dadjoke_regex("(I'm|I am)(.*)", std::regex::icase);
    std::smatch dadjoke_match;
    std::regex hhgttg_regex("What is the meaning of life?", std::regex::icase);
    std::smatch hhgttg_match;
    std::regex magic8ball_regex("\\?$", std::regex::icase);
    std::smatch magic8ball_match;
    
    do{
        std::getline (std::cin,x);
        
        if(x == "Goodbye Echo")
        {
            break;
        }
        if(std::regex_search (x, dadjoke_match, dadjoke_regex))
        {
            std::cout << "*Hello" << dadjoke_match[2] << ", I'm Dad*" << std::endl;
            x.clear();
            continue;
        }
        if(std::regex_search (x, hhgttg_match, hhgttg_regex))
        {
            std::cout << "*The meaning of life is 42*" << std::endl;
            x.clear();
            continue;
        }
        if(std::regex_search (x, magic8ball_match, magic8ball_regex))
        {
            std::cout << "*" << magic8ball() << "*" << std::endl;
            x.clear();
            continue;
        }
        std::cout << "*" << x << "*" << std::endl;
        x.clear();    
        
    }while(x.empty());
    
    return 0;
}