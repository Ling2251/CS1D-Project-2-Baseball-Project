#include <vector>
#include <string>
#include <dbmanager.h>

using namespace std;

//bubble sort by stadium name
void bubbleSort(vector<team>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vec.at(i).stadiumName > vec.at(j + 1).stadiumName) {
        swap(vec[j], vec[j + 1]);
      }
    }
  }
}

int main(){

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
//    cout << element.stadiumName << " "  << element.teamName << endl;
// }

return 0;
}
