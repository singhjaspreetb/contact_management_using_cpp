#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
class contact
{
private:
    char num[11];
    char name[30];
    char email[30];
    char address[30];
    int con_num;
    char ext;
    char choice;
private:
    void display();
    void add_contact();
    void con_num_gen();
    void display_ser();
    int display_mod();
    int search();
    void display_con();
    void modify();
    void update_mod();
    void delete_con();
    void del();
    int find();
    void restore_con();
    void restore();
    void del_backup();
    void invalid();
    void exit();
public:
    contact();
};
contact ::contact()
{
    while (ext != 'q')
    {
        display();
        switch (choice)
        {
        case '1':
            add_contact();
            break;
        case '2':
            display_ser();
            break;
        case '3':
            display_con();
            break;
        case '4':
            modify();
            break;
        case '5':
            delete_con();
            break;
        case '6':
            restore_con();
            break;
        case '0':
            exit();
            break;
        default:
            invalid();
            break;
        }
    }
}
void contact ::display()
{
    system("cls");
    system("COLOR 8f");
    cout << "\n\n\n\t\t\t\t\t\t\t\t*** Contact Management System ***";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t  Contact Menu";
    cout << "\n\t\t\t\t\t\t\t\t    =========================";
    cout << "\n\t\t\t\t\t\t\t\t\t1: Add New Contact";
    cout << "\n\t\t\t\t\t\t\t\t\t2: Search Contact";
    cout << "\n\t\t\t\t\t\t\t\t\t3: List All Contact";
    cout << "\n\t\t\t\t\t\t\t\t\t4: Modify Contact";
    cout << "\n\t\t\t\t\t\t\t\t\t5: Delete Contact";
    cout << "\n\t\t\t\t\t\t\t\t\t6: Restore Contact";
    cout << "\n\t\t\t\t\t\t\t\t\t0: Exit";
    cout << "\n\t\t\t\t\t\t\t\t    =========================";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
    cin >> choice;
    Sleep(1000);
}
void contact ::con_num_gen()
{
    string temp, temp2, temp3 = "1";
    int flag;
    ifstream read("users.txt");
    if (read.peek() <= 0)
    {
        con_num = 1;
    }
    else
    {
        while (!read.eof())
        {
            read >> temp;
            if (temp == "{")
            {
                read >> temp2;
                temp2 = temp2 >= temp3 ? temp2 : temp3;
                temp3 = temp2;
            }
        }
    }
    read.close();
    ifstream in("deleted.txt");
    temp3=temp2;
    while (!in.eof())
    {
        in >> temp;
        if (temp == "{")
        {
            in >> temp2;
            temp2 = temp2 >= temp3 ? temp2 : temp3;
            temp3 = temp2;
        }   
    }
    con_num = stoi(temp2);
    ++con_num;
    in.close();
}
void contact ::add_contact()
{
    system("cls");
    system("COLOR 70");
    con_num_gen();
    cout << "\n\t\t\t\t\t\t\t\t\tContat No:     " << con_num;
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Name:    ";
    fflush(stdin);
    gets(name);
    cout << "\n\t\t\t\t\t\t\t\t\tEnter Number:  ";
    fflush(stdin);
    gets(num);
    cout << "\n\t\t\t\t\t\t\t\t\tEnter Email:   ";
    fflush(stdin);
    gets(email);
    cout << "\n\t\t\t\t\t\t\t\t\tEnter Address: ";
    fflush(stdin);
    gets(address);
    ofstream out("users.txt", ios::app);
    out << '{' << endl
        << con_num << endl
        << name << endl
        << num << endl
        << email << endl
        << address << endl
        << '}' << endl;
    out.close();
    cout << "\n\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
    getch();
}
int contact ::search()
{
    int x;
    string temp, temp1, temp2;
    int flag = 0;
    ifstream read("users.txt");
    while (!read.eof())
    {
        read >> temp;
        if (temp == "{")
        {
            read >> temp1;
            read.ignore();

            getline(read, temp2);
            if (temp2 == name)
            {
                flag = 1;
                break;
            }
        }
    }
    read.close();
    x = stoi(temp1);
    if (flag == 1)
    {
        return x;
    }
    else
    {
        return 0;
    }
}
void contact ::display_ser()
{
    system("COLOR A0");
    int flag = 0;
    while (1)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t\t    Enter Name : ";
        fflush(stdin);
        gets(name);
        system("cls");
        flag = display_mod();
        if (flag == 0)
        {
            break;
        }
    }
}
void contact ::display_con()
{
    system("cls");
    system("COLOR 20");
    string temp, temp2;
    ifstream read("users.txt");
    cout << "\n\t\t\t\t\t\t\t\t    =========================";
    cout << "\n\t\t\t\t\t\t\t\t\t List All Contact";
    cout << "\n\t\t\t\t\t\t\t\t    =========================";
    while (!read.eof())
    {
        read >> temp;
        if (temp == "{")
        {
            cout << "\n\n\t\t\t\t\t\t\t    ==========================================";
            read >> temp2;
            cout << "\n\n\t\t\t\t\t\t\t    Contat No: " << temp2;
            read.ignore();
            getline(read, temp2);
            cout << "\n\t\t\t\t\t\t\t    Name:      " << temp2;
            read >> temp2;
            cout << "\n\t\t\t\t\t\t\t    Number:    " << temp2;
            read >> temp2;
            cout << "\n\t\t\t\t\t\t\t    Email:     " << temp2;
            read.ignore();
            getline(read, temp2);
            cout << "\n\t\t\t\t\t\t\t    Address:   " << temp2;
        }
    }
    cout << "\n\n\t\t\t\t\t\t\t    ==========================================";
    cout << "\n\t\t\t\t\t\t\t\t    Press Any Key to Continue...";
    getch();
    read.close();
}
int contact ::display_mod()
{
    string temp, temp2;
    ifstream read("users.txt");
    int num = search();
    if (num == 0)
    {
        invalid();
        return 1;
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t    =========================";
        cout << "\n\t\t\t\t\t\t\t\t\t   Your Contact";
        cout << "\n\t\t\t\t\t\t\t\t    =========================";
        string temp1 = to_string(num);
        cout << endl
             << temp1;
        while (!read.eof())
        {
            read >> temp;
            if (temp == "{")
            {
                read >> temp;
                if (temp == temp1)
                {
                    cout << "\n\n\t\t\t\t\t\t\t    ==========================================";
                    cout << "\n\n\t\t\t\t\t\t\t    Contat No: " << temp1;
                    read.ignore();
                    getline(read, temp2);
                    cout << "\n\t\t\t\t\t\t\t    Name:      " << temp2;
                    read >> temp2;
                    cout << "\n\t\t\t\t\t\t\t    Number:    " << temp2;
                    read >> temp2;
                    cout << "\n\t\t\t\t\t\t\t    Email:     " << temp2;
                    read.ignore();
                    getline(read, temp2);
                    cout << "\n\t\t\t\t\t\t\t    Address:   " << temp2;
                    cout << "\n\n\t\t\t\t\t\t\t    ==========================================";
                    break;
                }
            }
        }
    }
    cout << "\n\t\t\t\t\t\t\t\t    Press Any Key to Continue...";
    getch();
    read.close();
    return 0;
}
void contact ::update_mod()
{
    char update[30];
    fflush(stdin);
    gets(update);
    string temp;
    ifstream read("users.txt");
    ofstream write("temp.txt");
    int x = search();
    string temp2 = to_string(x);
    while (!read.eof())
    {
        getline(read, temp);
        write << temp << endl;
        if (temp == "{")
        {
            getline(read, temp);
            write << temp << endl;
            if (temp == temp2)
            {
                for (char i = '1'; i < choice; i++)
                {
                    getline(read, temp);
                    write << temp << endl;
                }
                getline(read, temp);
                write << update << endl;
            }
        }
    }
    read.close();
    write.close();
    ifstream in("temp.txt");
    ofstream out("users.txt");
    while (!in.eof())
    {
        getline(in, temp);
        out << temp << endl;
    }
    in.close();
    out.close();
    remove("temp.txt");
}
void contact ::modify()
{
    int flag = 0, flag2 = 0;
    while (1)
    {
        system("cls");
        system("COLOR 40");
        cout << "\n\n\t\t\t\t\t\t\t\t    Enter Name : ";
        fflush(stdin);
        gets(name);
        while (1)
        {
            system("cls");
            flag2 = display_mod();
            if (flag2 == 0)
            {
                cout << "\n\n\t\t\t\t\t\t\t    ==========================================";
                cout << "\n\n\t\t\t\t\t\t\t    What Do You Want Change...";
                cout << "\n\n\t\t\t\t\t\t\t    1: Name";
                cout << "\n\t\t\t\t\t\t\t    2: Number";
                cout << "\n\t\t\t\t\t\t\t    3: Email";
                cout << "\n\t\t\t\t\t\t\t    4: Address";
                cout << "\n\t\t\t\t\t\t\t    5: Exit";
                cout << "\n\n\t\t\t\t\t\t\t    Enter Your Choice : ";
                cin >> choice;
                cout << "\n\n\t\t\t\t\t\t\t    ==========================================";
                switch (choice)
                {
                case '1':
                    cout << "\n\n\t\t\t\t\t\t\t\t    Enter New Name : ";
                    update_mod();
                    break;
                case '2':
                    cout << "\n\n\t\t\t\t\t\t\t\t    Enter New Number : ";
                    update_mod();
                    break;
                case '3':
                    cout << "\n\n\t\t\t\t\t\t\t\t    Enter New Email : ";
                    update_mod();
                    break;
                case '4':
                    cout << "\n\n\t\t\t\t\t\t\t\t    Enter New Address : ";
                    update_mod();
                    break;
                case '5':
                    flag = 1;
                    break;
                default:
                    invalid();
                    break;
                }
            }
            else if (flag2 == 1)
            {
                break;
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 1)
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t    =========================";
            cout << "\n\t\t\t\t\t\t\t\t\t Updated Contact";
            cout << "\n\t\t\t\t\t\t\t\t    =========================";
            flag2 = display_mod();
            break;
        }
    }
}
void contact ::del()
{
    string temp;
    int flag = 0;
    ifstream read("users.txt");
    ofstream write("temp.txt");
    ofstream wow("deleted.txt", ios::app);
    int x = search();
    string temp2 = to_string(x);
    while (!read.eof())
    {
        flag = 0;
        getline(read, temp);
        if (temp == "{")
        {
            getline(read, temp);
            if (temp == temp2)
            {
                wow << "{" << endl;
                wow << temp << endl;
                while (temp != "}")
                {
                    getline(read, temp);
                    wow << temp << endl;
                }
                getline(read, temp);
            }
            else
            {
                write << "{" << endl;
                write << temp << endl;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            write << temp << endl;
        }
    }
    wow.close();
    read.close();
    write.close();
    ifstream in("temp.txt");
    ofstream out("users.txt");
    while (!in.eof())
    {
        getline(in, temp);
        out << temp << endl;
    }
    in.close();
    out.close();
    remove("temp.txt");
}
void contact ::delete_con()
{
    system("COLOR 60");
    int flag = 0;
    while (1)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t\t    Enter Name : ";
        fflush(stdin);
        gets(name);
        system("cls");
        flag = display_mod();
        if (flag == 0)
        {
            cout << "\n\n\n\t\t\t\t\t\t\t\tDo You Want to Delete this Contact (y|n)";
            cout << "\n\n\t\t\t\t\t\t\t\t          Enter Choice : ";
            cin >> choice;
            if (choice == 'y')
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t    Press Any Key to Continue...";
                getch();
                del();
                cout << "\n\n\t\t\t\t\t\t\t\t    =========================";
                cout << "\n\t\t\t\t\t\t\t\t\t  Contact Deleted";
                cout << "\n\t\t\t\t\t\t\t\t    =========================";
                Sleep(1000);
            }
            else if (choice == 'n')
            {
                break;
            }
            if (flag == 0)
            {
                break;
            }
        }
    }
}
int contact ::find()
{
    int x;
    string temp, temp1, temp2;
    int flag = 0;
    ifstream read("deleted.txt");
    while (!read.eof())
    {
        read >> temp;
        if (temp == "{")
        {
            read >> temp1;
            read.ignore();

            getline(read, temp2);
            if (temp2 == name)
            {
                getline(read, temp2);
                if (temp2 == num)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    read.close();
    x = stoi(temp1);
    if (flag == 1)
    {
        return x;
    }
    else
    {
        return 0;
    }
}
void contact ::restore()
{
    int x = find();

    int flag = 0;
    string temp;
    string temp2 = to_string(x);
    ofstream wow("users.txt", ios::app);
    ifstream read("deleted.txt");
    while (!read.eof())
    {
        getline(read, temp);
        if (temp == "{")
        {
            getline(read, temp);
            if (temp == temp2)
            {
                wow << "{" << endl;
                wow << temp << endl;

                while (temp != "}")
                {
                    getline(read, temp);
                    wow << temp << endl;
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    read.close();
    wow.close();
}
void contact ::del_backup()
{
    string temp;
    int flag = 0;
    ifstream read("deleted.txt");
    ofstream write("temp.txt");
    int x = find();
    string temp2 = to_string(x);
    while (!read.eof())
    {
        flag = 0;
        getline(read, temp);
        if (temp == "{")
        {
            getline(read, temp);
            if (temp == temp2)
            {
                while (temp != "}")
                {
                    getline(read, temp);
                }
                getline(read, temp);
            }
            else
            {
                write << "{" << endl;
                write << temp << endl;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            write << temp << endl;
        }
    }
    read.close();
    write.close();
    ifstream in("temp.txt");
    ofstream out("deleted.txt");
    while (!in.eof())
    {
        getline(in, temp);
        out << temp << endl;
    }
    in.close();
    out.close();
    remove("temp.txt");
}
void contact ::restore_con()
{
    system("COLOR 8e");
    int flag = 0;
    while (1)
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t\t    Enter Name : ";
        fflush(stdin);
        gets(name);
        cout << "\n\t\t\t\t\t\t\t\t    Enter Number : ";
        fflush(stdin);
        gets(num);
        system("cls");
        flag = find();
        if (flag != 0)
        {
            restore();
            cout << "\n\n\t\t\t\t\t\t\t\t    =========================";
            cout << "\n\t\t\t\t\t\t\t\t\tContact Restored";
            cout << "\n\t\t\t\t\t\t\t\t    =========================";
            display_mod();
            cout << "\n\n\n\t\t\t\t\t\t\t\tDo You Want to Delete From Backup (y|n)";
            cout << "\n\n\t\t\t\t\t\t\t\t          Enter Choice : ";
            cin >> choice;
            if (choice == 'y')
            {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\t    Press Any Key to Continue...";
                getch();
                del_backup();
                cout << "\n\n\t\t\t\t\t\t\t\t   ===========================";
                cout << "\n\t\t\t\t\t\t\t\t   Contact Deleted From Backup";
                cout << "\n\t\t\t\t\t\t\t\t   ===========================";
                Sleep(1000);
            }
            break;
        }
        else
        {
            invalid();
        }
    }
}
void contact ::invalid()
{
    cout << "\n\t\t\t\t\t\t\t\t\tInvalid Input!";
    cout << "\n\t\t\t\t\t\t\t\t\tTry Again :)";
    Beep(750, 1000);
    Sleep(1000);
}
void contact ::exit()
{
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t  Thanks For Coming";
    cout << "\n\n\t\t\t\t\t\t\t\t\tBye Have A Nice Day :)";
    ext = 'q';
}
int main()
{
    contact c;
    return 0;
}