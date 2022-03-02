#include <iostream>
#include<cstring>
using namespace std;

//classes declaration
class Products;
class	User;
class Customer;
class Services;
class Report;
class Beautician;
class Payment;
class Booking;
class Feedback;
class Shopping_cart;

//base class(use inheritance)
class User {
    protected:
        string name;
        string  phoneNo;
        string email;
        int age;
        string address;

    public:
        User();//default constructor
        User(string pname, string pphoneNo, string pemail, int page, string paddress);//overloaded constructor
        void userregister();
        ~User() {}//destructor called
};

User::User() {}

User::User(string pname, string pphoneNo, string pemail, int page, string paddress) {
        name = pname;
        phoneNo = pphoneNo;
        email = pemail;
        age = page;
        address = paddress;
}
void User::userregister() {}


class Report {
    private:
        int reportID;
        string reportName;
        Payment* payreport;

    public:
        Report() {}//default constructor
        Report(int RID, string rreportName) {
            reportID = RID;
            rreportName = reportName;
        }//overloaded constructor

        void generatepaymentReport(Payment* prep);
        ~Report() {}//destructor called

};

class Feedback {
    private:
        int feedbackID;

    public:
        Feedback();//default constructor
        Feedback(int pfeedbackID);//overloaded constructor
        void viewfeedback() {
            cout << "======================||Feedback||=======================" << endl << endl;
            cout << "Excelent Service" << endl << endl;;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        }
        void checkreply();
        ~Feedback() {}//destructor called

};

Feedback::Feedback(int pfeedbackID) {
    feedbackID = pfeedbackID;

}


class Services {
    protected:
        string serviceID;
        string serviceName;

    public:
        Services();//default constructor
        Services(string pserviceID, string serviceName);//overloaded constructor
        void viewService() {
            cout << "======================||Service||=======================" << endl << endl;
            cout << "Service ID: " << serviceID << endl;
            cout << "Service Name: " << serviceName << endl;
        }
        void confirmService();
        ~Services() {}//destructor called

};

Services::Services() {}

Services::Services(string pserviceID, string pserviceName) {

        serviceID = pserviceID;

}


class Customer :public User {
    private:
        Booking* booking;
        Feedback* feedback[1];//composition relationship
        Services* cusservice[2];
        string CustomerId;  

    public:
        Customer();//default constructor
        Customer(string pname, string pphoneNo, string pemail, int page, string paddress, string pCustomerId, int serno, int feedno);//overloaded constructor
        void selectservice(Services* s1, Services* s2) {
            cusservice[0] = s1;
            cusservice[1] = s2;
        }
        void addbooking(Booking* cusb);
        void addfedback() {
            feedback[1]->viewfeedback();
        }
        void purchaseitems();
        void manageprofile();
        ~Customer() {}//destructor called
};

Customer::Customer() {}

Customer::Customer(string pname, string pphoneNo, string pemail, int page, string paddress, string pCustomerId, int serno1, int feedno) :User(pname, pphoneNo, pemail, page, paddress) {

        feedback[0] = new Feedback(feedno);
        CustomerId = pCustomerId;
 }


class Beautician : public User {
    private:
        string beauticianID;
        Booking* bbooking[2];

    public:
        Beautician();//default constructor
        Beautician(string pname, string pphoneNo, string pemail, int page, string paddress, string pbeauticianID);//overloaded constructor
        void acceptbooking(Booking* beau);
        void updateAvailability();
        void displayBeautician() {
            cout << endl << "===================||Beautician Details||===============" << endl << endl;;
            cout << "Beautician Name: " << name << endl;
            cout << "Beautician ID: " << beauticianID << endl;
            cout << "Email: " << email << endl;
        }
        ~Beautician() {}//destructor called

};

Beautician::Beautician() {}

Beautician::Beautician(string pname, string pphoneNo, string pemail, int page, string paddress, string pbeauticianID) :User(pname, pphoneNo, pemail, page, paddress)
{
    beauticianID = pbeauticianID;
}


class Booking {
    private:
        Customer* cus;
        Beautician* beautician;
        string bookingID;
        string branchName;
        string date;

