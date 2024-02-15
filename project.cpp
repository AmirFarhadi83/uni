
#include <iostream> 
#include <conio.h> 
#include <string> 
using namespace std;


struct student {
  char name[31];
  int id;
  int sal_vorod;
  char major[31];
  char maghta[85];
  char daneshkadeh[95];
  int vahed;
  float average;
};

struct student s[10];

int num;
char a[31], b[31];



char* gets(char* s)
{
  int i = 0;

  for (;;)
  {
    int a;
    a = _getche();
    if (a != 13)
    {
      s[i] = char(a);
      i++;
    }
    else
    {
      s[i] = NULL;
      i = 0;
      while (s[i])
        i++;

      putchar(12);
      return s;
    }
  }

}


char* lower(char* s1)
{
  for (int i = 0; s1[i]; i++)
  {
    if (s1[i] >= 'A' && s1[i] <= 'Z')
      s1[i] = s1[i] + ('a' - 'A');
  }
  return s1;
}




int main()
{
  s[0] = { "mohammad",2,1397,"psychology","karshenasi_arshad","computer",18,12.5f };
  s[1] = { "ali",1,1397,"psychology","karshenasi","sience",17,18 };
  s[2] = { "reza",3,1401,"computer engineering","karshenasi_arshad","computer",16,15.5f };
  s[3] = { "amir",4,1401,"medical engineering","karshenasi","sience",8,9.75f };
  s[4] = { "sara",5,1400,"medical engineering","karshenasi_arshad","computer",16,15.5f };
  s[5] = { "hossin",6,1401,"computer engineering","karshenasi","sience",13,20 };
  s[6] = { "amir",7,1399,"medical engineering","karshenasi_arshad","omran",14,20 };
  s[7] = { "akbar",8,1399,"psychology","karshenasi","omran",12,15 };
  s[8] = { "erfan",9,1397,"computer engineering","karshenasi_arshad","computer",11,14.5f };
  s[9] = { "arash",10,1398,"computer engineering","karshenasi_arshad","omran",10,17 };

  cout << "How do you want to search?\n"
     << " 1 = Through the name\n"
     << " 2 = Through the field of study\n"
     << " 3 = Through sal_vorod\n"
     << " 4 = Through ID\n"
     << " 5 = Through maghtae tahsili\n"
     << " 6 = Through daneshkadeh\n"
     << " 7 = Through vahed\n"
     << " 8 = Through average\n" << endl;
  cin >> num;


  //name 
  if (num == 1)
  {
    cout << "enter a name: " << endl;

    gets(a);
    lower(a);
    int  j = 0;
    for (; s[j].name; j++)
    {
      for (; strcmp(a, s[j].name) != 0; j++);
      cout << "\nName :" << s[j].name
         << "\nID :" << s[j].id
         << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }

  //field of study 
  if (num == 2)
  {
    cout << "enter a major: " << endl;

    gets(b);
    lower(b);

    int  j = 0;
    for (; s[j].major; j++)
    {
      for (; strcmp(b, s[j].major) != 0; j++);
      cout << "\nName :" << s[j].name
          << "\nID :" << s[j].id
          << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }

  //sal_vorod 
  if (num == 3)
  {
    int sal_vorod;
    cout << "enter sal_vorod: " << endl;
    cin >> sal_vorod;
    int  j = 0;
    for (; s[j].sal_vorod; j++)
    {
      for (; sal_vorod - s[j].sal_vorod; j++);
      cout << "\nName :" << s[j].name
         << "\nID :" << s[j].id
         << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }

  //ID 
  if (num == 4)
  {
    int id, j = 0;
    cout << "enter ID: " << endl;
    cin >> id;
    for (; id - s[j].id; j++);
    cout << "\nName :" << s[j].name
       << "\nID :" << s[j].id
       << "\nsal_vorod :" << s[j].sal_vorod
       << "\nMajor :" << s[j].major
       << "\nmaghta:" << s[j].maghta
       << "\naverage:" << s[j].average
       << "\nvahed:" << s[j].vahed
       << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
  }

  //maghtae tahsili 
  if (num == 5)
  {
    cout << "enter a maghta: " << endl;

gets(b);
    lower(b);

    int  j = 0;
    for (; s[j].maghta; j++)
    {
      for (; strcmp(b, s[j].maghta) != 0; j++);
      cout << "\nName :" << s[j].name
         << "\nID :" << s[j].id
         << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }

  //daneshkadeh 
  if (num == 6)
  {
    cout << "enter a daneshkadeh: " << endl;

    gets(b);
    lower(b);

    int  j = 0;
    for (; s[j].daneshkadeh; j++)
    {
      for (; strcmp(b, s[j].daneshkadeh) != 0; j++);
      cout << "\nName :" << s[j].name
         << "\nID :" << s[j].id
         << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }

  //vahed 
  if (num == 7)
  {
    int vahed, j = 0;
    cout << "enter vahed: " << endl;
    cin >> vahed;
    for (; s[j].vahed; j++)
    {
      for (; vahed - s[j].vahed; j++);
      cout << "\nName :" << s[j].name
         << "\nID :" << s[j].id
         << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }

  //average 
  if (num == 8)
  {
    int average;
    cout << "enter average: " << endl;
    cin >> average;
    int  j = 0;
    for (; s[j].average; j++)
    {
      for (; average - s[j].average; j++);
      cout << "Name :" << s[j].name
         << "\nID :" << s[j].id
         << "\nsal_vorod :" << s[j].sal_vorod
         << "\nMajor :" << s[j].major
         << "\nmaghta:" << s[j].maghta
         << "\naverage:" << s[j].average
         << "\nvahed:" << s[j].vahed
         << "\ndaneshkadeh:" << s[j].daneshkadeh << endl;
    }
  }
}
