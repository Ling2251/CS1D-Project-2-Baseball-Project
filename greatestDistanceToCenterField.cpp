#include <vector>
#include <string>
#include <dbmanager.h>
int main(){

  vector<team> teams;

  //SQL query
  QSqlQuery query;
  query.exec("SELECT * FROM stadium_info");   
  while (query.next()) {
    team currTeam;
    currTeam.teamName = query.value(0).toString();
    currTeam.stadiumName = query.value(1).toString();
    currTeam.distanceToCenterField = query.value(7).toInt();   
    teams.push_back(currTeam);
  }
  int n = teams.size();
  int max = teams.at(0).distanceToCenterField;
  vector<int> max_indexes = { 0 };
  for (int i = 1; i < n; i++) {
    if (teams.at(i).distanceToCenterField > max) {
      max = teams.at(i).distanceToCenterField;
      max_indexes = { i };
    } else if (teams.at(i).distanceToCenterField == max) {
      max_indexes.push_back(i);
    }
  }
 // cout << "The minimum distance to center field is: " << min << endl;
 // cout << "The stadiums and teams with the minimum distance are: ";
 // for (int i = 0; i < min_indexes.size(); i++) {
 //   cout << teams.at(i).stadiumName << " " << teams.at(i).teamName << endl;
 // }
}


