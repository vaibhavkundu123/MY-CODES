// PREFIX SUM (1-D ARRAY) TO SHORT DOWN TIME COMPLExITY 
// TIME COMPLEXITY FROM O(N x Q) IS REDUCED TO O(N) + O(2Q)
// SIZE OF ARRAY (N) = 3
// ARRAY ELEMENTS (arr) = 1 4 1
// NUMBER OF QUERIES (Q) = 3 ie., (1,1) , (1,2) , (0,2)

// USE CUMULATIVE SUM CONCEPT TO REDUCE THE TIME COMPLEXITY

/* #include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int index = 0; index < n; index++)
    {
        cin >> arr[index];
    }

    vector<int> cum_arr(n,0);
    cum_arr[0] = arr[0];
    for(int index = 1; index < n; index++)
    {
        cum_arr[index] = cum_arr[index - 1] + arr[index];
    }

    int q;
    cin >> q;
    while(q--)
    {
        int start, end;
        cin >> start >> end;
        if(start == 0)
        {
            cout << cum_arr[end] << endl;
        }
        else
        {
            cout << cum_arr[end] - cum_arr[start - 1] << endl;
        }
    }
    
    return 0;
} */




// PREFIX SUM (2-D ARRAY)
// MATRIX EXAMPLE :-    1     5     3
//                      7     6     2
//                      4     9     8
// USE SAME LOGIC AS BEFORE

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols,0));

    for(int row_index = 0; row_index < rows; row_index++) {
        for(int col_index = 0; col_index < cols; col_index++) {
            cin >> matrix[row_index][col_index];
        }
    }

    vector<vector<int>> cum_matrix(rows, vector<int>(cols,0));

    // CUMULATIVE SUM WITH TIME COMPLEXITY O(ROW^2 x COLUMN^2)

    /* for(int cum_row_index = 0; cum_row_index < rows; cum_row_index++) {
        for(int cum_col_index = 0; cum_col_index < cols; cum_col_index++) {
            int sum = 0;
            for(int row_index = 0; row_index <= cum_row_index; row_index++) {
                for(int col_index = 0; col_index <= cum_col_index; col_index++) {
                    sum += matrix[row_index][col_index];
                }
            }
            cum_matrix[cum_row_index][cum_col_index] = sum;
        }
    }

    for(int cum_row_index = 0; cum_row_index < rows; cum_row_index++) {
        for(int cum_col_index = 0; cum_col_index < cols; cum_col_index++) {
            cout << cum_matrix[cum_row_index][cum_col_index] << " ";
        }
        cout << endl;
    } */

    // CUMULATIVE SUM WITH TIME COMPLEXITY O(ROW x COLUMN)

    cum_matrix[0][0] = matrix[0][0];

    for(int cum_col_index = 1; cum_col_index < cols; cum_col_index++) {
        cum_matrix[0][cum_col_index] = cum_matrix[0][cum_col_index - 1] + matrix[0][cum_col_index];
    }

    for(int cum_row_index = 1; cum_row_index < rows; cum_row_index++) {
        cum_matrix[cum_row_index][0] = cum_matrix[cum_row_index - 1][0] + matrix[cum_row_index][0];
    }

    for(int cum_row_index = 1; cum_row_index < rows; cum_row_index++) {
        for(int cum_col_index = 1; cum_col_index < cols; cum_col_index++) {
            cum_matrix[cum_row_index][cum_col_index] = cum_matrix[cum_row_index][cum_col_index - 1] + cum_matrix[cum_row_index - 1][cum_col_index] - cum_matrix[cum_row_index - 1][cum_col_index - 1] + matrix[cum_row_index][cum_col_index];
        }
    }
    
    for(int cum_row_index = 0; cum_row_index < rows; cum_row_index++) {
        for(int cum_col_index = 0; cum_col_index < cols; cum_col_index++) {
            cout << cum_matrix[cum_row_index][cum_col_index] << " ";
        }
        cout << endl;
    }

    // FINDING CUMULATIVE SUM AT ANY POINT OR RANGE IN THE MATRIX USING THE CUMULATIVE MATRIX

    int start_row, start_col, end_row, end_col;
    cin >> start_row >> start_col >> end_row >> end_col;

    if(start_row == 0 && start_col == 0) {
        cout << cum_matrix[end_row][end_col] << endl;
    }
    else if(start_row == 0) {
        cout << cum_matrix[end_row][end_col] - cum_matrix[end_row][start_col - 1] << endl;
    }
    else if(start_col == 0) {
        cout << cum_matrix[end_row][end_col] - cum_matrix[start_row - 1][end_col] << endl;
    }
    else {
        cout << cum_matrix[end_row][end_col] - cum_matrix[end_row][start_col - 1] - cum_matrix[start_row - 1][end_col] + cum_matrix[start_row - 1][start_col - 1] << endl;
    }

    return 0;
}