    public:
        Booking();//default constructor
        Booking(string pbookingID, string pbranchName, string pdate, Customer* pcustomer, Beautician* pbeautician);//overloaded constructor
        void assignBeautician(Beautician* B);

        void displayBooking() {
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl << "======================||Booking||=======================" << endl << endl;
            cout << "Booking ID: " << bookingID << endl;
            cout << "Branch Name: " << branchName << endl;
            cout << "Appointment Date: " << date << endl << endl;
        }
        ~Booking() {}//destructor called

};

class Customer;
Booking::Booking() {}

Booking::Booking(string pbookingID, string pbranchName, string pdate, Customer* pcustomer, Beautician* pbeautician) {

        bookingID = pbookingID;
        branchName = pbranchName;
        date = pdate;
        cus = pcustomer;
        beautician = pbeautician;
}

class Shopping_cart;

class Products {
    private:
        string productID;
        string productName;
        float price;

    public:
        Products() {}//default constructor
        Products(string pproductID, string pproductName, float pprice);//overloaded constructor
        void displayproduct();
        ~Products() {}//destructor called

};

Products::Products(string pproductID, string pproductName, float pprice)
{
        productID = pproductID;
        productName = pproductName;
        price = pprice;
}


class Shopping_cart :public Products {
    private:
        Payment* paycart;
        int noOfitems;

    public:
        Shopping_cart();//default constructor
        Shopping_cart(string PProductId, string PProductname, float Price, int pnoOfitems);//overloaded constructor
        void managecart();
        void addpayment(Payment* p);
        ~Shopping_cart() {}

};

Shopping_cart::Shopping_cart(string pproductID, string pproductName, float pprice, int pnoOfitems) :Products(pproductID, pproductName, pprice) {

        noOfitems = pnoOfitems;
}


class Payment {
    private:
        Shopping_cart* pcart;
        Report* payreport;
        string  Payment_Id;
        double Payment_amount;
    public:
        Payment();//default constructor
        Payment(string pPayment_Id, float pPayment_amount, Shopping_cart* cart, Report* p);//overloaded constructor
        void displaypayment() {
            cout << endl << "======================||Payment||=======================" << endl << endl;
            cout << "Payment ID: " << Payment_Id << endl;
            cout << "Payable Amount: " << Payment_amount << endl << endl;
        }
        ~Payment() {}//destructor called

};

Payment::Payment(string pPayment_Id, float pPayment_amount, Shopping_cart* cart, Report* p) {

        Payment_Id = pPayment_Id;
        Payment_amount = pPayment_amount;
        pcart = cart;
        payreport = p;

}


int main() {

        Customer* C1 = new Customer("Nipuni Sooriarachchi", "0768959018", "nipuni.s@gmail.com", 30, "89/1,Bataduwa,Galle", "CUS01", 01, 23);
        Beautician* BT = new Beautician("Sandali Fernando", "0773456738", "sandali.salonj@gmail.com", 33, "45/2,Arangala,Malabe", "BEAU01");
        Booking* B1 = new Booking("BK01", "Nugegoda", "2021/06/04", C1, BT);
        Shopping_cart* SC = new Shopping_cart("PRO01", "Oriflame", 3700, 1);
        Report* Re = new Report(1001, "DAY01");
        Payment* P = new Payment("PAY01", 1000, SC, Re);
        Products* Pr = new Products("PRO02", "Oriflame", 1000);
        Services* Ser = new Services("SER01", "Hair Cutting");
        Feedback* feed = new Feedback(01);
        User* user = new User("Senalii Mendis", "0786387632", "senali.m@gmail.com", 44, "123/3,Mavittara,Kottawa");

        B1->displayBooking();//Booking::displayBooking() called
        Ser->viewService();//Services::viewService() called
        BT->displayBeautician();//Beautician::displayBeautician() called
        P->displaypayment();//Payment::displaypayment() called
        feed->viewfeedback();//Feedback::viewfeedback() called

        //deallocate memory(release memory)
        delete C1;
        delete P;
        delete Ser;
        delete BT;
        delete B1;
        delete feed;
        delete Re;
        delete SC;
        delete Pr;
        delete user;

    return 0;

}
