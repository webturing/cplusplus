#include<iostream>

using namespace std;

int main() {
    char isbn[15];
    cin >> isbn;
    int final = 0;
    int time = 1;
    int i;
    for (i = 0; isbn[i + 1] != '\0'; i++) {
        if (isbn[i] == '-')
            continue;
        else {
            final += (isbn[i] - '0') * time;
            time++;
        }
    }

    char ch = final % 11 < 10 ? (final % 11 + '0') : 'X';
    if (ch == isbn[i])
        cout << "Right" << endl;
    else {
        isbn[i] = ch;
        cout << isbn << endl;
    }
    return 0;
}


//#include<iostream>
//using namespace std;
//int main()
//{
//	char ch[15];
//	cin>>ch;
//	int i=0;
//	int arr[10];
//	
//	//0-670-82162-4
//	arr[0]=ch[0]-'0';
//	arr[1]=ch[2]-'0';
//	arr[2]=ch[3]-'0';
//	arr[3]=ch[4]-'0';
//	arr[4]=ch[6]-'0';
//	arr[5]=ch[7]-'0';
//	arr[6]=ch[8]-'0';
//	arr[7]=ch[9]-'0';
//	arr[8]=ch[10]-'0';
////	arr[9]=ch[12]-'0';
//	
//	int sum=0;
//	for(int i=1;i<10;i++)
//	{
//		sum+=arr[i-1]*i;
//	}
//	
//	char c;
//	if(sum%11==10)
//			c='X';
//	else c=sum%11+'0';
//	if(c==ch[12])
//	{
//		cout<<"Right"<<endl;
//	}
//	else
//	{
//		ch[12]=c;
//		cout<<ch<<endl;
//	}
//	return 0;
//}
