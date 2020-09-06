#include "database.h"

void Database::Add(const Date& date, const string& event) {
    if (unique_storage.count(date) == 0 || unique_storage.at(date).count(event) == 0) {
        unique_storage[date].insert(event);
        storage[date].push_back(event);
    }
}

void Database::RemoveEmpty() {
    vector<Date> emptyDates;

    for (const auto& [date, events] : unique_storage) {
        if (events.empty()) {
            emptyDates.push_back(date);
        }
    }

    for (const auto& date : emptyDates) {
        storage.erase(date);
        unique_storage.erase(date);
    }
}


void Database::Print(ostream& os) const {
    for (const auto& item : storage) {
        for (const string& event : item.second) {
            os << item.first << " " << event << endl;
        }
    }
}


int Database::RemoveIf(Pred predicate) {
    int numOfRemoved = 0;
    for (auto& [date, events] : storage) {
        auto borderIt = stable_partition(events.begin(), events.end(),
            [&, date=date](const string& event) {
                return !predicate(date, event);
            });

        numOfRemoved += distance(borderIt, events.end()) ;
        events.erase(borderIt, events.end());
        unique_storage[date].clear();

        if (!events.empty()) {
            unique_storage[date].insert(events.begin(), events.end());
        }
    }
    RemoveEmpty();
    return numOfRemoved;
}

string Database::Last(const Date& date) const {
    if (date < begin(unique_storage)->first || storage.empty()) {
        throw std::invalid_argument("");
    }

    auto it = storage.upper_bound(date);
    --it;

    ostringstream os;
    os << it->first << ' ' << storage.at(it->first).back();
    return os.str();
}

vector<pair<Date, string>> Database::FindIf(Pred predicate) const {
    vector<pair<Date, string>> result;

    for (const auto& [date, events] : storage) {
        for (const auto& event : events) {
            if (predicate(date, event)) {
                result.emplace_back(date, event);
            }
        }
    }
    return result;
}

ostream& operator<<(ostream& os, pair<Date, string> entry) {
    os << entry.first << ' ' << entry.second;
    return os;
}