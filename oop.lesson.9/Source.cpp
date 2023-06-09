#include<iostream>

using namespace std;

class Student   {

    char* name;
    int age;

public:

    Student() // construct by default

    {

        cout << "Constructor by default\n";

        name = nullptr;

        age = 0;

    }

    Student(const char* Name, int Age) // construct by 2 param

    {

        cout << "Constructor with parameters\n";

        name = new char[strlen(Name) + 1];

        strcpy_s(name, strlen(Name) + 1, Name);

        age = Age;

    }

    Student(const Student& object) = delete;

    Student& operator=(const Student& object) {
        
        age = object.age;

        delete[] name;
        name = nullptr;

        if (object.name != nullptr) {

            name = new char[strlen(object.name) + 1];
            strcpy_s(name, strlen(object.name) + 1, object.name);
        }

        return *this;
    }


    void Output()    {

        if (name == nullptr)    {

            cout << "Empty object!\n";
            return;
        }

        cout << "Name: " << name << endl << "Age: " << age << endl;
    }

    ~Student()

    {

        cout << "Destruct\n";

        delete[] name;

    }

    void SetAge(int age) {

        if(age > 14 && age < 90)
        this->age = age;
    }

    void SetName(char* name) {

        delete[]this->name;
        this->name = nullptr;

        if (name != nullptr) {

            this->name = new char[strlen(name) + 1];
            strcpy_s(this->name, strlen(name) + 1, name);
        }
    }

};

void SafeInput(int& value, int min, int max) {

    while (!(cin >> value) || value < min || value > max) {
        cout << "error, wrong value.. try again: ";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

void AddStudent(Student*& list, int& size)
{
    int age = 0;
    char name[20];

    Student* temp = new Student[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = list[i];

    cout << "enter age: ";
    SafeInput(age, 14, 90);
    temp[size].SetAge(age);

    cout << "enter name: ";
    cin.ignore();
    cin.getline(name, 20);
    temp[size].SetName(name);

    delete[] list;
    list = temp;
    size++;
}

int main()
{
    int size = 0;
    cout << "enter size: ";
    SafeInput(size, 1, 10);
    cout << endl;

    Student* list = new Student[size];
    int age = 0;
    char name[20];

    for (int i = 0; i < size; i++) {

        cout << "enter age: ";
        SafeInput(age, 14, 90);
        list[i].SetAge(age);

        cout << "enter name: ";
        cin.ignore();
        cin.getline(name, 20);
        list[i].SetName(name);
    }
    cout << endl;

    for (int i = 0; i < size; i++)
        list[i].Output();
    cout << endl;

    AddStudent(list, size);
    cout << endl;

    for (int i = 0; i < size; i++)
        list[i].Output();
    cout << endl;

    delete[]list;
}

//Task1
//Практика 1: Добавить в класс сэттеры(для каждого поля) и заполнить массив объектов с использованием сэттеров.Сэттеры должны принимать значения с клавиатуры.Вывести заполненный массив на экран

//Практика 2 : Добавить глобальную функцию, которая принимает массив объектов и добавляет к нему одного студента