#include <iostream>
using namespace std;

class JaggedArr {
private:
    int** array;
    int* rowSizes;
    int totalRows;

public:
    JaggedArr(int rows) : totalRows(rows) {
        array = new int*[totalRows];
        rowSizes = new int[totalRows];
        
        for (int i = 0; i < totalRows; i++) {
            rowSizes[i] = 0;
            array[i] = nullptr;
        }
    }

    ~JaggedArr() {
        for (int i = 0; i < totalRows; i++) {
            delete[] array[i];
        }
        delete[] array;
        delete[] rowSizes;
    }

    void setRowSize(int row, int size) {
        if (row < 0 || row >= totalRows) return;
        
        if (array[row] != nullptr) {
            delete[] array[row];
        }
        
        rowSizes[row] = size;
        array[row] = new int[size];
        
        for (int i = 0; i < size; i++) {
            array[row][i] = 0;
        }
    }

    void setValue(int row, int col, int value) {
        if (row < 0 || row >= totalRows || col < 0 || col >= rowSizes[row]) return;
        array[row][col] = value;
    }

    int getValue(int row, int col) const {
        if (row < 0 || row >= totalRows || col < 0 || col >= rowSizes[row]) return -1;
        return array[row][col];
    }

    int getRowSum(int row) const {
        if (row < 0 || row >= totalRows) return 0;
        
        int sum = 0;
        for (int i = 0; i < rowSizes[row]; i++) {
            sum += array[row][i];
        }
        return sum;
    }

    void display() const {
        for (int i = 0; i < totalRows; i++) {
            cout<<"Team "<<i + 1<<" ("<<rowSizes[i]<<" players): ";
            for (int j = 0; j < rowSizes[i]; j++) {
                cout<<array[i][j]<<" ";
            }
            cout<<"- Sum: "<<getRowSum(i)<<endl;
        }
    }

    int getTotalRows() const {
        return totalRows;
    }

    int getRowSize(int row) const {
        if (row < 0 || row >= totalRows) return 0;
        return rowSizes[row];
    }
};

int main() {
    int numTeams;
    cout<<"Enter number of teams: ";
    cin >> numTeams;

    JaggedArr teams(numTeams);

    for (int i = 0; i < numTeams; i++) {
        int teamSize;
        cout<<"Enter number of players in team "<<i + 1<<": ";
        cin >> teamSize;
        
        teams.setRowSize(i, teamSize);
        
        cout<<"Enter scores for team "<<i + 1<<" ("<<teamSize<<" players): ";
        for (int j = 0; j < teamSize; j++) {
            int score;
            cin >> score;
            teams.setValue(i, j, score);
        }
    }
    cout<<"\nTeam Scores and Sums:"<<endl;
    teams.display();
    cout<<"\nIndividual Team Sums:"<<endl;
    for (int i = 0; i < numTeams; i++) {
        cout<<"Team "<<i + 1<<" sum: "<<teams.getRowSum(i)<<endl;
    }
    return 0;
}