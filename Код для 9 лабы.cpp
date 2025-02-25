#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>

struct GroupStats {
    std::string groupName;
    double fiveStars; 
    double fourStars; 
    double threeStars; 
    double twoStars; 
    double passingRate; 
};

void calculateAverage(const std::vector<GroupStats>& groups,
    GroupStats& average) {
    double totalFiveStars = 0, totalFourStars = 0, totalThreeStars = 0,
        totalTwoStars = 0, totalPassingRate = 0;

    for (const auto& group : groups) {
        totalFiveStars += group.fiveStars;
        totalFourStars += group.fourStars;
        totalThreeStars += group.threeStars;
        totalTwoStars += group.twoStars;
        totalPassingRate += group.passingRate;
    }

    average.fiveStars = totalFiveStars / groups.size();
    average.fourStars = totalFourStars / groups.size();
    average.threeStars = totalThreeStars / groups.size();
    average.twoStars = totalTwoStars / groups.size();
    average.passingRate = totalPassingRate / groups.size();
}



int main(int argc, char* argv[])
{
    std::system("chcp 1251");
    std::string facultyName;
    int numberOfGroups;

    std::cout << "Введите наименование факультета: ";
    std::getline(std::cin, facultyName);

    std::cout << "Введите число групп: ";
    std::cin >> numberOfGroups;

    std::vector<GroupStats> groups(numberOfGroups);

    for (int i = 0; i < numberOfGroups; ++i) {
        std::cout << "Введите название группы " << (i + 1) << ": ";
        std::cin >> groups[i].groupName;

        std::cout << "Введите % пятёрок для группы " << groups[i].groupName << ": ";
        std::cin >> groups[i].fiveStars;

        std::cout << "Введите % четвёрок для группы " << groups[i].groupName << ": ";
        std::cin >> groups[i].fourStars;

        std::cout << "Введите % троек для группы " << groups[i].groupName << ": ";
        std::cin >> groups[i].threeStars;

        std::cout << "Введите % двоек для группы " << groups[i].groupName << ": ";
        std::cin >> groups[i].twoStars;

        
        groups[i].passingRate = groups[i].fiveStars + groups[i].fourStars + groups[i].threeStars;
    }

    
    GroupStats average;
    calculateAverage(groups, average);

    
    std::cout << "\nУспеваемость по факультету: " << facultyName << "\n";
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nГруппы:\n";
    for (const auto& group : groups) {
        std::cout << std::setw(15) << group.groupName
            << std::setw(10) << group.fiveStars
            << std::setw(10) << group.fourStars
            << std::setw(10) << group.threeStars
            << std::setw(10) << group.twoStars
            << std::setw(15) << group.passingRate << "\n";
    }

    
    std::cout << "\nСредние показатели по факультету:\n";
    std::cout << std::setw(15) << "Пятёрки"
        << std::setw(10) << "Четвёрки"
        << std::setw(10) << "Тройки"
        << std::setw(10) << "Двойки"
        << std::setw(15) << "Успеваемость" << "\n";

    std::cout << std::setw(15) << average.fiveStars
        << std::setw(10) << average.fourStars
        << std::setw(10) << average.threeStars
        << std::setw(10) << average.twoStars
        << std::setw(15) << average.passingRate << "\n";

    return 0;
}
