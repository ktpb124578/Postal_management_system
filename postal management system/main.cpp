#include "Head.cpp"
#include "PostalWorkers.cpp"
#include "Clerk.cpp"
#include "Officer.cpp"
#include "Postman.cpp"
#include "Customers.cpp"
#include "Order.cpp"


using namespace std;

void console();
void options1();
void prices();
void controller();

int main()
{
    controller();
}

void console()
{
    cout << "\n\t\t  **************************************** \n";
    cout << "\n\t\t  WELCOME TO PAKISTAN-POST COURIER SERVICE \n";
    cout << "\n\t\t  **************************************** \n";
}

void options1()
{
    cout << "\n";
    cout << "\t   1. Prices";
    cout << "\t   2. Sign Up";
    cout << "\t   3. Sign In";
    cout << "\t   4. Exit";
}

void prices()
{
    cout << "\n PRICE TABLE OF REGULAR MAIL SERVICE";
    cout << "\n";
    cout << "\n             Weight upto         Weight upto         Additional";
    cout << "\n              250 grams           500 grams           500 grams";
    cout << "\n";
    cout << "\n Local         Rs. 25              Rs. 40              Rs. 10";
    cout << "\n";
    cout << "\n Inter-City    Rs. 60              Rs. 100             Rs. 20";

    cout << "\n PRICE TABLE OF URGENT MAIL SERVICE";
    cout << "\n";
    cout << "\n             Weight upto         Weight upto         Additional";
    cout << "\n              250 grams           500 grams           500 grams";
    cout << "\n";
    cout << "\n Local         Rs. 50              Rs. 65              Rs. 25";
    cout << "\n";
    cout << "\n Inter-City    Rs. 85              Rs. 130             Rs. 45";

    cout << "\n\n";

    cout << "\n PRICE TABLE OF PARCEL DELIVERY SERVICE";
    cout << "\n";
    cout << "\n     Category        Rate";
    cout << "\n";
    cout << "\n     Upto 1 Kg       Rs. 100";
    cout << "\n     Upto 3 Kg       Rs. 175";
    cout << "\n     Upto 5 Kg       Rs. 250";
    cout << "\n     Upto 10 Kg      Rs. 375";
    cout << "\n     Upto 15 Kg      Rs. 500";
    cout << "\n     Upto 20 Kg      Rs. 625";
    cout << "\n     Upto 25 Kg      Rs. 750";
    cout << "\n     Upto 30 Kg      Rs. 875";

    cout << "\n\n";

    cout << "\n Back to Home";
}

