#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

bool validMove(vector <vector <int> > table, int a, int b, int entry){
    
    int n = table.size();
    loop(i,0,n){
        if(table[i][b] == entry) return false;
    }
    
    loop(j,0,n){
        if(table[a][j] == entry) return false;
    }
    
    //,j = (b / 3) * 3;
    int adash = (a / 3),bdash = (b / 3);
    for(int i = (a / 3) * 3;i < (adash+1)*3;i++){
        for(int j = (b / 3) * 3;j < (bdash+1) * 3;j++){
        	  //cout << i << " " << j << endl;
            if(table[i][j] == entry) return false;
        }
    }
    return true;
}

bool sudokuUtil(vector <vector <int> > &table, int column, int row){
    
    int n = table.size();
    if(column == n){
    	
    	//cout << "in here:\n" << row << " "  << column << endl;
    	return true;
    }
    if(table[row][column] != 0){
        if(row == n-1) return sudokuUtil(table,column+1,0);
        else return sudokuUtil(table,column,row+1);
    }
    
    for(int i = 1;i <= n;i++){
        
        if(validMove(table,row,column,i)){
            table[row][column] = i;
            
            if(row == n-1){
                if(sudokuUtil(table,column+1,0)){
                    return true;
                }
            }
            else {
                if(sudokuUtil(table,column,row+1))
                    return true;
            }
            
            table[row][column] = 0;
        }
    }
    
    cout << "row:" << row << " column:" << column << endl;
    return false;
}

bool sudoku(vector <vector <int> > table){

    bool answer = sudokuUtil(table,0,0);
    
    vector <int> validRows
    
    loop(i,0,table.size()){
        loop(j,0,table.size()){
            cout << table[i][j] << " ";
        }
        //cout << endl;
    }
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(k,0,t){
	
	    int n = 9;
	    vector <vector <int> > table;
	    loop(i,0,n){
	        vector <int> row(n);
	        loop(j,0,n){
    	        cin >> row.at(j);
	        }
	        table.push_back(row);
	    }
	    //cout << validMove(table,2,0,2);
	    cout << sudoku(table) << endl;
	}
	return 0;
}

