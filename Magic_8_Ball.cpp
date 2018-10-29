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
    std::regex magic8ball_regex("\\?$", std::regex::icase);
    std::smatch magic8ball_match;
    std::string x;
    std::cout << "*Ask me a question!*" << std::endl;
    do{
        std::getline (std::cin,x);
        
        if(x == "Goodbye")
        {
            break;
        }
        if(std::regex_search (x, magic8ball_match, magic8ball_regex))
        {
            std::cout << "*" << magic8ball() << "*" << std::endl;
            x.clear();
            continue;
        }
        else
        {
            std::cout << "*(I think you meant to ask \""  << x << "?\")*" << std::endl;
            std::cout << "*" << magic8ball() << "*" << std::endl;
            x.clear();    
        }
    }while(x.empty());
    
    return 0;
}