#include <iostream>
#include <fstream>
#include <string_view>
#include <string>
#include <cstring>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>

// line is shorter than 50 symbols
// the first characters is 'A'
bool isLineGood(const std::string& line)
{
    if (line[0] == 'A' && line.size() < 50)
    {
        return true;
    }
    return false;
}




void collectLines(const std::string& text, std::vector<std::string>& lineBag)
{
    int lineLength = 0;
    int lineStart = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        char c = text[i];
        if (c == '\n')
        {
            lineBag.push_back(text.substr(lineStart, lineLength));
            lineLength = 0;
            lineStart = i+1;
        }
        else
        {
            lineLength += 1;
        }
    }
}


void collectLinesSv(std::string_view text, std::vector<std::string_view>& lineBag)
{
    int lineLength = 0;
    int lineStart = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        char c = text[i];
        if (c == '\n')
        {
            lineBag.push_back(text.substr(lineStart, lineLength));
            lineLength = 0;
            lineStart = i+1;
        }
        else
        {
            lineLength += 1;
        }
    }
}


void runStdString(const char* buffer)
{
    std::vector<std::string> lineVector;
    
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    
    collectLines(buffer, lineVector);
    
    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
    
}


void runStdStringView(const char* buffer)
{
    std::vector<std::string_view> wordSetSv;
    

    std::clock_t c_start2 = std::clock();
    auto t_start2 = std::chrono::high_resolution_clock::now();
    
    collectLinesSv(buffer, wordSetSv);
    
    std::clock_t c_end2 = std::clock();
    auto t_end2 = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end2 - c_start2) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end2-t_start2).count()
              << " ms\n";
}



void checkGoodLines(const char* buffer)
{
    std::vector<std::string> wordSet;
    collectLines(buffer, wordSet);
    
    int counter = 0;

    std::clock_t c_start2 = std::clock();
    auto t_start2 = std::chrono::high_resolution_clock::now();
    
    // checking all lines
    for(const std::string& line: wordSet)
    {
        if (isLineGood(line))
        {
            std::cout << line << std::endl;
            counter++;
        }
    }
    
    std::clock_t c_end2 = std::clock();
    auto t_end2 = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end2 - c_start2) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end2-t_start2).count()
              << " ms\n";
    
    std::cout << counter << std::endl;
}



void task0()
{
    // the size of the book is 160000+ symbols
    const char* path = "../../data/alice.txt";
    std::ifstream textFile(path);

    char buffer[150001];
    textFile.read(buffer, 150000);
    
    runStdString(buffer);
    
    runStdStringView(buffer);
    
    checkGoodLines(buffer);

}



//void task1()
//{
//    if (isLineGood())
//    {
//        std::cout << "first line is good";
//    }
    
//    std::string secondLine("Not a good line");
//    if (!isLineGood())
//    {
//        std::cout << "second line is not good";
//    }
    
//}



int main()
{
    
    std::string example("string");
    
    const char* pointer = example.c_str();
    
    
    int a = strlen("asdasdasd");
    task0();
//    task1();

    return 0;
}
