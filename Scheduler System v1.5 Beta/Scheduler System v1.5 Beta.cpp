
/*	

	SCHEDULER SYSTEM Version 1.5 - DESIGNED AND PROGRAMMED BY: JOJIE BAGATUA
	
	!! ABOUT SCHEDULER SYSTEM - The purpose of this system is to simplify our lives by
								organizing our school schedules more effectively, as
								the current portal schedule is disorganized and chaotic.
								
							 - 	This system is designed to be user-friendly and includes 
								features such as clear labels for subjects, precise times 
								for each class, room assignments, and the day of the week.
								Making it easy to navigate and manage our daily schedules.
								
*/		


#include <iostream>
#include <vector>
#include <string>
#include <fstream>  // For file operations

using namespace std;

void credits() {
    cout << "\n\t\t-----------------------------------------------------------------------------------------" << endl;
    cout << "\t\t|   SCHEDULER SYSTEM   |   Designed and Programmed by: Jojie   |   Version 1.5   	|" << endl;
    cout << "\t\t-----------------------------------------------------------------------------------------\n\n" << endl;
    system("Color A");
}

void UI() {
    cout << "\n\t\t----------------------------------------------------------------------------------" << endl;
    cout << "\t\t|   SCHEDULER SYSTEM   |   Designed and Programmed by: Jojie   |   Version 1.5   |" << endl;
    cout << "\t\t----------------------------------------------------------------------------------\n\n" << endl;

    cout << "\t * HERE ARE THE STEPS ON HOW TO USE SCHEDULER SYSTEM: *\n" << endl;
    cout << "\t 1. Enter the name of the day." << endl;
    cout << "\t 2. Enter the subject name." << endl;
    cout << "\t 3. Enter the time IN of the subject." << endl;
    cout << "\t 4. Enter the time OUT of the subject." << endl;
    cout << "\t 5. After entering details for one subject, the program will prompt you again for the next subject." << endl;
    cout << "\t 6. If you're done entering details, finish entering details for that day by typing \"D/d\" as done." << endl;
    cout << "\t 7. All the details you input in SCHEDULER SYSTEM will automatically arrange and display it as TABLE!." << endl;
}

struct ScheduleEntry {
    string subject;
    string timeIn;
    string timeOut;
    string room;

    ScheduleEntry() {}

    ScheduleEntry(const string& s, const string& in, const string& out, const string& r)
        : subject(s), timeIn(in), timeOut(out), room(r) {}
};

void printSchedule(const vector<pair<string, vector<ScheduleEntry> > >& schedule) {
    for (size_t i = 0; i < schedule.size(); ++i) {
        const string& day = schedule[i].first;
        const vector<ScheduleEntry>& entries = schedule[i].second;

        cout << "\n\n\t\t\tSchedule for " << day << ":" << endl;
        cout << "\t\t\t------------------------------------------------------" << endl;
        cout << "\t\t\t| Subject             | Time In | Time Out | Room    |" << endl;
        cout << "\t\t\t------------------------------------------------------" << endl;

        for (size_t j = 0; j < entries.size(); ++j) {
            const ScheduleEntry& entry = entries[j];
            cout << "\t\t\t| " << entry.subject;
            cout << string(20 - entry.subject.length(), ' ');
            cout << "| " << entry.timeIn;
            cout << string(7 - entry.timeIn.length(), ' ');
            cout << " | " << entry.timeOut;
            cout << string(8 - entry.timeOut.length(), ' ');
            cout << " | " << entry.room;
            cout << string(7 - entry.room.length(), ' ');
            cout << " |" << endl;
        }

        cout << "\t\t\t------------------------------------------------------" << endl;
    }

    // Ask if the user wants to generate a file
    char generateFile;
    cout << "\nDo you want to generate a text file of this schedule? (y/n): ";
    cin >> generateFile;
    cin.ignore(); // Clear newline left in the input buffer

    if (generateFile == 'y' || generateFile == 'Y') {
        ofstream outFile("schedule.txt");

        if (outFile.is_open()) {
        	
        		outFile << "\n\t\t\t\t\t-----------------------------------------------------------------------------------------" << endl;
				outFile << "\t\t\t\t\t|   SCHEDULER SYSTEM   |   Designed and Programmed by: Jojie   |   Version 1.5   	|" << endl;
				outFile << "\t\t\t\t\t-----------------------------------------------------------------------------------------\n\n" << endl;
        	
            for (size_t i = 0; i < schedule.size(); ++i) {
                const string& day = schedule[i].first;
                const vector<ScheduleEntry>& entries = schedule[i].second;

				

                outFile << "\n\n\t\t\t\t\t\t\tSchedule for " << day << ":" << endl;
				outFile << "\t\t\t\t\t\t\t------------------------------------------------------" << endl;
				outFile << "\t\t\t\t\t\t\t| Subject             | Time In | Time Out | Room    |" << endl;
				outFile << "\t\t\t\t\t\t\t------------------------------------------------------" << endl;	

                for (size_t j = 0; j < entries.size(); ++j) {
                    const ScheduleEntry& entry = entries[j];
                    outFile << "\t\t\t\t\t\t\t| " << entry.subject;
    				outFile << string(20 - entry.subject.length(), ' ');
    				outFile << "| " << entry.timeIn;
    				outFile << string(7 - entry.timeIn.length(), ' ');
    				outFile << " | " << entry.timeOut;
    				outFile << string(8 - entry.timeOut.length(), ' ');
    				outFile << " | " << entry.room;
    				outFile << string(7 - entry.room.length(), ' ');
    				outFile << " |" << endl;
                }

                outFile << "\t\t\t\t\t\t\t------------------------------------------------------\n";
            }

            outFile.close();
            cout << "\n\t\t Generated file SUCCESSFULLY!\n" << endl;
            cout << "The schedule has been converted into txt file and the name is 'schedule.txt'.\n\n\n\n" << endl;
            system("pause");
        } else {
            cerr << "Unable to open file for writing." << endl;
        }
    }
}

int main() {
    vector<pair<string, vector<ScheduleEntry> > > schedule;
    string day, subject, timeIn, timeOut, room;

    while (true) {
        UI();
        cout << "\n\nEnter the day name: ";
        getline(cin, day);

        if (day == "D" || day == "d") {
            system("CLS");
            credits();
            break;
        }

        vector<ScheduleEntry> dailyEntries;
        while (true) {
            cout << "\n\tEntering schedule for " << day << ".\n" << endl;
            cout << "Enter subject name: ";
            getline(cin, subject);

            if (subject == "D" || subject == "d") {
                system("CLS");
                break;
            }

            cout << "Enter time In (HH:MM): ";
            getline(cin, timeIn);

            cout << "Enter time Out (HH:MM): ";
            getline(cin, timeOut);

            cout << "Enter room name: ";
            getline(cin, room);

            dailyEntries.push_back(ScheduleEntry(subject, timeIn, timeOut, room));
        }

        schedule.push_back(make_pair(day, dailyEntries));
    }

    printSchedule(schedule);

    return 0;
}

