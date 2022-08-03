#include <iostream>
#include<windows.h>
#include <mysql.h>
#include <sstream>
#include<stdlib.h>
#include<iomanip>
#include <cstdlib>
#include<string>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector> //vector to make list for transaction and service
#include <bits/stdc++.h>

using namespace std;
void Login_staff();
void stock_transaction();
void Stock();
void Transaction();
void add_stock();
void delete_stock();
void add_amount_stock();
void decrease_amount_stock();
void add_employee();
void employee();
void delete_employee();
void view_stock(); //to search stock
void view_employee();
void vdelete_stock();
void vtable_stock(string);
void service_j();
void month_ly();

int main()
{
Login_staff();
}
//==================================================================================================================================================
void Login_staff()//code in the function of Login_staff
{
int qstate = 0;
MYSQL_RES *result;
MYSQL_ROW row;
MYSQL* conn;
conn = mysql_init(0);
string staff_username;
string staff_password;
stringstream ss_username;
stringstream ss_password;
conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
bool done_1 = false;
while(!done_1)
    {
system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                                                     __               __                                     "<<endl;
cout<<"                                                                    |  |.-----.-----.|__|.-----.    .-----.---.-.-----.-----."<<endl;
cout<<"                                                                    |  ||  _  |  _  ||  ||     |    |  _  |  _  |  _  |  -__|"<<endl;
cout<<"                                                                    |__||_____|___  ||__||__|__|    |   __|___._|___  |_____|"<<endl;
cout<<"                                                                              |_____|               |__|        |_____|      "<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                                                                      username:";
cin>>staff_username;
       conn = mysql_init(0);
       conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);
       ss_username<<"SELECT * FROM staff WHERE username = '"<<staff_username<<"'";
       string query = ss_username.str();
       const char* q = query.c_str();
       mysql_query(conn,q);
       result = mysql_store_result(conn);
       int num_fields;
       num_fields = mysql_num_fields(result);
       string srole = "Staff";
       string srole1 = "Admin";
       if((row = mysql_fetch_row(result)))
        {
    if(staff_username == row[1] && srole == row[7] ) //if username input is equal to the 2nd row in the databaase and if the row 8 equal to staff then go to stock_transaction
    {
    cout<<"                                                                                      password:";
    cin>>staff_password;
    ss_password<< ss_username<<"SELECT * FROM staff WHERE staffpassword = '"<<staff_password<<"'";
    string query = ss_password.str();
    if(staff_password == row[2])
    {
        system("CLS");
        stock_transaction();
    }
    else
        {
        cout<<"Wrong password \n";
        system("pause");
        Login_staff();
        }
    }
        else if(staff_username == row[1] && srole1 == row[7] ) //if username input is equal to the 2nd row in the databaase and if the row 8 equal to admin then go to employee
         {
             cout<<"                                                                                      password:";
    cin>>staff_password;
    ss_password<< ss_username<<"SELECT * FROM staff WHERE staffpassword = '"<<staff_password<<"'";
    string query = ss_password.str();
    if(staff_password == row[2])
    {
        system("CLS");
        employee();
    }
    else
        {
        cout<<"Wrong password \n";
        system("pause");
        Login_staff();
        }
         }
    else
        {
    cout<<"Wrong username \n";
    system("pause");
    Login_staff();
    }
    }
    }
}
//===================================================================================================================================================
void stock_transaction()
{
    char stock_tmein;
    bool stock_tloop = false;
    string stock_tinput;
    do{
    system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                                       __          ___   ___                                 "<<endl;
cout<<"                                               .-----.|  |_.---.-.'  _|.'  _|    .--------.-----.-----.--.--."<<endl;
cout<<"                                               |__ --||   _|  _  |   _||   _|    |        |  -__|     |  |  |"<<endl;
cout<<"                                               |_____||____|___._|__|  |__|      |__|__|__|_____|__|__|_____|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
    cout<<"                                                                a. Stock"<<endl;
    cout<<"                                                                b. Service"<<endl;
    cout<<"                                                                c. Transaction"<<endl;
    cout<<"                                                                d. Report"<<endl;
    cout<<"                                                                e. Exit"<<endl;
    cout<<"                                                                Choose input for this menu: ";
    cin>>stock_tmein;
    switch(stock_tmein)
    {
    case 'a':
    Stock(); //go to stock
    break;
    case 'b':
    service_j(); //go to service
    break;
    case 'c':
        Transaction();// go to transaction
        break;
        case 'd':
        month_ly(); //go to report
    case 'e':
        cout<<"                                                                Exit menu?:";
        cin>>stock_tinput;
        if(stock_tinput=="y" || stock_tinput == "Y"){
            main();
        }
            else if(stock_tinput == "n" || stock_tinput == "N"){
                    stock_transaction();
                    }
                        else{
                            cout<<"                                                                Wrong input. Please try again"<<endl;
                            system("pause");
                        }
                        break;
    default:
        cout<<"                                                                Wrong input. Please try again"<<endl;
        system("pause");

    }
    }
    while(!stock_tloop);
}
//=======================================================================================================================================
void Transaction()
{
    vector <string> z1; //create a container for transaction list
    vector <int> z2;    //create a container and total the price
    for(int i = 0 ; i<100 ; i++) //loop for transaction
        {
    int qstate = 0;
    string transaction_input;
    string em_name;
    string trans_item;
    string service1;
    string t_employee;
    float ch_price;
    float trans_price;
    float cash;
    float final_total;
    int trans_quantity;
    float trans_total;
    char repeat;
    vector<float> p_rice;
    vector<string> i_tem;
    stringstream ss_tname;
    stringstream iid_name;
    stringstream table_string;
    stringstream ss_tstooc1;
    stringstream d_stock;
    int n, pro = 1;
    float arr[100],sum=0;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                   _______                                     __   __              "<<endl;
cout<<"                                  |_     _|.----.---.-.-----.-----.---.-.----.|  |_|__|.-----.-----."<<endl;
cout<<"                                    |   |  |   _|  _  |     |__ --|  _  |  __||   _|  ||  _  |     |"<<endl;
cout<<"                                    |___|  |__| |___._|__|__|_____|___._|____||____|__||_____|__|__|"<<endl;

cout<<""<<endl;
cout<<""<<endl;
cout<<"                                     Item list:"<<endl;
cout<<"                                  ================================================================================"<<endl;
for(int i = 0; i<z1.size();i++) //loop for container
    {
        cout<<"                                     "<<z1[i]<<endl;//print the transaction container here
    }
cout<<"                                  ================================================================================"<<endl;
cout<<"                                      Sum=RM"<<accumulate(z2.begin(), z2.end(), 0)<<endl;//total price will be print here
cout<<"                                  ================================================================================"<<endl;
cout<<""<<endl;

            cout<<"                                                                 spare part's description(type q to quit):";
            cin.get();
            getline(cin, trans_item);
            if(trans_item == "q") //if user input is q then goes back to the staff menu
                {
                    stock_transaction();
                }
            else
                {
            ss_tstooc1 <<"SELECT * FROM stock WHERE description = '"<<trans_item<<"'"; //mysql command to search if the item is available or not
              string query = ss_tstooc1.str();
              const char* q = query.c_str();
              if(conn){
              qstate = mysql_query(conn,q);
              if(!qstate) //if available then proceeed
                {
                    cout<<"                                                                 Name:";
                    cin>>t_employee;
                    string item = trans_item;
                    z1.push_back(item);
                    res = mysql_store_result(conn);
                    while ((row = mysql_fetch_row(res))){
                        cout <<"                                                                 Price:RM"<<     row[2]<<endl;
                        float fp = atof(row[2]);
                        cout<<"                                                                 How many: ";
                        cin>>trans_quantity;
                        int tq = atof(row[3]);
                        if(trans_quantity <= tq )
                            {
                        float total = fp*trans_quantity;
                        float ttotal = total;
                        z2.push_back(ttotal);
                        d_stock<<"UPDATE stock SET Amount = Amount - "<<trans_quantity<<" WHERE description = '"<<trans_item<<"'";
                        string query = d_stock.str();
                        const char* q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if(qstate == 0)
                            {
                        table_string << "INSERT INTO Transaction(spare_part,Quantity,Price,Staff) VALUES ('"<<trans_item<<"',"<<trans_quantity<<","<<fp<<",'"<<t_employee<<"')";
    string query = table_string.str();
           const char* q = query.c_str();
           qstate = mysql_query(conn, q);
    if(qstate == 0)
           {
               float tttotal=accumulate(z2.begin(), z2.end(), 0); //declare the total from price container to easily be print out
               cout<<"                                                                             Total:RM "<< tttotal<<endl; //print out the variable
               cout<<"                                                                        Do another transaction?:";
               cin>>repeat;
               if(repeat == 'N'||repeat == 'n')
                {
               cout<<"                                                                             Cash:RM";
                    cin>>cash;
                    final_total=cash-tttotal; //subtract cash input with total in the tttotal container
               cout<<"                                                                              Total:RM"<<final_total<<endl;
               system("pause");
               Transaction();
                }



           }
           else
            {
                cout<<"                                                                                  Record failed..."<<endl;
                system("pause");
                Transaction();
           }
                            }
                            else
                                {
                                    cout<<""<<endl;
                                    cout<<"                                                                                 Record failed..."<<endl;
                                    system("pause");

                                }

                    }
                    else
                    {
                        cout<<"                                                                Not enough stock"<<endl;
                        system("pause");
                        Transaction();
                    }
                    }

              }
              else
              {
                cout<<"                                                                                  Record failed..."<<endl;
                system("pause");
                //Transaction();
           }
        }
        else
            {
              cout<<"                                                                       Query executional problem:"<<mysql_error(conn)<<endl; //print error
              system("pause");
            }
    }

}
}
//====================================================================================================================================================================
void service_j()
{
    string ser_input;
    vector <string> g1; //create a container to print service list
    vector <int> g2;

for(int i = 0 ; i<100 ; i++)
        {
            string em_name;
            string service_s;
            float charge;
            float c_cash;
            stringstream in_serv;
            MYSQL* conn;
            MYSQL_RES *res;
            MYSQL_ROW row;
            conn = mysql_init(0);
            conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
            int qstate = 0;
            system("CLS");
    cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                                                   _______                    __             "<<endl;
cout<<"                                                                  |     __|.-----.----.--.--.|__|.----.-----."<<endl;
cout<<"                                                                  |__     ||  -__|   _|  |  ||  ||  __|  -__|"<<endl;
cout<<"                                                                  |_______||_____|__|  \\___/ |__||____|_____|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                                                       Service total:"<<endl;
cout<<"                                                                  ================================================================================"<<endl;
for(int i = 0; i<g1.size(); i++) //loop to print service list
    {
        cout<<"                                                                       "<<g1[i]<<endl; //print service list here
    }
cout<<"                                                                  ================================================================================"<<endl;
cout << "                                                                       Sum = RM"
         << accumulate(g2.begin(), g2.end(), 0)<<endl; //print total of price list
cout<<"                                                                  ================================================================================"<<endl;

cout<<""<<endl;
cout<<"                                                                       employee's name(type q to quit):";
            cin>>em_name;
            if(em_name == "q") //if user enter q then goes back to staff meny
                {
                    stock_transaction();
            }
            else
                {

            cout<<"                                                                       Service:";
            cin.get();
            getline(cin, service_s);
            cout<<"                                                                       Price:RM";
            cin>>charge;

            in_serv<<"INSERT INTO service(Staff,Service,Price) VALUES ('"<<em_name<<"','"<<service_s<<"',"<<charge<<")"; //insert into database
            string i_query = in_serv.str();
            const char* q = i_query.c_str();
            if(conn)
            {
            qstate = mysql_query(conn,q);
            if(!qstate)
                {
                  string servi = service_s; //make variable for input service
                   g1.push_back(servi); //insert the variable into service container
                   float chargi = charge; //make variable for input charge
                  g2.push_back(chargi); //insert it into charge container to and add it into total

                   int mysql_reset_connection(MYSQL *mysql); //reset the connection so it doesnt clash the query in loop and cause error
                   float total=accumulate(g2.begin(), g2.end(), 0);
                  cout<<"                                                                       Done adding service?(type y for yes):";
                  cin>>ser_input;

                  if(ser_input=="y") //if the user input is y then proceed to the payment
                    {
                      cout<<"                                                                  ================================================================================"<<endl;
                      cout<<"                                                                       Total amount:RM"<<total<<endl;
                      cout<<"                                                                       Cash:RM";
                      cin>>c_cash;
                      float change = c_cash-total;
                      cout<<"                                                                       Change:RM"<<change<<endl;
                      system("pause");
                      service_j();
                    }
                    else
                        {

                    }

        }
           else
        {
             cout<<"                                                                       Query executional problem:"<<mysql_error(conn)<<endl;//print error
            system("pause");
        }
        }


        }
}

}

