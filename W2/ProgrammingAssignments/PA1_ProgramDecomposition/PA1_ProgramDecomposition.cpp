// PA1_ProgramDecomposition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    q.stops.clear();
    q.bus.clear();
    q.stop.clear();

    string operation_code;
    is >> operation_code;
    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        for (int i = 0; i < stop_count; ++i) {
            string stop;
            is >> stop;
            q.stops.push_back(stop);
        }
    }
    else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    string stop;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.stops_to_buses.count(r.stop) == 0) {
        os << "No stop" << endl;
    }
    else {
        for (const string& bus : r.stops_to_buses.at(r.stop)) {
            os << bus << " ";
        }
        os << endl;
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    map<string, vector<string>> stops_to_buses;
    map<string, vector<string>> buses_to_stops;

};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.buses_to_stops.count(r.bus) == 0) {
        os << "No bus" << endl;
    }
    else {
        for (const auto& stop : r.buses_to_stops.at(r.bus)) {
            os << "Stop " << stop << ": ";
            if (r.stops_to_buses.at(stop).size() == 1) {
                os << "no interchange";
            }
            else {
                for (const string& bus : r.stops_to_buses.at(stop)) {
                    if (bus != r.bus) {
                        os << bus << " ";
                    }
                }
            }
            os << endl;
        }
    }
    return os;
}

struct AllBusesResponse {
    map < string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.buses_to_stops.empty()) {
        os << "No buses" << endl;
    }
    else
    {
        for (const auto& [bus, stops] : r.buses_to_stops) {
            os << "Bus " << bus << ": ";
            for (const string& stop : stops) {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for (const string& stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse result{ stop, stops_to_buses};
        return result;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse result{ bus, stops_to_buses, buses_to_stops };
        return result;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse result{ buses_to_stops };
        return result;
    }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

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
