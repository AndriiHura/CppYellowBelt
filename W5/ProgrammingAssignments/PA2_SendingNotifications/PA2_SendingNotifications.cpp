// PA2_SendingNotifications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
    cout << "Send '" << message << "' to e-mail " << email << endl;
}


class INotifier {
public:
    virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier {
public:

    SmsNotifier(const string& number)
        : number_(number) {}

    void Notify(const string& message) override {
        SendSms(number_, message);
    }

private:
    const string number_;
};

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const string& email) : email_(email){}

    void Notify(const string& message) override {
        SendEmail(email_, message);
    }

private:
    const string email_;
};

void Notify(INotifier& notifier, const string& message) {
    notifier.Notify(message);
}


int main() {
    SmsNotifier sms{ "+7-495-777-77-77" };
    EmailNotifier email{ "na-derevnyu@dedushke.ru" };

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