//==========================================================================================================================================================================

void month_ly()
{
    //vector <tuple<string,int,float>> z1;
    vector <string> z1;
    vector <int> z2;
    int qstate = 0;

    string c_name;
    int c_month;
    int c_year;

    float ch_price;
    float trans_price;
    float cash;
    float final_total;
    int trans_quantity;
    float trans_total;
    char repeat;
    vector<float> p_rice;
    vector<string> i_tem;
    stringstream ss_tname;
    stringstream iid_name;
    stringstream table_string;
    stringstream ss_commission;
    stringstream d_stock;
    int n, pro = 1;
    float arr[100],sum=0;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                     ______                           __               __              "<<endl;
cout<<"                                    |      |.-----.--------.--------.|__|.-----.-----.|__|.-----.-----."<<endl;
cout<<"                                    |   ---||  _  |        |        ||  ||__ --|__ --||  ||  _  |     |"<<endl;
cout<<"                                    |______||_____|__|__|__|__|__|__||__||_____|_____||__||_____|__|__|"<<endl;


cout<<""<<endl;
cout<<""<<endl;
            cout<<"                                                                 Name(type q to quit):";
            cin.get();
            getline(cin, c_name);
            if(c_name == "q")
                {
                    stock_transaction();
                }
            else
                {
            cout<<"                                                                 Month:";
            cin>>c_month;
            cout<<"                                                                 Year:";
            cin>>c_year;
            ss_commission <<"SELECT SUM(Quantity*Price) AS orderTotal FROM transaction WHERE YEAR(Time) = "<<c_year<<" AND MONTH(Time) = "<<c_month<<" AND Staff = '"<<c_name<<"'"; //get total in database
              string query = ss_commission.str();
              const char* q = query.c_str();
              if(conn){
              qstate = mysql_query(conn,q);
              if(!qstate)
                {
                    res = mysql_store_result(conn);
                    while ((row = mysql_fetch_row(res))){
                        cout <<"                                                                 Monthly sales:RM"<<row[0]<<endl;
                        float fp = atof(row[0]);
                        float commission = fp*0.01;
                        cout<<"                                                                 Commission:RM"<<commission<<endl;
                        system("pause");
                        month_ly();
                    }

              }
              else
              {
              cout<<"                                                                       Query executional problem:"<<mysql_error(conn)<<endl;//print error
                system("pause");
                month_ly();
           }
        }
        else
            {
              cout<<"                                                                       Query executional problem:"<<mysql_error(conn)<<endl;//print error
              system("pause");
              month_ly();
            }


}
}


