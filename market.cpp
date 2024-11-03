#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;

struct Products
{
  string name;
  float price;
};

void capital(string& cap)
{
  for (int i = 0; i < cap.size(); i++)
  {
    if (!i) cap.at(i) = toupper(cap.at(i));
    else if (cap.at(i) == ' ') cap.at(i + 1) = toupper(cap.at(i + 1));
  }
}

bool check_product(const vector<Products>& check_vec, const string& check)
{
  for (Products word : check_vec) return word.name == check;
  return false;
}

void add_product(vector<Products>& add)
{
  Products get;
  cout << "Name: ";
  getline(cin, get.name);
  capital(get.name);
  bool exist = check_product(add, get.name);
  if (exist)
  {
    cout << "\nExist Product - Failed Added\n";
    return;
  }
  cout << "Price: ";
  cin >> get.price;
  add.push_back(get);
  cout << "\nDone Added\n";
}

void show_products(const vector<Products>& show)
{
  if (!show.size())
  {
    cout << "\nMenu is empty!\n";
    return;
  }
  cout << "\n----------------------------- Products Menu -----------------------------\n";
  int num = 1;
  for (const Products& word : show)
  {
    cout << '[' << num << "] " << word.name << ": " << word.price << " EGP\n";
    num++;
  }
  cout << "------------------------------------------------------------------------\n";
}

void update_product(vector<Products>& update)
{
  if (!update.size())
  {
    cout << "\nMenu is empty!\n";
    return;
  }
  int position;
  cout << "Enter position: ";
  cin >> position;
  cin.ignore();
  string select;
  cout << "(name, price)\nEnter type: ";
  getline(cin, select);
  Products& get = update.at(position - 1);
  if (select == "name")
  {
    cout << "Name: ";
    getline(cin, get.name);
    capital(get.name);
  }
  else if (select == "price")
  {
    cout << "Price: ";
    cin >> get.price;
  }
  cout << "\nDone Updated.\n";
}

void delete_product(vector<Products>& del)
{
  if (!del.size())
  {
    cout << "\nList is empty!\n";
    return;
  }
  int position;
  cout << "Enter Position: ";
  cin >> position;
  cin.ignore();
  del.erase(del.begin() + (position - 1));
  cout << "\nDone Removed.\n";
}

int main()
{
  string logo = "=======================                           =======================\n";
  string* ptr = &logo;
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "====================                                 ====================\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "=================                                       =================\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "==============                                             ==============\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  cout.flush();
  *ptr = "===========                  M  A  R  K  E  T                 ===========\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "==============                                             ==============\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "==================                                     ==================\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "====================                                 ====================\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  *ptr = "=======================                           =======================\n";
  for (char ch : *ptr)
  {
    cout << ch;
    Sleep(1);
  }
  cout.flush();
  vector<Products> product;
  ifstream read("data.txt");
  string result;
  while (getline(read, result))
  {
    Products get;
    get.name = result.substr(0, result.find(','));
    result.erase(0, result.find(',') + 1);
    get.price = stof(result);
    product.push_back(get);
  }
  while (true)
  {
    cout << "\n[1] View Menu";
    cout << "\n[2] Add Product";
    cout << "\n[3] Update Product";
    cout << "\n[4] Delete Product\n";
    int option;
    cin >> option;
    cin.ignore();
  reload:
    switch (option)
    {
    case 1: show_products(product); cout.flush(); break;
    case 2: add_product(product); cout.flush(); break;
    case 3: update_product(product); cout.flush(); break;
    case 4: delete_product(product); cout.flush(); break;
    default: cout << "Enter a valid option: "; cin >> option; goto reload;
    }
    ofstream file("data.txt");
    for (const Products& word : product)
    {
      file << word.name << ',' << word.price << '\n';
    }
  }
  return 0;
}