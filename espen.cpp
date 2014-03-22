#include <iomanip>
#include <iostream>
//#include <cstring>
//#include <string>
#include <fstream>

using namespace std;

///////////////////////////////////////////
/// Lot of crap here.. look at the bottom//
///////////////////////////////////////////


void cnum(int number, int count)
{
	if (number/10==0) return;
	
		cnum(number/10, count+1);	
		cout<<number%10<<"="<<count<<" ";	  
}



void charp(char* chrpkr)
{
	chrpkr[0]='d';
	cout <<chrpkr;
}



void char8(int number, char* chrpkr)
{
 int pos=0;
 number+=10000000;
 while (number)
 {
  chrpkr[6-pos++]=number%10+48;
  number/=10;
 }
 chrpkr[pos]='\0';
}

void charx(int number, char* chrpkr,int signs)
{
 int pos=0;
 signs--;
 while (signs>=pos)
 {
  chrpkr[(signs) -pos++]=number%10+48;
  number/=10;
 }
 chrpkr[pos]='\0';
}


// Insert chars from int at the end of char_array;


void lag_navn(char* chrpkr,int number,int signs, int prot)
{
 int pos=0;
 prot++;
 signs-=prot;
 while (signs>=pos)
 {
  if (number)
	  {
		  chrpkr[(signs) -pos]=number%10+48;
		  number/=10;
	   }
  pos++;
 }
 chrpkr[signs+prot]='\0';
}

void olag_navn(char* chrpkr,int number, int prot)
{
 int signs,pos=0;
 signs=strlen(chrpkr);
 prot++;
 signs-=prot;
 while (signs>=pos)
 {
  if (number) chrpkr[(signs)-pos]=number%10+48;
  number/=10;    
  pos++;
 }
 chrpkr[signs+prot]='\0';
}
//

inline void lag_navn(char* chrpkr,int number, int prot)
{
 for (int signs=strlen(chrpkr);number&&signs--;number/=10)chrpkr[signs-prot]=number%10+48;
}

void main()
{char ch,filename[30]="DATA0000.DTA";
	lag_navn(filename,133,4); // Adjust filename & protect last 4 chars from change.

	ofstream fout(filename);
	fout <<"Hi there how are you doing!";
	fcloseall();
	cout <<"Her er file:"<<filename<<" :)";

	ifstream fin(filename);
	char tmpstr[80];
	fin.getline(tmpstr,99);
	fcloseall();
	cout << endl<<tmpstr;

	cin >> ch;	
}


	


