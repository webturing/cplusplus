#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int win[n][5];
    int x, y; //operate
    for (int i = 0; i < n; i++) {
        cin >> win[i][0] >> win[i][1] >> win[i][2] >> win[i][3];
        win[i][4] = i + 1;
    }
    for (int j = 0; j < m; j++) {
        cin >> x >> y;
        for (int i = n - 1; i >= 0; i--) {
//			cout<<x<<" "<<win[i][0]<<" "<<win[i][2]<<endl;
//			cout<<y<<" "<<win[i][1]<<" "<<win[i][3]<<endl;
            if (x >= win[i][0] && x <= win[i][2] && y >= win[i][1] && y <= win[i][3]) {
                cout << win[i][4] << endl;
                int temp[5];
                for (int k = 0; k < 5; k++)
                    temp[k] = win[i][k];

                for (int r = i; r < n - 1; r++) {
                    win[r][0] = win[r + 1][0];
                    win[r][1] = win[r + 1][1];
                    win[r][2] = win[r + 1][2];
                    win[r][3] = win[r + 1][3];
                    win[r][4] = win[r + 1][4];
                }
                win[n - 1][0] = temp[0];
                win[n - 1][1] = temp[1];
                win[n - 1][2] = temp[2];
                win[n - 1][3] = temp[3];
                win[n - 1][4] = temp[4];

//				for(int t=0;t<n;t++)
//				{
//					cout<<win[t][0]<<" "<<win[t][1]<<" "<<win[t][2]<<" "<<win[t][3]<<" "<<win[t][4]<<endl;		
//				}
                break;
            }
            if (i == 0)
                cout << "IGNORED" << endl;
        }
    }


    return 0;
}