void Stock()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    char stock_input;
    bool stock_loop = false;
    do
        {
    system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                                       __               __                                    "<<endl;
cout<<"                                               .-----.|  |_.-----.----.|  |--.    .--------.-----.-----.--.--."<<endl;
cout<<"                                               |__ --||   _|  _  |  __||    <     |        |  -__|     |  |  |"<<endl;
cout<<"                                               |_____||____|_____|____||__|__|    |__|__|__|_____|__|__|_____|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
    cout<<"                                                               Update stock menu"<<endl;
    cout<<"                                                               1. Add new stock"<<endl;
    cout<<"                                                               2. Search and edit for stock"<<endl;
    cout<<"                                                               3. Exit"<<endl;
    cout<<"                                                               Choose input for this menu:";
    cin>>stock_input;
switch(stock_input){
    case '1':
        add_stock();
        break;
    case '2':
        view_stock();
        break;
    case '3':
        stock_transaction();
        break;
         default:
        cout<<"Wrong input. Please try again"<<endl;
        system("pause");
}
}while(!stock_loop);
}
//===================================================================================
void add_stock()
{

    string stock_name;
    float stock_price;
    int stock_amount;
    int qstate = 0;
    stringstream ss_addstock;
    string as;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql

    system("CLS");
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
cout<<"                                                     _______     __     __             __               __    "<<endl;
cout<<"                                                    |   _   |.--|  |.--|  |    .-----.|  |_.-----.----.|  |--."<<endl;
cout<<"                                                    |       ||  _  ||  _  |    |__ --||   _|  _  |  __||    < "<<endl;
cout<<"                                                    |___|___||_____||_____|    |_____||____|_____|____||__|__|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
    cout<<""<<endl;
            cout<<"                                                                                        <<<<Guide>>>>"<<endl;
            cout<<""<<endl;
            cout<<"                                                                                    Type Y or y for yes"<<endl;
            cout<<"                                                                                    Type N or n for no"<<endl;
            cout<<"                                                                                 Do you really want to add stock?:";
    cin>>as;
    if(as == "Y" || as == "y")
        {
    cout<<""<<endl;
    cout<<"                                                                                    Insert the stock:";
    cin.get();
                        getline(cin, stock_name);
    cout<<"                                                                                    Insert the stock price:";
    cin>>stock_price;
    cout<<"                                                                                    Insert the amount of stock:";
    cin>>stock_amount;
    ss_addstock << "INSERT INTO stock(description,Price,Amount) VALUES ('"<<stock_name<<"',"<<stock_price<<","<<stock_amount<<")";
    string query = ss_addstock.str();
           const char* q = query.c_str();
           qstate = mysql_query(conn, q);
    if(qstate == 0)
           {
               cout<<"                                                                                  Record inserted..."<<endl;
               system("pause");
               vtable_stock(stock_name);
           }
           else
            {
                cout<<"                                                                                  Record failed..."<<endl;
                system("pause");
                add_stock();
           }
    }
    else if(as == "N" || as == "n"){
        Stock();
    }
    else
        {
            cout<<"Wrong input. Please try again"<<endl;
            system("pause");
            add_stock();
        }
}
//=========================================================================================================================================================