void controller()
{
    Head H;
    PostalWorkers *P;
    Clerk CL;
    AccountOfficer AO;
    Postman PM;
    Customers C;
    Order OR;

    fstream file;

    int to, s1, s2, s3, s4, s5;
    char opt;
    bool flag;
    string cn, na, nu, pa;

    while(1)
    {
        console();
        options1();

        opt = getch();

        system("CLS");

        switch(opt)
        {
            case '1':
                console();
                prices();

                opt = getch();

                system("CLS");
            break;

            case '2':
                console();
                options1();

                cout << "\n";
                cout << "\n\t\t\t\t  ^";
                cout << "\n\t\t\t\t  |";
                cout << "\n\t\t\t\t  |";
                cout << "\n\t\t\t\t  |--- 1. As Postal Worker";
                cout << "\n\t\t\t\t  |";
                cout << "\n\t\t\t\t  |--- 2. As Customer";

                opt = getch();

                system("CLS");

                switch (opt)
                {
                    case '1':
                        console();
                        options1();

                        cout << "\n";
                        cout << "\n\t\t\t\t  ^";
                        cout << "\n\t\t\t\t  |       --- 1. Account Officer";
                        cout << "\n\t\t\t\t  |                               /";
                        cout << "\n\t\t\t\t  |--- 1. As Postal Worker   ----- --- 2. Clerk";
                        cout << "\n\t\t\t\t  |                               \\";
                        cout << "\n\t\t\t\t  |--- 2. As Customer              --- 3. Postman";

                        opt = getch();

                        system("CLS");

                        switch(opt)
                        {
                            case '1':
                                P = &AO;
                                P->SignUp();

                                opt = getch();

                                system("CLS");
                            break;

                            case '2':
                                P = &CL;
                                P->SignUp();

                                opt = getch();

                                system("CLS");
                            break;

                            case '3':
                                P = &PM;
                                P->SignUp();

                                opt = getch();

                                system("CLS");
                            break;

                            default:
                                
                            break;
                        }
                    break;

                    case '2':
                        C.SignUp();

                        opt = getch();

                        system("CLS");
                    break;
                    
                    default:
                        
                    break;
                }
            break;

            case '3':
                console();
                options1();

                cout << "\n";
                cout << "\n\t\t\t\t\t\t  ^";
                cout << "\n\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t\t  |--- 1. As Head";
                cout << "\n\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t\t  |--- 2. As Postal Workers";
                cout << "\n\t\t\t\t\t\t  |";
                cout << "\n\t\t\t\t\t\t  |--- 3. As Customers";

                opt = getch();

                system("CLS");

                switch (opt)
                {
                    case '1':
                        H.SignIn();

                        opt = getch();

                        system("CLS");

                        do
                        {
                            flag = true;
                            console();

                            cout << "\n";
                            cout << "\n   1. Daily Report";
                            cout << "\n   2. Search Postal Workers";
                            cout << "\n   3. Add Employees";
                            cout << "\n   4. Sign Out";

                            opt = getch();

                            system("CLS");

                            switch(opt)
                            {
                                case '1':
                                    cout << "\n\t ***************** \n";
                                    cout << "\n\t YOUR DAILY REPORT \n";
                                    cout << "\n\t ***************** \n";

                                    file.open("Payment.txt");

                                    file >> to >> s1 >> s2 >> s3 >> s4 >> s5;

                                    file.close();

                                    cout << "\n\n Total Earnings : " << to;
                                    cout << "\n";
                                    cout << "\n Stamps sold of each category";
                                    cout << "\n";
                                    cout << "\n  Rs.100   Rs.50   Rs.20   Rs.10   Rs.5";
                                    cout << "\n";
                                    cout << "\n   " << s1 << "       " << s2 << "       " << s3 << "       " << s4 << "       " << s5;

                                    cout << "\n\n Back to Main";

                                    opt = getch();

                                    system("CLS");
                                break;

                                case '2':
                                    console();
                                    
                                    cout << "\n";
                                    cout << "\n   1. Daily Report";
                                    cout << "\n   2. Search Postal Workers";
                                    cout << "\n\t 1. Account Officer";
                                    cout << "\n\t 2. Clerk";
                                    cout << "\n\t 3. Postman";
                                    cout << "\n";
                                    cout << "\n   3. Add Employees";
                                    cout << "\n   4. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            cout << "\n Following is all the information of Account Officers";

                                            file.open("AccountOfficer.txt");
                                            
                                            while(!file.eof())
                                            {
                                                file >> cn >> na >> nu >> pa;

                                                cout << "\n\n";
                                                cout << "\n CNIC : " << cn;
                                                cout << "\n Name : " << na;
                                                cout << "\n Number : " << nu;
                                            }

                                            file.close();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            cout << "\n Following is all the information of Clerks";

                                            file.open("Clerk.txt");
                                            
                                            while(!file.eof())
                                            {
                                                file >> cn >> na >> nu >> pa;

                                                cout << "\n\n";
                                                cout << "\n CNIC : " << cn;
                                                cout << "\n Name : " << na;
                                                cout << "\n Number : " << nu;
                                            }

                                            file.close();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '3':
                                            cout << "\n Following is all the information of Postmans";

                                            file.open("Postman.txt");
                                            
                                            while(!file.eof())
                                            {
                                                file >> cn >> na >> nu >> pa;

                                                cout << "\n\n";
                                                cout << "\n CNIC : " << cn;
                                                cout << "\n Name : " << na;
                                                cout << "\n Number : " << nu;
                                            }

                                            file.close();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        default:

                                        break;
                                    }
                                break;

                                case '3':
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Daily Report";
                                    cout << "\n   2. Search Postal Workers";
                                    cout << "\n   3. Add Employees";
                                    cout << "\n\t 1. Account Officer";
                                    cout << "\n\t 2. Clerk";
                                    cout << "\n\t 3. Postman";
                                    cout << "\n";
                                    cout << "\n   4. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            P = &AO;
                                            P->SignUp();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            P = &CL;
                                            P->SignUp();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '3':
                                            P = &PM;
                                            P->SignUp();

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        default:
                                            
                                        break;
                                    }
                                break;

                                case '4':
                                    cout << "\n\n Head has been signed out successfully!!";
                                    cout << "\n\n Back to Home";

                                    opt = getch();

                                    system("CLS");

                                    flag = false;
                                break;

                                default:

                                break;
                            }
                        }
                        while(flag == true);
                    break;

                    case '2':
                        console();
                        options1();

                        cout << "\n";
                        cout << "\n\t\t\t\t\t\t  ^";
                        cout << "\n\t\t\t\t\t\t  |";
                        cout << "\n\t\t\t\t\t\t  |--- 1. As Head                  --- 1. Account Officer";
                        cout << "\n\t\t\t\t\t\t  |                               /";
                        cout << "\n\t\t\t\t\t\t  |--- 2. As Postal Worker   ----- --- 2. Clerk";
                        cout << "\n\t\t\t\t\t\t  |                               \\";
                        cout << "\n\t\t\t\t\t\t  |--- 3. As Customer              --- 3. Postman";

                        opt = getch();

                        system("CLS");

                        switch (opt)
                        {
                            case '1':
                                AO.SignIn();

                                opt = getch();

                                system("CLS");

                                do
                                {
                                    flag = true;
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Manage Accounts";
                                    cout << "\n   2. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            cout << "\n\n All accounts have been managed successfully!!";
                                            cout << "\n\n Back to Main";
                                            
                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            cout << "\n\n Account officer has been signed out successfully!!";
                                            cout << "\n\n Back to Home";

                                            opt = getch();

                                            system("CLS");

                                            flag = false;
                                        break;

                                        default:

                                        break;
                                    }
                                }
                                while(flag == true);
                            break;
                            
                            case '2':
                                CL.SignIn();

                                opt = getch();

                                system("CLS");

                                do
                                {
                                    flag = true;
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Stamp Orders";
                                    cout << "\n   2. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            cout << "\n\n All orders have been stamped successfully!!";
                                            cout << "\n\n Back to Main";
                                            
                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            cout << "\n\n Clerk has been signed out successfully!!";
                                            cout << "\n\n Back to Home";

                                            opt = getch();

                                            system("CLS");

                                            flag = false;
                                        break;

                                        default:

                                        break;
                                    }
                                }
                                while(flag == true);
                            break;

                            case '3':
                                PM.SignIn();

                                opt = getch();

                                system("CLS");

                                do
                                {
                                    flag = true;
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Distribute Orders";
                                    cout << "\n   2. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            cout << "\n\n All orders have been distributed successfully!!";
                                            cout << "\n\n Back to Main";
                                            
                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':
                                            cout << "\n\n Postman has been signed out successfully!!";
                                            cout << "\n\n Back to Home";

                                            opt = getch();

                                            system("CLS");

                                            flag = false;
                                        break;

                                        default:

                                        break;
                                    }
                                }
                                while(flag == true);
                            break;
                            
                            default:
                                
                            break;
                        }
                    break;

                    case '3':
                        C.SignIn();

                        opt = getch();

                        system("CLS");

                        do
                        {
                            flag = true;
                            console();

                            cout << "\n";
                            cout << "\n   1. Place Order";
                            cout << "\n   2. Trace Order";
                            cout << "\n   3. Sign Out";

                            opt = getch();

                            system("CLS");

                            switch(opt)
                            {
                                case '1':
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Place Order";
                                    cout << "\n\t 1. Order of Parcel";
                                    cout << "\n\t 2. Order of Mail";
                                    cout << "\n";
                                    cout << "\n   2. Trace Order";
                                    cout << "\n   3. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            OR.setParcelDetails(C.getCnic());

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':

                                        break;

                                        default:

                                        break;
                                    }
                                break;

                                case '2':
                                    console();

                                    cout << "\n";
                                    cout << "\n   1. Place Order";
                                    cout << "\n   2. Trace Order";
                                    cout << "\n\t 1. Tracing Parcel";
                                    cout << "\n\t 2. Tracing Mail";
                                    cout << "\n";
                                    cout << "\n   3. Sign Out";

                                    opt = getch();

                                    system("CLS");

                                    switch(opt)
                                    {
                                        case '1':
                                            OR.traceParcelDetails(C.getCnic());

                                            opt = getch();

                                            system("CLS");
                                        break;

                                        case '2':

                                        break;

                                        default:

                                        break;
                                    }
                                break;

                                case '3':
                                    cout << "\n\n Customer has been signed out successfully!!";
                                    cout << "\n\n Back to Home";

                                    opt = getch();

                                    system("CLS");

                                    flag = false;
                                break;

                                default:

                                break;
                            }
                        }
                        while(flag == true);
                        
                    break;
                    
                    default:
                        
                    break;
                }
            break;

            case '5':
                exit(0);
            break;
            
            default:
                exit(0);
            break;
        }
    }
    
}