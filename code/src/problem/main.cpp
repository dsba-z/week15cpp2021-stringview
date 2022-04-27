#include <iostream>
#include <fstream>
#include <string_view>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>


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
            lineStart = i;
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
            lineStart = i;
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

int main()
{

    // the size of the book is 160000+ symbols
    const char* path = "../../data/alice.txt";
    std::ifstream textFile(path);

    char buffer[150001];
    textFile.read(buffer, 150000);
    
    runStdString(buffer);
    
    runStdStringView(buffer);
    
    return 0;
}