void add_amount_stock(string didaas)
{
   int qstate = 0;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL* conn;
   stringstream ss_aastock;
   stringstream ss_descriptionas;
   string aa_stock_value;
   string didaas2 = didaas;
   string aas_input;
   bool aas_loop = false;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    do{
    ss_descriptionas<<"SELECT * FROM stock WHERE description = '"<<didaas<<"'";
    string query = ss_descriptionas.str();
    const char* q = query.c_str();
    if(conn){
    int qstate = mysql_query(conn,q);
        if(!qstate){
            res = mysql_store_result(conn);
            system("CLS");
            cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                          _______     __ __ __               __               __                                    "<<endl;
cout<<"                                         |    ___|.--|  |__|  |_     .-----.|  |_.-----.----.|  |--.    .--------.-----.-----.--.--."<<endl;
cout<<"                                         |    ___||  _  |  |   _|    |__ --||   _|  _  |  __||    <     |        |  -__|     |  |  |"<<endl;
cout<<"                                         |_______||_____|__|____|    |_____||____|_____|____||__|__|    |__|__|__|_____|__|__|_____|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
             cout<<"                                                                  "<<setw(10)<<left<<"ID"<<right<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<endl; //as label for the output table
            while(row = mysql_fetch_row(res))
            {
               cout<<"                                                                  "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(10)<<row[3]<<endl; //print from the database
            }
           cout<<""<<endl;
            cout<<"                                                                                        <<<<Guide>>>>"<<endl;
            cout<<""<<endl;
            cout<<"                                                                                    Type Y or y for yes"<<endl;
            cout<<"                                                                                    Type N or n for no"<<endl;
            cout<<"                                                                        Do you really want to add the amount of stock?:";
            cin>>aas_input;
            if(aas_input == "y" || aas_input == "Y")
            {
            cout<<""<<endl;
            cout<<"                                                                            Insert the amount that you want to add:";
            cin>>aa_stock_value;
           ss_aastock<<"UPDATE stock SET Amount = Amount + "<<aa_stock_value<<" WHERE description = '"<<didaas<<"'"; //update the amount of stock in database
           string query = ss_aastock.str();
           const char* q = query.c_str();
           qstate = mysql_query(conn, q);
           if(qstate == 0)
           {
               cout<<""<<endl;
               cout<<"                                                                                  Record updated..."<<endl;
               system("pause");
               add_amount_stock(didaas2);
           }
           else
            {
                cout<<""<<endl;
                cout<<"                                                                                 Record failed..."<<endl;
                system("pause");
                add_amount_stock(didaas2);
           }
            }
            else if (aas_input == "N" || aas_input == "n")
                {
                vtable_stock(didaas2);
            }
            else
                {
                    cout<<"Wrong input. Please try again"<<endl;
                    system("pause");
                    add_amount_stock(didaas2);
                }
}
}
    }while(!aas_loop);
}
//================================================================================================================================================

