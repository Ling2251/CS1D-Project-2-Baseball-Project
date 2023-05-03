#include "sortmajorleaguenames.h"
#include "./ui_sortmajorleaguenames.h"
#include <vector>
#include <string>
//need to include "team" class
#include <dbmanager.h>

using namespace std;

//bubble sort by team name
void sortMajorLeagueNames::bubbleSort(vector<team>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vec.at(i).teamName > vec.at(j + 1).teamName) {
        swap(vec[j], vec[j + 1]);
      }
    }
  }
}

void sortMajorLeagueNames::sortTeamNames(){

//vector of "team" class
vector<team> teamVector;

//SQL query
QSqlQuery query;
query.exec("SELECT * FROM stadium_info");
while (query.next()) {
    //current team
    team currTeam;
    //team name
    currTeam.teamName = query.value(0).toString();
    //stadium name
    currTeam.stadiumName = query.value(1).toString();
    teamVector.push_back(currTeam);
}
//sort vector
bubbleSort(teamVector);

//to test
// for(const auto& element : teamVector) {
//    cout << element.teamName << " "  << element.stadiumName << endl;
// }

}

sortMajorLeagueNames::sortMajorLeagueNames(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sortMajorLeagueNames)
{
    ui->setupUi(this);
}

sortMajorLeagueNames::~sortMajorLeagueNames()
{
    delete ui;
}

