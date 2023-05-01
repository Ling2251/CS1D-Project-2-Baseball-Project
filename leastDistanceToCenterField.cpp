#include <vector>
#include <string>
#include <dbmanager.h>
int main(){
  
  //vector of "team" class
  vector<team> teams;   

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
    //distance to center field
    currTeam.distanceToCenterField = query.value(7).toInt();   
    teams.push_back(currTeam);
  }
  int n = teams.size();
  int min = teams.at(0).distanceToCenterField;
  //vector of minimum value indexes
  vector<int> min_indexes = { 0 };
  //finds minimum distance to center field and duplicate indexes
  for (int i = 1; i < n; i++) {
    if (teams.at(i).distanceToCenterField < min) {
      min = teams.at(i).distanceToCenterField;
      min_indexes = { i };
    } else if (teams.at(i).distanceToCenterField == min) {
      min_indexes.push_back(i);
    }
  }
  
 //to test  
 // cout << "The minimum distance to center field is: " << min << endl;
 // cout << "The stadiums and teams with the minimum distance are: ";
 // for (int i = 0; i < min_indexes.size(); i++) {
 //   cout << teams.at(i).stadiumName << " " << teams.at(i).teamName << endl;
 // }
}