void decrease_amount_stock(string diddas)
{
   int qstate = 0;
   MYSQL_RES *res;
   MYSQL_ROW row;
   MYSQL* conn;
   stringstream ss_dastock;
   stringstream ss_descriptionds;
   string da_stock_value;
   string diddas2 = diddas;
   string das_input;
   bool das_loop = false;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    do{
    ss_descriptionds<<"SELECT * FROM stock WHERE description = '"<<diddas<<"'";
    string query = ss_descriptionds.str();
           const char* q = query.c_str();

    if(conn){
    int qstate = mysql_query(conn,q);
        if(!qstate){
            res = mysql_store_result(conn);// connect to table
            system("CLS");
            cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                          _______     __ __ __               __               __                                    "<<endl;
cout<<"                                         |    ___|.--|  |__|  |_     .-----.|  |_.-----.----.|  |--.    .--------.-----.-----.--.--."<<endl;
cout<<"                                         |    ___||  _  |  |   _|    |__ --||   _|  _  |  __||    <     |        |  -__|     |  |  |"<<endl;
cout<<"                                         |_______||_____|__|____|    |_____||____|_____|____||__|__|    |__|__|__|_____|__|__|_____|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
            cout<<"                                                                  "<<setw(10)<<left<<"ID"<<right<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<endl;//as label for the output table
            while(row = mysql_fetch_row(res))
            {
               cout<<"                                                                  "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(10)<<row[3]<<endl;//print from the database
            }
            cout<<""<<endl;
            cout<<"                                                                                        <<<<Guide>>>>"<<endl;
            cout<<""<<endl;
            cout<<"                                                                                    Type Y or y for yes"<<endl;
            cout<<"                                                                                    Type N or n for no"<<endl;
            cout<<"                                                                        Do you really want to decrease the amount of stock?:";
            cin>>das_input;
            if(das_input == "y" || das_input == "Y")
            {
            cout<<""<<endl;
            cout<<"                                                                         Insert the amount that you want to decrease:";
            cin>>da_stock_value;
           ss_dastock<<"UPDATE stock SET Amount = Amount - "<<da_stock_value<<" WHERE description = '"<<diddas<<"'";
           string query = ss_dastock.str();
           const char* q = query.c_str();
           qstate = mysql_query(conn, q);
           if(qstate == 0)
           {
               cout<<""<<endl;
               cout<<"                                                                                  Record updated..."<<endl;
               system("pause");
               decrease_amount_stock(diddas2);
           }
           else
            {
                cout<<""<<endl;
                cout<<"                                                                                 Record failed..."<<endl;
                system("pause");
                decrease_amount_stock(diddas2);
           }
            }
            else if (das_input == "N" || das_input == "n")
                {
                vtable_stock(diddas2);
            }
            else
                {
                    cout<<"Wrong input. Please try again"<<endl;
                    system("pause");
                    decrease_amount_stock(diddas2);

            }
}
}
    }while(!das_loop);
}
//=================================================================================================================================================
void add_employee()
{
    string ae_firstname;
    string ae_lastname;
    string ae_phone;
    string ae_job;
    string ae_username;
    string ae_password;
    int qstate = 0;
    stringstream ss_ae;
    string ae_input;
    string ae_role;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    system("CLS");
    if(conn){
        int qstate = mysql_query(conn,"SELECT * FROM staff");
        if(!qstate){
            res = mysql_store_result(conn);
            system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                     _______     __     __                            __                          "<<endl;
cout<<"                                    |   _   |.--|  |.--|  |    .-----.--------.-----.|  |.-----.--.--.-----.-----."<<endl;
cout<<"                                    |       ||  _  ||  _  |    |  -__|        |  _  ||  ||  _  |  |  |  -__|  -__|"<<endl;
cout<<"                                    |___|___||_____||_____|    |_____|__|__|__|   __||__||_____|___  |_____|_____|"<<endl;
cout<<"                                                                              |__|             |_____|            "<<endl;
cout<<""<<endl;
cout<<""<<endl;
            cout<<"                                              "<<setw(10)<<left<<" Staff ID"<<right<<setw(15)<<" First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone number"<<setw(15)<<"Job"<<endl;//as label for the output table
            cout<<" "<<endl;
            while(row = mysql_fetch_row(res))
            {
               cout<<"                                              "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[3]<<setw(15)<<row[4]<<setw(15)<<row[5]<<setw(15)<<row[6]<<endl;//print from the database

            }
            cout<<""<<endl;
            cout<<"                                                   "<<"Do you want to add more employee?:";
            cin>>ae_input;
            if(ae_input == "y" || ae_input == "Y")
                {
    cout<<"                                                   "<<"Enter the username:";
    cin>>ae_username;
    cout<<"                                                   "<<"Enter the password:";
    cin>>ae_password;
    cout<<"                                                   "<<"Enter the first name of the employee:";
    cin>>ae_firstname;
    cout<<"                                                   "<<"Enter the last name of the employee:";
    cin>>ae_lastname;
    cout<<"                                                   "<<"Enter the phone number of the employee:";
    cin>>ae_phone;
    cout<<"                                                   "<<"Enter the job:";
    cin>>ae_job;
    cout<<"                                                   "<<"Role:";
    cin>>ae_role;
    ss_ae << "INSERT INTO staff(username,staffpassword,FirstName,LastName,phonenumber,job,Role) VALUES ('"<<ae_username<<"','"<<ae_password<<"','"<<ae_firstname<<"','"<<ae_lastname<<"','"<<ae_phone<<"','"<<ae_job<<"','"<<ae_role<<"')"; //insert input into database
    string query = ss_ae.str();
           const char* q = query.c_str();
           qstate = mysql_query(conn, q);
           if(qstate == 0)
            {
               cout<<"                                                  Record updated..."<<endl;
               system("pause");
               add_employee();
           }
           else
            {
                cout<<"                                                  Record failed..."<<endl;
                system("pause");
                add_employee();
           }
        }

        else if(ae_input == "N" || ae_input == "n")
        {
            employee();
        }
        else
            {
                cout<<"                                                                     Wrong input. Please try again"<<endl;
        system("pause");
        add_employee();

            }
        }
}
}
//================================================================================================================================================
void employee()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    char employee_input;
    bool employee_loop = false;
    do
        {
    system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                     _______                  __                                                          "<<endl;
cout<<"                                    |    ___|.--------.-----.|  |.-----.--.--.-----.-----.    .--------.-----.-----.--.--."<<endl;
cout<<"                                    |    ___||        |  _  ||  ||  _  |  |  |  -__|  -__|    |        |  -__|     |  |  |"<<endl;
cout<<"                                    |_______||__|__|__|   __||__||_____|___  |_____|_____|    |__|__|__|_____|__|__|_____|"<<endl;
cout<<"                                                       |__|             |_____|                                           "<<endl;
cout<<""<<endl;
cout<<""<<endl;
    cout<<"                                                                  Update employee menu"<<endl;
    cout<<"                                                                  1. Add employee"<<endl;
    cout<<"                                                                  2. Delete employee"<<endl;
    cout<<"                                                                  3. Exit"<<endl;
    cout<<"                                                                  Choose input for this menu:";
    cin>>employee_input;
    switch(employee_input){
    case '1':
        add_employee();
        break;
    case '2':
        delete_employee();
        break;
    case '3':
        main();
        break;
         default:
             cout<<""<<endl;
        cout<<"                                                                     Wrong input. Please try again"<<endl;
        system("pause");
        employee();
}
        }while(!employee_loop);
}
//================================================================================================================================================
void delete_employee()
{
    string delemployee_id;
    int qstate = 0;
    stringstream ss_deleteemployee;
    MYSQL* conn;
    string re_input;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    if(conn){
        int qstate = mysql_query(conn,"SELECT * FROM staff");
        if(!qstate){
            res = mysql_store_result(conn);
            system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                            ______                                                              __                          "<<endl;
cout<<"                           |   __ \\.-----.--------.-----.--.--.-----.    .-----.--------.-----.|  |.-----.--.--.-----.-----."<<endl;
cout<<"                           |      <|  -__|        |  _  |  |  |  -__|    |  -__|        |  _  ||  ||  _  |  |  |  -__|  -__|"<<endl;
cout<<"                           |___|__||_____|__|__|__|_____|\\___/|_____|    |_____|__|__|__|   __||__||_____|___  |_____|_____|"<<endl;
cout<<"                                                                                       |__|             |_____|            "<<endl;
cout<<""<<endl;
cout<<""<<endl;
            cout<<"                                              "<<setw(10)<<left<<" Staff ID"<<right<<setw(15)<<" First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone number"<<setw(15)<<"Job"<<setw(15)<<"Role"<<endl;//as label for the output table
            cout<<" "<<endl;
            while(row = mysql_fetch_row(res))
            {
               cout<<"                                              "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[3]<<setw(15)<<row[4]<<setw(15)<<row[5]<<setw(15)<<row[6]<<setw(15)<<row[7]<<endl;//print from the database

            }
            cout<<" "<<endl;
            cout<<"                                                   "<<"Do you want to remove an employee?:";
            cin>>re_input;
            if(re_input == "Y" || re_input == "y" ){
        cout<<"                                                      Insert the ID of employee that you want to delete:";
    cin>>delemployee_id;
    ss_deleteemployee<<"DELETE FROM staff WHERE staffid = '"<<delemployee_id<<"'"; //delete staff data where it same like the input
    string query = ss_deleteemployee.str();
           const char* q = query.c_str();
           qstate = mysql_query(conn, q);
    if(qstate == 0)
           {
               cout<<"Record deleted..."<<endl;
               system("pause");
               delete_employee();
           }
           else
            {
                cout << mysql_error(conn) << endl;
                system("pause");
                delete_employee();
           }
        }
        else if(re_input == "N" || re_input == "n")
            {
                employee();
        }
        else{
                cout<<"                                                                      Wrong input. Please try again"<<endl;
        system("pause");
        delete_employee();

        }
    }
}
}
//====================================================================================================================
void vdelete_stock(string did)
{

    int qstate = 0;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    stringstream ss_description;
    stringstream ss_vdeletestock;
    string did2 = did;
    string opt_vdel;
    ss_description<<"SELECT * FROM stock WHERE description = '"<<did<<"'";
    string query = ss_description.str();
    const char* q = query.c_str();
    if(conn){
    int qstate = mysql_query(conn,q);
        if(!qstate){
            res = mysql_store_result(conn);// connect to table
            system("CLS");
            cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                               _____         __         __                     __               __    "<<endl;
cout<<"                                              |     \.-----.|  |.-----.|  |_.-----.    .-----.|  |_.-----.----.|  |--."<<endl;
cout<<"                                              |  --  |  -__||  ||  -__||   _|  -__|    |__ --||   _|  _  |  __||    < "<<endl;
cout<<"                                              |_____/|_____||__||_____||____|_____|    |_____||____|_____|____||__|__|"<<endl;
cout<<""<<endl;
cout<<""<<endl;


            cout<<"                                                                  "<<setw(10)<<left<<"ID"<<right<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<endl; //as label for the output table
            while(row = mysql_fetch_row(res))
            {
               cout<<"                                                                  "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(10)<<row[3]<<endl; //print from the database
            }
           cout<<""<<endl;
            cout<<"                                                                                   <<<<Guide>>>>"<<endl;
            cout<<""<<endl;
            cout<<"                                                                               Type Y or y for yes"<<endl;
            cout<<"                                                                               Type N or n for no"<<endl;
            cout<<"                                                                      Are you sure you want to delete this stock?:";
            cin>>opt_vdel;
            if(opt_vdel == "y"|| opt_vdel== "Y")
            {
                ss_vdeletestock<<"DELETE FROM stock WHERE description = '"<<did<<"'";
                string query = ss_vdeletestock.str();
                const char* q = query.c_str();
           qstate = mysql_query(conn, q);
           if(qstate == 0)
           {
               cout<<                                                                                  "Record deleted..."<<endl;
               system("pause");
               Stock();
           }
           else
            {
                cout << mysql_error(conn) << endl;//print error
                system("pause");
           }
            }
            else if(opt_vdel == "n" || opt_vdel == "N")
            {
                vtable_stock(did);
            }
            else
                {
                    cout<<"                                                                      Wrong input. Please try again"<<endl;
                    system("pause");
                    vdelete_stock(did);
                }
}
}
}
//====================================================================================================================
void view_stock()
{

    int qstate = 0;
    stringstream ss_description;
    string description_id;
    char vstock_input;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    system("CLS");
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
cout<<"                                                                                       __    "<<endl;
cout<<"                                                         .-----.-----.---.-.----.----.|  |--."<<endl;
cout<<"                                                         |__ --|  -__|  _  |   _|  __||     |"<<endl;
cout<<"                                                         |_____|_____|___._|__| |____||__|__|"<<endl;
cout<<""<<endl;
cout<<""<<endl;

    cout<<"                                                             Search for a stock(type q to quit):";
    cin.get();
                        getline(cin, description_id);
                        if(description_id == "q")
                            {
                                Stock();
                            }
                        else
                            {
    ss_description<<"SELECT * FROM stock WHERE description = '"<<description_id<<"'";
    string query = ss_description.str();
    const char* q = query.c_str();
    if(conn){
        int qstate = mysql_query(conn,q);
        if(!qstate)
            {
          vtable_stock(description_id);
    }

  }
}
}
//=======================================================================================================================
  void view_employee()
{
    system("CLS");
    int qstate = 0;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    if(conn){
        int qstate = mysql_query(conn,"SELECT * FROM staff");
        if(!qstate){
            res = mysql_store_result(conn);
            cout<<"                                                                  "<<setw(10)<<left<<" Staff ID"<<right<<setw(15)<<" First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone number"<<setw(15)<<"Job"<<endl; //as label for the output table
            cout<<" "<<endl;
            while(row = mysql_fetch_row(res))
            {
               cout<<"                                                                  "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[3]<<setw(15)<<row[4]<<setw(15)<<row[5]<<setw(15)<<row[6]<<endl; //print from the database
               system("pause");
            }
        }
    }

  }
