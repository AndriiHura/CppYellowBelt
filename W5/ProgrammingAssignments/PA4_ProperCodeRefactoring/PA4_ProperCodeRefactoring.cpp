#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:

    Person(const string& name, const string& status)
        : name_(name), status_(status){}

    virtual void Walk(const string& destination) const {
        cout << status_<< ": " << name_ << " walks to: " << destination << endl;
    }

    string Name() const {
        return name_;
    }
    string Status() const {
        return status_;
    }

private:
    const string name_;
    const string status_;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong)
        : Person(name, "Student"), FavouriteSong(favouriteSong){}

    void Learn() {
        cout << "Student: " << Name() << " learns" << endl;
    }

    virtual void Walk(const string& destination) const override {
        cout << "Student: " << Name() << " walks to: " << destination << endl;
        cout << "Student: " << Name() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << Name() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject)
    : Person(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << "Teacher: " << Name() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name)
        : Person(name, "Policeman") {}

    void Check(const Person& p) {
        cout << "Policeman: " << Name()  << " checks "<<p.Status()<<
            ". "<<p.Status()<<"'s name is: " << p.Name() << endl;
    }
};


void VisitPlaces(Person& p, vector<string> places) {
    for (auto pl : places) {
        p.Walk(pl);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}