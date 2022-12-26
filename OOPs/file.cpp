#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class file {
  string filename;
  string info;

public:
  string filecreat() {
    cout << "Enter file name :";
    getline(cin, filename);
    return filename;
  }
  void writefile(string);
  void readfile(string);
};

void file::writefile(string fname) {
  ofstream ost(fname, ios::out);
  if (!ost) {
    cout << "File not created!";
  } else {
    cout << "File created succesfully !\n";
    char ch;
    do {
      cout << "Enter info: \n";
      getline(cin, info);
      ost << info << "\n";
      cout << "continue? (y/n) : ";
      cin.get(ch);
      cin.get();
    } while (ch == 'y' || ch == 'Y');
    ost.close();
  }
}

void file::readfile(string fname) {
  ifstream ist(fname, ios::in);
  string line;
  if (!ist) {
    cout << "file not found! ";
  } else {
    cout << "File found : \n";
    cout << "File name : " << fname;
    while (!ist.eof()) {
      getline(ist, line);
      cout << line << "\n";
    }
    ist.close();
  }
}

int main() {

  file f;

  string fname;
  while (true) {
    int ch;
    cout << "menu:\n";
    cout << "1.creat and write to a file \n";
    cout << "2.read from a file \n";
    cout << "3.exit\n";
    cout << "Enter your choice : ";
    cin >> ch;
    cin.get();
    switch (ch) {
    case 1:
      fname = f.filecreat();
      f.writefile(fname);
      break;

    case 2:
      fname = f.filecreat();
      f.readfile(fname);
      break;

    case 3:
      exit(0);

    default:
      cout << "invalid cmd ";
      break;
    }
  }

  return 0;
}