//==========================================================================================================================

void vtable_stock(string vdid)
{
    int qstate = 0;
    MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.40.1", "admin","admin","stock_transaction",0,NULL,0);//make a connection to the mysql
    stringstream ss_description;
    stringstream ss_vdeletestock;
    char vstock_input;
    ss_description<<"SELECT * FROM stock WHERE description = '"<<vdid<<"'";
    string query = ss_description.str();
    const char* q = query.c_str();
    if(conn){
        int qstate = mysql_query(conn,q);
        if(!qstate){
            res = mysql_store_result(conn);// connect to table
            system("CLS");
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"                                          _______     __ __ __               __               __                                    "<<endl;
cout<<"                                         |    ___|.--|  |__|  |_     .-----.|  |_.-----.----.|  |--.    .--------.-----.-----.--.--."<<endl;
cout<<"                                         |    ___||  _  |  |   _|    |__ --||   _|  _  |  __||    <     |        |  -__|     |  |  |"<<endl;
cout<<"                                         |_______||_____|__|____|    |_____||____|_____|____||__|__|    |__|__|__|_____|__|__|_____|"<<endl;
cout<<""<<endl;
cout<<""<<endl;
            cout<<"                                                                  "<<setw(10)<<left<<"ID"<<right<<setw(15)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<endl; //as label for the output table
            while(row = mysql_fetch_row(res))
            {

               cout<<"                                                                  "<<setw(10)<<left<<row[0]<<right<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(10)<<row[3]<<endl; //print from the database
               //system("pause");
            }
            cout<<""<<endl;
cout<<""<<endl;
            cout<<"                                                                   a. Delete stock"<<endl;
            cout<<"                                                                   b. Add amount of stock"<<endl;
            cout<<"                                                                   c. Decrease amount of stock"<<endl;
            cout<<"                                                                   d. Exit"<<endl;
            cout<<"                                                                   Choose option for this data:";
            cin>>vstock_input;
            switch(vstock_input){
        case 'a':
        vdelete_stock(vdid);
        break;
        case 'b':
        add_amount_stock(vdid);
        break;
         case 'c':
        decrease_amount_stock(vdid);
        break;
         case 'd':
        Stock();
        break;
         default:
        cout<<"                                                                        Wrong input. Please try again"<<endl;
        system("pause");
        vtable_stock(vdid);
        }
    }

  }
}
